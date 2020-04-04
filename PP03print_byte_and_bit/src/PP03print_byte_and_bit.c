/*
 ============================================================================
 Name        : PP03print_byte_and_bit.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

void print_array(int * array_to_be_print, int length);
void print_array_using_hexadecimal_base(int * array, int starting_index ,int last_index);
void print_array_using_binary_base(int * array, int starting_index ,int last_index);
void print_binary(unsigned char x) ;

int main(void) {

	int length = 16;
	int * array = calloc(length, sizeof(int));
	for (int i=0 ; i<length ; i++){
		array[i] = i;
	}

	printf("print array:\n");
	print_array(array, length);

	printf("print_array_using_hexadecimal_base(array, 9, 14):\n");
	print_array_using_hexadecimal_base(array, 9, 14);

	printf("print array using binary base(array, 9, 12)\n");
	print_array_using_binary_base(array, 9, 12);





	return EXIT_SUCCESS;
}

void print_array(int * array_to_be_print, int length){
	printf("[");
	for (int i=0 ; i<length ; i++){
		printf("%d ", array_to_be_print[i]);
	}
	printf("]\n\n");
}

/*
 * last_index = (length-1) solitamente
 */
void print_array_using_hexadecimal_base(int * array, int starting_index ,int last_index){
	printf("[");
	for (int i=starting_index ; i<=last_index ; i++){
		int value = array[i];
		for(int j=0 ; j<sizeof(int) ; j++){
			BYTE tp = (value>>j*8)&0xFF;
			printf(" %02X", tp);
		}
		if(i < last_index){
			printf(",");
		}
	}
	printf("]\n\n");
}

void print_array_using_binary_base(int * array, int starting_index ,int last_index){
	printf("[");
		for (int i=starting_index ; i<=last_index ; i++){
			int value = array[i];
			for(int j=0 ; j<sizeof(int) ; j++){
				BYTE tp = (value>>j*8)&0xFF;
				print_binary(tp);
				printf(" ");
			}
			if(i < last_index){
				printf(",");
			}
		}
		printf("]\n");
}

void print_binary(unsigned char x) {
    int b = 128;

    while (b != 0) {

        if (b <= x) {
            x -= b;
            printf("1");
        } else
            printf("0");
        b = b >> 1;
    }
}
