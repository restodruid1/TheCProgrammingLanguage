#include <stdio.h>

int strrindex(char s[], char t);

int main(void) {
	char s[] = "hell0";
	char t = 't';
	
	printf("%d", strrindex(s, t));
}

// return rightmost index occurance of t in s
int strrindex(char s[], char t) {
	int index = -1;
	int i = 0;

	while (s[i] != '\0') {
		if (s[i] == t) {
			index = i;
		}
		i++;
	}
	return index;	// returns -1 if no match is found
}