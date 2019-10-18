/*
 * Name			: Manzel Gomez
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File		: adder.c
 *
 * Description:
 * This program will allow you to add two numbers and add them together 
 *
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	int i;

	printf("Enter a number: ");
	scanf("%d",&n);

	printf("Enter another number: ");
	scanf("%d", &i);

	printf("You have entered %d and %d \n",n,i);
	printf("%d + %d \n", n,i);
	printf("the sum is %d ", n+i);


	return 0;
}
