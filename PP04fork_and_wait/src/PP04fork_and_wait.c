/*
 ============================================================================
 Name        : PP04fork_and_wait.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void) {
	int wstatus;
	int result_from_child = -1;

	pid_t child_pid;
	child_pid = fork();

	switch (child_pid) {
		case 0:
			printf("[child] sono il processo figlio\n");
			pid_t process_id;
			process_id = getpid();
			printf("[child] il mio pid è: %d\n", process_id);
			int valore_di_ritorno = 10;
			printf("[child] sto per andare a dormire per 10 secondi: \n");
			sleep(10);
			printf("[child] mando come valore di rotorno: %d\n",valore_di_ritorno);
			exit(valore_di_ritorno);
			break;
		case -1:
			printf("fork() ha fallito! niente processo figlio!\n");
			exit(1);
			break;
		default:
			// valore > 0, ovvero il pid del processo figlio
			printf("[parent] sono il processo padre\n");
			pid_t process_id2;
			process_id2 = getpid();
			printf("[parent] il mio pid è: %d\n", process_id2);
			printf("[parent] so che mio figlio è: %d\n", child_pid);

			do {
				pid_t ws = waitpid(child_pid, &wstatus, WUNTRACED | WCONTINUED);
				if (ws == -1) {
					perror("[parent] waitpid");
					exit(EXIT_FAILURE);
				}
				if (WIFEXITED(wstatus)) {
					result_from_child = WEXITSTATUS(wstatus);
					//printf("[parent] child process è terminato, ha restituito: %d\n", result_from_child);
				} else if (WIFSIGNALED(wstatus)) {
					printf("[parent] child process killed by signal %d\n", WTERMSIG(wstatus));
				} else if (WIFSTOPPED(wstatus)) {
					printf("[parent] child process stopped by signal %d\n", WSTOPSIG(wstatus));
				} else if (WIFCONTINUED(wstatus)) {
					printf("[parent] child process continued\n");
				}
			} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));

			if (result_from_child != -1) {
				printf("[parent] il valore restituito dal processo figlio è %d\n", result_from_child);
			}
			exit(0);
	}

}
