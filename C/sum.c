#include <stdio.h>

unsigned long sum(unsigned int n);
unsigned long square(int n);
unsigned long sumOfSquares(unsigned int n);

int main(int argc, char const *argv[]) {
  unsigned int n;

  printf("Enter a positive integer: ");
  scanf("%d", &n);


  unsigned long x = sum(n);
  unsigned long y = sumOfSquares(n);

  printf("Sum of integers from 1 to %d is %lu \n", n, x);
  printf("Sum of squares from 1 to %d is %lu\n", n, y);

  return 0;
}

unsigned long sum(unsigned int n) {
//  printf("\t entering oddSum (%d)\n", n);
  unsigned long result = 0;

  for(unsigned int i = 1; i <= n; i++){
//    printf("\t adding (%d) sum\n", n);
    result = result + i;
  }

//  printf("\t exiting oddSum (%d)\n", n);
  return result;
}

unsigned long sumOfSquares(unsigned int n){
  unsigned long result = 0;

  for(unsigned int i = 1; i <= n; i++){
    result = result + square(i);
  }
  return result;
}

unsigned long square(int n) {
  return n*n;
}
