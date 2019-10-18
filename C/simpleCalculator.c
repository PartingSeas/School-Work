/*
 * Name			: Manzel Gomez
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: adder.c
 *
 * Description:
 * This program will allow you to add two numbers and add them together 
 *
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

	int n=0, i=0;

	printf("Enter two numbers: ");
	scanf("%d %d",&n, &i);

	printf("%d + %d = %d \n", n,i, n+i); 
	printf("%d - %d = %d \n", n,i, n-i); 
	printf("%d * %d = %d \n", n,i, n*i);
	
	//make the person feel bad for trying to divide by zero
	if (i == 0){
		printf("cant be dividing by no zero's, you know that, cmon: %d / %d \n", n, i);
		printf("get lost. \n");
	}

	else {
		printf("%d / %d = %d \n", n,i, n / i);
		printf("This is cool.\n");
	}

	return 0;
}
