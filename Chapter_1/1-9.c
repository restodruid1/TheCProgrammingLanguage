#include <stdio.h>



int main() {
	int c;

	while ((c = getchar()) != EOF) {
		// Print first blank then loop till non blank is found
		if (c == ' ') {
			putchar(c);
			while (c == ' ') {
				c = getchar();
			}
		}		
		putchar(c);
		
	}

	return 0;
}

/*Task:
	Copy a programs input to its output. Replace a string of blanks with one space*/