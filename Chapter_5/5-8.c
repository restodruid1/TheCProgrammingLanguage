#include <stdio.h>

int day_of_year(int year, int month, int day);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void) {
	printf("%d\n", day_of_year(2025, 1, 5));
	printf("%d\n", day_of_year(2025, 2, 1));
}
int day_of_year(int year, int month, int day) {
	int i, leap;
	char *p;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	p = daytab[leap]; // Get correct row of two dimensional array

	while (month--)	// Iterate over the months, adding days per month to day
		day += *p++;	// Move pointer along array
	
	return day;
}