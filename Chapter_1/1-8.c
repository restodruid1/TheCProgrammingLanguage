#include <stdio.h>



int main() {
	int tabs, blank, newline;
	tabs = 0;
	blank = 0;
	newline = 0;
	int c;

	// Grab each char from input
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++newline;
		}
		if (c == '\t'){
			++tabs;
		}
		if (c == ' ') {
			++blank;
		}
		
	}
	printf("tab:%d blank:%d newline:%d", tabs, blank, newline);
	

	return 0;
}

/*Task:
	Count tabs, blank spaces, and newlines*/