#include <stdarg.h>
#include <stdio.h>

void minscanf(char* format, ...);

int main(void) {
	float i;
	char s[20];

	minscanf("%s", s);

	printf("%s\n", s);

	return -1;
}

void minscanf(char* format, ...) {
	va_list ap;
	char* p, *sval;
	int *ival;
	double *dval;

	va_start(ap, format);
	for (p = format; *p; p++) {
		if (*p != '%')
			continue;

		switch (*++p) {
		case 'i':
		case 'd':
			ival = va_arg(ap, int*);
			scanf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double*);
			scanf("%f", dval);
			break;
		case 's':
			sval = va_arg(ap, char*);
			scanf("%[^\n]s", sval);	// scan input until new line is found
			break;
		}
	}
	va_end(ap);
}