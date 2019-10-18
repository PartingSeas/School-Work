/*
 * Name			: FirstName LastName
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: template.c
 *
 * Description	:
 * C program template that we will use in the class to copy from and
 * and write other C programs
 * This is called a block comment
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	int counter = 0;
	double input;
	double total = 0.0, average = 0.0;

	do{
		printf("Enter the number you would like added to the average and press enter (to end, enter -1): \n");
		scanf("%lf", &input);
		if (input >= 0) total = total + input;
		counter++;
	} while (input != -1);
	
	counter = counter - 1;
	if(counter > 0){
		average = total / counter;
		printf("The average of the numbers you entered is: %f", average);
	}
	return 0; 
} // end of int main(int argc, char *argv[])
// line comment
