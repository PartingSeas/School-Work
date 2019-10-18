#include <stdio.h>

int main() {
	for(int i = 1; i <= 100; i = i+1) {
		printf("[%3d]  ", i);
		if ((i % 10) == 0) {
			printf("\n");
		}
	}

	return 0;
}
