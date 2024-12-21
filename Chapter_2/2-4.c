#include <stdio.h>

void squeeze(char s[], char c[]);

// Delete any charcater in s that matches any character in c
int main(void) {
	char s[] = "elephant";
	char c[] = "kevin";

	squeeze(s, c);
	printf("%s", s);
}
void squeeze(char s[], char c[]) {
	int i;
	int j;
	int k = 0;

	// var k holds spot in string for next valid char
	for (i = 0; s[i] != '\0'; i++) {
		for (j = 0; c[j] != '\0' && c[j] != s[i]; j++) {
			;
		}
		if (c[j] == '\0') {
			s[k++] = s[i];	// No match char found. Copy letter into string, increment k
		}					// If match found, k holds empty spot in string
	}
	s[k] = '\0';
}