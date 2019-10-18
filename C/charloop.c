#include <stdio.h>

int main() {
	//unsigned char ch;
	printf("[%3s]\t[%3s]\n", "dec", "chr");
	for(int i = 1; i <= 256; i = i + 1) {
		printf("[%3d]\t[%c]\n", i, i);
		}

	return 0;
}
