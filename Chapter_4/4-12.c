#include <stdio.h>
void itoa(int n);

char s[10];	// External buffer

int main(void) {
	int i = -21;
	//char s[10];
	//printf("%d\n", 2 / 10);
	itoa(i);

	printf("%s", s);
}

int p = 0;	// External array index counter
void itoa(int n) {
	if (n < 0) {	// Add negative to string and offset to positive for remainder
		s[p++] = '-';
		n = -n;
	}
	if (n / 10) {	// not 0
		itoa(n / 10);	// Move over one decimal place to left
	}
	s[p++] = (n % 10) + '0';
	s[p] = '\0';
}