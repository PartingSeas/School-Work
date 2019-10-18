#include <stdio.h>

unsigned long sum(unsigned int n);
unsigned long square(int n);
unsigned long sumOfSquares(unsigned int n);

unsigned long sum(unsigned int n) {
  unsigned long result = 0;

  for(unsigned int i = 1; i <= n; i++){
    result = result + i;
  }

  return result;
}

unsigned long sumOfSquares(unsigned int n){
  unsigned long result = 0;

  for(unsigned int i = 1; i <= n; i++){
    result = result + square(i);
  }
  return result;
}
