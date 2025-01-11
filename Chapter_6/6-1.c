#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define BUFFSIZE 100
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char*, int);
int binsearch(char*, struct key*, int);

struct key {
	char* word;
	int count;
} keytab[] = {
"auto", 0,
"break", 0,
"case", 0,
"char", 0,
"const", 0,
"continue", 0,
"default", 0,
/* ... */
"unsigned", 0,
"void", 0,
"volatile", 0,
"while", 0
};

/* count C keywords */
main()
{
	int n;
	char word[MAXWORD];
	while (getword(word, MAXWORD) != EOF) {
		printf("%s\n", word);
		if (isalpha(word[0])) {
			if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
				keytab[n].count++;
			}
		}
	}
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",
				keytab[n].count, keytab[n].word);
	return 0;
}
/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char* word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* getword: get next word or character from input */
int getword(char* word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char* w = word;
	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		// Parses line like normal
		if (c == '#' || c == '_') {
			for (; --lim > 0; w++)
				// Add chars to word until space is found
				if ((c = getch()) != ' ') {
					*w = c;
				}
				else {
					*w = '\0';
					return word[0];
				}

		}
		// Adds chars until string terminator found
		else if (c == '"') {
			while ((c = getch()) != '"') {
				*w++ = c;
			}
			*w++ = '"';
			*w = '\0';
			return word[0];
		}
		// Handles comments
		else if (c == '/') {
			// Comment of the form "/* */"
			c = getch();
			if (c == '*') {
				while ((c = getch()) != '\n') {
					if ((c = getch()) == '*') {
						if ((c = getch()) == '/') {
							*w = '\0';
							return word[0];
						}
					}
				}
			}
			else if (c == '/') {	//Skip entire line (find '\n')
				while ((c = getch()) != '\n') {
					;
				}
				*w = '\0';
				return word[0];
			}	
			
		}
		// None of the above
		else {
			*w = '\0';
			return c;
		}
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

int bufp = 0;
char buf[BUFFSIZE];

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}