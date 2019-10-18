/*
 * Name			: Manzel Gomez
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: simpleCalculator.c
 *
 * Description	:
 * C program to do simple arithmetic operations (+, -, * and /) on two integers
 * accepted from the user
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b, result;
	char op, gobbler;

	printf("Enter first int: ");
	scanf("%d", &a);
	scanf("%c", &gobbler);

	printf("Enter operand (+, -, *, /): ");
	scanf("%c", &op);
	scanf("%c", &gobbler);

	printf("Enter second int: ");
	scanf("%d", &b);
	scanf("%c", &gobbler);

	if(op == '+'){
		result = a + b;
	} else if(op == '-') {
		result = a - b;
	} else if(op == '*') {
		result = a * b;
	} else if(op == '/') {
		if( b == 0){
			printf("cant divide by %d \n", b);
			return 1;
		}
		result = a / b;
	}else{
		printf("stupid mf...trying to use %c", op);
		return 2;
	}

	printf("a = [%d], op = [%c], b = [%d] \n", a, op, b);
	printf("%d %c %d = %d \n", a, op, b, result);
	return 0;
} // end of int main(int argc, char *argv[])
