/*
 ============================================================================
 Name        : read_and_write.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//costanti simboliche
#define	false	0
#define	true	1

void print_some_printf();

int main(void) {
	print_some_printf();

	return EXIT_SUCCESS;
}

void print_some_printf(){
	puts("!!!Hello World!!!");

	printf("\nchar: \n");
	char ch = 65; // = 'A'
	printf("il valore esadecimale di '%c' è %x \n", ch, ch);
	printf("il valore numerico di '%c' è %d \n", ch, ch);
	ch = '\x42'; // = 'B' tradotto da esadecimale = 67
	printf("%c\n",ch);
	ch = '\103'; // = 'C' tradotto da base 8
	printf("%c\n",ch);
	putchar('\n');


	short int short_it_var = -32761;
	printf("short int: %hi \n", short_it_var);
	short_it_var = 0x42; // = 66
	printf("short int: %hi = %x in esadecimale\n", short_it_var, short_it_var);
	printf("short int size: %d \n\n", sizeof(short int));

	int int_var = -10;
	printf("int: %d \n\n", int_var);

	unsigned int var_unsigned_int = 10U; // = 2 fai attenzione ad non usare numeri negativi vcome in questo caso
	printf("unsigned int: %u\n", var_unsigned_int);
	printf("sempre unsigned int ma in esadecimale: %x \n\n", var_unsigned_int);

	long var_signed_long_int = 1234567890L; // suffisso L
	printf("long int o semplicmente long: %li\n\n", var_signed_long_int);

	unsigned long var_unsigned_long = 123456789123456789UL; // suffisso UL
	printf("unsigned long: %lu\n\n", var_signed_long_int);

	float var_float = 23.5F; // suffisso F
	printf("var_float: %.2f\n\n", var_float);

	double var_double = 222.788888D; // suffisso D
	printf("var_double: %.2lf\n\n", var_double);

}
