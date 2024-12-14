#include <stdio.h>

#define YES 1
#define NO 0

int main() {
	int c;
	int newWord;

	newWord = NO;

	while ((c = getchar()) != EOF) {
		//Parse input until valid character found
		if (newWord == NO) {
			while (c == ' ' || c == '\t' || c == '\n') {
				c = getchar();
			}
			newWord = YES;
			putchar(c);
		}
		//Either add to existing word or end it
		else {
			if (c == ' ' || c == '\t' || c == '\n') {
				putchar('\n');
				newWord = NO;
			}
			else {
				putchar(c);
			}
		}
	}

	return 0;
}



/*Task:
	print input one word per line*/