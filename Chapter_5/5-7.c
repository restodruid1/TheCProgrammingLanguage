#include <stdio.h>
#define MAXLEN 1000

int readlines(char *[], int, char[]);
int main(void) {
	char storage[MAXLEN];
	char *lineptr[MAXLEN];
	int nlines = 0;
	int i = 0;

	if ((nlines = readlines(lineptr, MAXLEN, storage)) >= 0) {
		printf("Lines Read\n");
	}
	while (i < nlines) {
		printf("Lines: %d\n", i);
		printf("%s\n", lineptr[i]);
		i++;
	}
}

int getline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void strcpy(char* s, char* t) {
	while ((*s++ = *t++) != '\0')
		;
}

int readlines(char *lineptr[], int maxlines, char storage[]) {
	int len, nlines, storagelines;
	char* p, line[MAXLEN];

	nlines = 0;
	storagelines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || MAXLEN <= storagelines)
			return -1;
		else {
			line[len - 1] = '\0';
			// Allocate space in storage array in main function
			if (len + storagelines <= MAXLEN) {
				p = storage + storagelines;		// Two different ways of getting the memory address from storage
				//p = &storage[storagelines];
				strcpy(p, line);
				lineptr[nlines++] = p;		// Add the pointer to the line of text to lineptr array
				storagelines += (len + 1);	// Get next available memory spot for storage
			}
			else {
				return -1;
			}
			
		}
	return nlines;

}