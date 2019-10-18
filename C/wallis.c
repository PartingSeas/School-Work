/*
 * Name			: Manzel Gomez
 * Class		: CS-110 CA
 * Semester		: Fall 2019
 * This File	: wallisProduct.c
 *
 * Description	: some fuck shit ya herr
 */

#include <stdio.h>

double wallisProduct(unsigned int);

int main(int argc, char *argv[]) {
	unsigned int n;

	printf("Enter a number: ");
	scanf("%u", &n);

	double wp = wallisProduct(n);
	printf("n = %5u\t wp = %20.17f\n", n, wp);

	return 0;
} // end of int main(int argc, char *argv[])

double wallisProduct(unsigned int n){
	double wp = 1.0;
	for (unsigned int i = 1; i <= n; i++) {
		wp = wp * ((double)2*i/(2*i-1)) * ((double)2*i/(2*i+1));
	}
	return wp;
} //end of double wallisProduct()
// line comment
