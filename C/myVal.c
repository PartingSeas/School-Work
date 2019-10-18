#include <stdio.h>

int main(){
	int i = 1, a = 5;
	int myVal = 0;

	for(int b = 2; b > i; b--){
		myVal = a++;
		printf("%d", myVal);
	}
	return 0;
}
