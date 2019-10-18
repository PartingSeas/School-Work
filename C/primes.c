/*
 * Name			: Manzel Gomez
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: primes.c
 *
 * Description	:
 * C program to find an amount of prime numbers inputted by user
*/


#include <stdio.h>


int main() {
	int numOfprimes = 0, i = 3, x, z;

	printf("Enter the number of primes you want (1 to 1000): \n");
	scanf("%d", &numOfprimes);

	while (numOfprimes >= 1 && numOfprimes <= 1000) {
		if(numOfprimes == 1) {
			printf("\nFirst %d prime is:", numOfprimes);
			printf("\n");
			break;
		}
		else {
			printf("\nFirst %d primes are:", numOfprimes);
			printf("\n");
			break;
		}
	}

	for(x = 1; x <= numOfprimes; ) {
		for( z = 2; z <= i - 1; z++) {
			 if( i % z == 0)
				break;
		} if (z == i) {
		printf("[%d] \n", i);
		x++;
		}
	i++;
	}
}
