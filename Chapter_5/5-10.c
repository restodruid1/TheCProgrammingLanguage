#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int arr[argc];
	int i = 0;
	
	printf("argc: %d\n", argc);
	while (--argc > 0) {	// Loop through each element in argv
		// Add digit from argv to stack to be calculated
		if (isdigit(**++argv)) {	
			int j = **argv - '0';
			arr[++i] = j;
			printf("%d\n", arr[i]);
		}
		else {
			// argv is an operator so take last two numbers from stack and add calculated number back to stack
			char c = **argv;
			printf("char: %c\n", c);
			if (c == '+') {
				arr[i - 1] = arr[i] + arr[i - 1];
			}
			else if (c == '-') {
				arr[i - 1] = arr[i] - arr[i - 1];
			}
			else if (c == '*') {
				arr[i - 1] = arr[i] * arr[i - 1];
			}
			else if (c == '/') {
				arr[i - 1] = (arr[i-1] == 0) ? 0 : arr[i] / arr[i - 1];
			}
			else {
				continue; // This handles shell issues with '*' (to multiply, use *' in argv) 
			}
			i -= 1; // Reset pointer to top stack
		}
	}
	printf("answer: %d", arr[1]);	// Answer will exist at index 1
}