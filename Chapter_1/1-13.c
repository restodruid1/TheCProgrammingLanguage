#include <stdio.h>

#define YES 1
#define NO 0

int main() {
	int c;
	int newWord;
	int wordSize;
	int wordCountArr[10];
	int i;

	newWord = NO;
	wordSize = 0;
	
	for (i = 0; i <= 10; i++) {
		wordCountArr[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		//Parse input until valid character found
		if (newWord == NO) {
			while (c == ' ' || c == '\t' || c == '\n') {
				c = getchar();
			}
			newWord = YES;
			wordSize++;
			putchar(c);
		}
		//Either add to existing word or end it
		else {
			if (c == ' ' || c == '\t' || c == '\n') {
				putchar('\n');
				if (wordSize >= 10) {
					wordCountArr[10]++;
				}
				else if (wordSize < 10) {
					wordCountArr[wordSize]++;
				}
				newWord = NO;
				wordSize = 0;
			}
			else {
				putchar(c);
				wordSize++;
			}
		}
	}
	for (i = 1; i < 11; i++) {
		printf("%2d:", i);
		while (wordCountArr[i] > 0) {
			printf("*");
			wordCountArr[i]--;
		}
		printf("\n");
		
	}

	return 0;
}



/*Task:
	print a histogram of the length of words from input*/