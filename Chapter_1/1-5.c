#include <stdio.h>

/*Print Fahrenheit-Celcius table
  for fahr = 300, 280, ..., 0; floating-point*/

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = upper;
	
	// Heading above the table
	printf("Fahrenheit(300-0) to Celcius\n");
	printf("----------------------------\n");
	/*
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	*/
	for (upper; fahr >= lower; fahr = fahr - step) {
		printf("%3.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
	}
	return 0;
}

/*Task:
	Modify the program to print fahrenheit to celcius in reverse order
	Practice with for loop compared to previous while loops*/