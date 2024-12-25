#include <stdio.h>
// Rewrite lower function which converts upper case to lower case, with a conditional statement

void lower(char s[]);
int main(void) {
	char k[] = "MR.ROBOT";
	lower(k);
	printf("%s", k);
}

void lower(char s[]) {
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? 'a' + (s[i] - 'A') : s[i];	// if s[i] is upper case, start with 'a' and add the upper case differnce
																			// to get correct lower case value. else, keep letter same
	}
}