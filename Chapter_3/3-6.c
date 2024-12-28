#include <stdio.h>
#include <string.h>
// This program converts an integer into characters in s
void itoa(int n, char s[], int width);

int main(void) {
	char s[1000];
	//itob(20, s, 16);	dec to hex
	itoa(15, s, 5); 
	printf("%s", s);
}

void itoa(int n, char s[], int width) {
	int i, sign;

	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	
	if (sign < 0) {
		s[i++] = '-';
	}
	while (i < width) {
		s[i++] = ' ';
	}
	strrev(s);
	s[i] = '\0';
}