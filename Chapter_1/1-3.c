#include <stdio.h>

/*Print Fahrenheit-Celcius table
  for fahr = 0, 20, ..., 300; floating-point*/

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	
	// Heading above the table
	printf("Fahrenheit(0-300) to Celcius\n");
	printf("----------------------------\n");

	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}

/*Task:
	Modify the program to print a heading above the table*/