#include <stdio.h>
#include <ctype.h>

// Prints output as upper or lower case depending on argv
int main(int argc, char *argv[]) {
	char c; 
	char arg = (*argv[1] == 'u' || *argv[1] == 'U') ? 'u' : 'l';
	
	while ((c = getchar()) != EOF) {
		if (arg == 'u')
			putchar(toupper(c));
		else {
			putchar(tolower(c));
		}
	}
	return -1;
}