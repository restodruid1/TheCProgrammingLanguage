#include <stdio.h>



int main() {
	int c;

	while (c = getchar() != EOF) {
		//putchar(c);
		printf("%d\n", c);
	}
	//putchar(c);

	return 0;
}

/*Task:
	Confirm that c = getchar() != EOF will return 1 instead of the acutal input character*/