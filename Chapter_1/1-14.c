#include <stdio.h>

#define YES 1
#define NO 0
#define ALPHABET 26
#define NUMERICAL 10

int main() {
	int c;
	int newWord;
	int wordSize;
	int wordCountArr[ALPHABET + NUMERICAL]; //Set array to size 36(26 letters (a-z) & 10 numbers (0-9))
	int i;

	newWord = NO;
	wordSize = 0;
	
	// Initiate array with 0
	for (i = 0; i < ALPHABET + NUMERICAL; i++) {
		wordCountArr[i] = 0;
	}
	
	while ((c = getchar()) != EOF) {
		//Filter none letters
		while (c == ' ' || c == '\t' || c == '\n') {
			c = getchar();
		}
		//Populate array if the character is 0-9
		if (c - '0' >= 0 && c - '9' <= 9) {
			printf("num\n");
			wordCountArr[c - '0']++;
		}
		//Populate array if the character is a-z
		else if (c - 'a' >= 0 && c - 'a' <= 26) {
			wordCountArr[c - 'a' + 10]++;
		}
		//Populate array if the character is A-Z
		else if (c - 'A' >= 0 && c - 'A' <= 26) {
			wordCountArr[c - 'a' + 10]++;
		}
	}
	//Print histogram of numbers 0-9
	for (i = 0; i < NUMERICAL; i++) {
		printf("%2d:", i);
		while (wordCountArr[i] > 0) {
			printf("*");
			wordCountArr[i]--;
		}
		printf("\n");
		
	}
	//Print histogram of alphabet 
	for (i = 10; i < ALPHABET+10; i++) {
		printf("%2c:", i - 10 + 'a');
		while (wordCountArr[i] > 0) {
			printf("*");
			wordCountArr[i]--;
		}
		printf("\n");

	}

	return 0;
}



/*Task:
	print a histogram of the frequency of each character*/