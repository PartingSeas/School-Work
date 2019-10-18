/*
 * Name			: Manzel Gomez
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: switchStatement.c
 *
 * Description	:
 * 
 * 
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	unsigned short i;
	printf("Enter a small non-negative number: ");
	scanf("%hd", &i);

	switch (i) { 
		case 0:
			printf("You entered a zero, you get an %c \n", 'A');
			break;
		case 1:
			printf("You entered a one, you get a %c \n", 'B');
			break;
		case 2:
			printf("You entered a two, you get a %c \n", 'C');
			break;
		case 3:
			printf("You entered a three, you get a %c \n", 'D');
			break;
		case 4:
			printf("You entered a four, you get a %c \n", 'F');
		default: 
			printf("invalid input");
			break;
	}

	return 0;
} // end of int main(int argc, char *argv[])
// line comment
