/*
 * Name			: Manzel Gomez
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: reverseBinary.c
 *
 * Description	:
 * this program prompts user to enter a number and returns the reverse binary of input
 */

#include <stdio.h>

#define BASE 2

int main(int argc, char *argv[]) {
	int input, remainder;
	//int reverse[100]; 
	//int correct[100];
	printf("Please enter non-negative a number you would like to convert to reverse binary: \n");
	scanf("%d", &input);
	printf("\n");

	if(input <= -1){
		printf("What the hell, I said non negative");
		return 2;
	}

	else if(input == 0){
		printf("%d", input);
		return 1;
	}

	else{
		printf("[ ");
		while(input != 0){
		remainder = (input % BASE);
		input = (input / BASE);
//		while(input != 0){
//			for(int n = 0; n <= input; n++){
//				scanf("%d", &reverse[n]);
//			}
//		}

		printf("%d ", remainder);
		}
		printf("]");
	}


	return 0;
	}
// end of int main(int argc, char *argv[])
// line comment
