/*
 * Name			: FirstName LastName
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: template.c
 *
 * Description	:
 * allows user to enter a number and receive the factorial value back
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	unsigned short int i;
	unsigned long int fact = 1;

	printf("Enter a number between 0 - 20: ");
	scanf("%hd", &i);


	// if(i >= 0 && i <= 20){
	// 	for(unsigned short n = 1; n <= i; n++ ){
	// 	fact = fact * n;
	// 	}
	// } else {
	// 	printf("Please look at the instructions! ");
	// }

	switch(i) {
		case 7:
			fact = fact * i--;
		case 6:
			fact = fact * i--;
		case 5:
			fact = fact * i--;
		case 4:
			fact = fact * i--;
		case 3:
			fact = fact * i--;
		case 2:
			fact = fact * i--;
		case 1:
			fact = fact * i--;
	}

	printf("number entered: %hd, factorial: %lu \n", i, fact);

	return 0;
} // end of int main(int argc, char *argv[])
// line comment
