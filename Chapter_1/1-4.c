#include <stdio.h>

/*Print Fahrenheit-Celcius table
  for fahr = 0, 20, ..., 300; floating-point*/

// Fahrenheit Conversion
// C = (5.0/9.0) * (fahr - 32.0)
// 9.0C = (5.0) * (fahr - 32.0)
// 9.0C / 5.0 = (fahr - 32.0)
// ((9.0C) / 5.0) + 32.0 = fahr


int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	
	// Heading above the table
	printf("Celcius to Fahr\n");
	printf("----------------------------\n");

	while (celsius <= upper) {
		fahr = ((9.0 * celsius) / 5.0) + 32.0;
		printf("%6.1f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	
	return 0;
}

/*Task:
	Solve for Celcius to Fahrenheit.
	celsius = (5.0 / 9.0) * (fahr - 32.0);
	fahr = ((9.0C) / 5.0) + 32.0 */
