#include <stdio.h>

/*Print Fahrenheit-Celcius table
  for fahr = 0, 20, ..., 300; floating-point*/
float fahrToCelcius(float fahr) {
	float celsius;

	celsius = (5.0 / 9.0) * (fahr - 32.0);
	return celsius;
}

int main() {
	float fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	
	// Heading above the table
	printf("Fahrenheit(0-300) to Celcius\n");
	printf("----------------------------\n");

	while (fahr <= upper) {		
		printf("%3.0f %6.1f\n", fahr, fahrToCelcius(fahr));
		fahr = fahr + step;
	}
	
	return 0;
}

/*Task:
	turn the conversion computation into a function*/