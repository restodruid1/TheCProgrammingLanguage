#include <stdio.h>

void escape(char s[], char t[]);

int main(void) {
	char s[] = "";
	char t[] = "abcd\nef	gh";
	escape(s, t);
	printf("%s", s);
}

void escape(char s[], char t[]) {
	int i, j = 0;

	for (i = j; t[i] != '\0'; i++) {
		switch (t[i]) {
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}