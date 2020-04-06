/*
 ============================================================================
 Name        : PP2memcmp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(void) {

	int ARRAY_LEN = 5;
	int arr_a[] = {1,2,3,4,5};
	int arr_b[] = {1,2,3,4,5};

	printf("arr_a: %X\n", *arr_a);

	int result;
	result = memcmp(arr_a, arr_b, ARRAY_LEN * sizeof(int));
	printf("first memcmp: %d\n", result);
	if(result == 0){
		printf("this array are equals\n");
	}

	result = memcmp(arr_a, &arr_b[1], 3 * sizeof(int));
	printf("memcmp(arr_a, &arr_b[1], 3 * sizeof(int) == %d\n", result);


	return EXIT_SUCCESS;

}



void printbyteArray(char * array, int length){
	printf("\n[");
	for (int i=0 ; i<length ; i++){
		printf("%x ", array[i]);
	}
	printf("]\n");
}

