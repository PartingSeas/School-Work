//Name: Manzel Gomez
//Class: CS-110
//Program: euclideanAlgorithm.c
//description: This program allows a user to input two numbers and finds the greatest common divisor.


#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a = 0, b = 0, remainder = 0, real = 0;

  printf("Enter two numbers to find the gcd: ");
  scanf("%d %d", &a, &b);

// Stops program if user enters a zero

  while(a == 0 || b == 0) {
    printf("gcd(%d, %d) is not defined\n", a , b);
    return 1;
  }

// find out the mod of a mod b

  remainder = a % b;

// if b goes into a perfectly, the lowest common divisor is b itself

  while (remainder == 0) {
    printf("gcd(%d, %d) is %d\n", a , b , b );
    return 2;
  }

//as long as the remainder is not 0, take a mod b until you get GCD

  while(remainder > 1) {
    real = remainder;
    remainder = b % remainder;
    if (remainder == 0) {
      printf("gcd(%d, %d) is %d\n", a , b, real);
      return 3;
    }
  }

  return 0;
}
