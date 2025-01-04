#include <stdio.h>
int strend(char*, char*);

int main(void) {
	char s[] = "hello";
	char t[] = "lo";
	char t2[] = "hlo";

	printf("%d\n", strend(s, t));
	printf("%d", strend(s, t2));
}

int strend(char *s, char *t) {
	int lenS = 0;
	int lenT = 0;

	// Get length of s
	while (*s != '\0') {
		s++;
		lenS++;
	}
	// Get length of t
	while (*t != '\0') {
		t++;
		lenT++;
	}
	// Back one to end of string from \0 terminator
	t--;
	s--;
	// While the strings match
	while ((*t == *s) && lenT > 0) {
		printf("t = %c, s = %c\n", *t, *s);
		t--;
		s--;
		lenT--;
	}
	if (lenT == 0) {
		return 1;
	}
	else {
		return 0;
	}
}