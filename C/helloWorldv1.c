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
//header ^
/*string n;
statement_01:
	scanf("Enter your name: %s ", n);
	goto statement_01;

	goto done;
*/
statement_01:
	printf("Hello World !\n");
	goto statement_01;
	goto done;
done:
	return 0;
} // end of int main(int argc, char *argv[])
// line comment
