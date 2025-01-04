#include <stdio.h>
void strcat(char *s, char *t);

int main(void) {
	char s[] = "hello";
	char t[] = "world";
	strcat(s, t);
	printf("%s", s);
}

void strcat(char *s, char *t) {
	while (*s != '\0') {
		s++;
	}
	while (*t != '\0') {
		*s++ = *t++;
	}
	*s = '\0';
}