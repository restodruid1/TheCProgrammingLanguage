#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void) {
	char s[] = "9876.4";
	char s2[] = "9876.4e2";
	char s3[] = "9876.4e-2";
	printf("%f\n", atof(s));
	printf("%f\n", atof(s2));
	printf("%f\n", atof(s3));

	printf("%d\n", 102 / 10.0);
	printf("%f", 102 / 10.0);
}

// return rightmost index occurance of t in s
double atof(char s[]) {
	double val, power;
	int i, sign, signSci, sci;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
	}
	else {
		return val;
	}

	signSci = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	sci = s[i] - '0';
	//printf("%d\n", sci);
	while (sci > 0) {
		if (signSci == -1) {
			val = val / 10.0;
		}
		else {
			val = 10.0 * val;
		}
		sci--;
	}
	
	return sign * val;
}