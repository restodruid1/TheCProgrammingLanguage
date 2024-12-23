#include <stdio.h>

int any(char s1[], char s2[]);

// Return the location of the first character in string2 that appears in string1
int main(void) {
	char s1[] = "laphant";
	char s2[] = "kevin";
	char s3[] = "juni";
	char s4[] = "arwey";

	
	printf("%d\n", any(s1, s2));
	printf("%d", any(s3, s4));
}
int any(char s1[], char s2[]) {
	int i;
	int j;

	
	for (i = 0; s2[i] != '\0'; i++) {
		for (j = 0; s1[j] != '\0'; j++) {
			if (s2[i] == s1[j]) {
				return j;
			}
		}
	}
	return -1;
}