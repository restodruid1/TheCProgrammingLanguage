#include <stdio.h>
int main(void) {
	int i = 5;
	int j = 9;
	int k;
	printf("%d\n", i);
	printf("%d\n", j);
	printf("%d\n", k =  j&i);

	int b1 = 0b01;
	printf("%d\n", b1);
	printf("%d\n", b1 << 0b10);

	printf("%d", 0b11 & 0177);
}



				