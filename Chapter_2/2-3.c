// Convert a hexadecimal string into its integer value
#include <math.h>
#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main(void) {
	char s[] = "1A37";
	char c[] = "0x1A37";
	printf("%d\n", htoi(s));
	printf("%d\n", htoi(c));
}
int htoi(char s[]) {
	int ele = 0;
	int len = 0;
	int ans = 0;
	int decVal;

	while (s[ele] != '\0') {
		ele++;
	}
	ele--;
	len = ele;
	printf("%d\n", len);
	// Iterate from len of hex string back to 0
	while (ele >= 0) {
		if (isdigit(s[ele])) {
			decVal = s[ele] - '0';
		}
		else if (s[ele] >= 'A' && s[ele] <= 'F') {
			decVal = s[ele] - 'A' + 10;
		}
		else if (s[ele] >= 'a' && s[ele] <= 'f') {
			decVal = s[ele] - 'a' + 10;
		} 
		else if (s[ele] == 'X' || s[ele] == 'x' && ele == 1 && s[ele - 1] == '0') {
			return ans;
		}
		else {
			return -1; // invalid hex
		}
		ans = pow(16, len - ele) * decVal + ans;	// Convert from hex to decimal
		printf("%d\n", ans);
		ele--;
	}
	return ans;
}