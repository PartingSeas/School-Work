#include <stdio.h>

int main(){
	int i = 0, x = 0;

	printf("enter a number you would like seperated \n");
	scanf("%d", &i);
	
	while(i != 0){	
		x = i / 10;
		printf("The digits in [%d] are [%d] ", i, x);	
		i = i % 10;
	}

	return 0;
}
