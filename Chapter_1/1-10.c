#include <stdio.h>

// Not introduced to If-Else statements yet
int main() {
	int c;

	while ((c = getchar()) != EOF) {
		// Print first blank then loop till non blank is found
		if (c == '\t') {
			printf("\\t");
		}
		if (c == '\b') {
			printf("\\b");
		}
		if (c == '\\') {
			printf("\\\\");
		}
		if (c != '\t') {
			if (c != '\b') {
				if (c != '\\') {
					putchar(c);
				}
			}
		}
	}

	return 0;
}

/*
int main() {
	int c;

	while ((c = getchar()) != EOF) {
		// Print first blank then loop till non blank is found
		if (c == '\t') {
			printf("\\t");			
		}
		else if (c == '\b') {
			printf("\\b");
		}
		else if (c == '\\') {
			printf("\\\\");
		}
		else {
			putchar(c);
		}
		
		
		
	}

	return 0;
}
*/

/*Task:
	Copy a programs input to its output. Replace tabs with \t, backspace with \b, and backslash with \\*/