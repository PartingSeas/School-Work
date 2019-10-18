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


bool checkIfNumEqualToOne(int num){
	if(num == 1) {
		return true;
	}
	return false;
}
bool checkIfInputIsNotANumber(int char){
	if(char <= 49 && char >= 58){
		return false;
	}
	return true;
}


int main() {
	int numOfprimes = 0, i = 3, x, z;
	char c;
	bool condition = false;

	while(!condition){
		//-> contune takes you here
		printf("Enter the number of primes you want (1 to 1000): \n");
		scanf("%d %c", &numOfprimes, &c);
		int charval = (int)c;
		printf("%d", charval);

		if (checkIfInputIsNotANumber(charval)) {
			continue;
		}

		for (int b = 1; b <= numOfprimes; ){
			if(checkIfNumEqualToOne(numOfprimes)) {
				printf("\nFirst %d prime is:", numOfprimes);
				printf("\n");
			}
			if (numOfprimes >= 2 && numOfprimes < 1000) {
				printf("\nFirst %d primes are:", numOfprimes);
				printf("\n");
			}
			else if (numOfprimes > 1000){
				printf("\nNo numbers over 1000 \n");
				printf("\n");
			}
		}
		condition = true;
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
