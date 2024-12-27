#include <stdio.h>
#include <string.h>
// This program turns an integer into the the base b representation e.g., dec to hex = 20d = 14h
void itob(int n, char s[], int b);

int main(void) {
	char s[1000];
	//itob(20, s, 16);	dec to hex
	itob(10, s, 14); 
	printf("%s", s);
}

void itob(int n, char s[], int b) {
	int rem;
	int i = 0;
	do {
		rem = n % b; //numbers from 0 - base b
		s[i++] = (rem <= 9) ? rem + '0' : rem - 10 + 'A';	//0 - 9 are numbers. Nums > 9 are from alphabet (10 = 'A')
		n = n / b;	// Move over a decimal spot
	} while (n > 0);
	strrev(s);
	s[i] = '\0';
}