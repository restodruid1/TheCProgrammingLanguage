#include <stdio.h>

#define swap(t,x,y) {	t _a; \
						_a = x; \
						x = y; \
						y = _a; }
					
					
						


int main(void) {
	int i = 1;
	int j = 2;

	printf("i = %d\nj = %d\n", i, j);
	swap(int, i, j);
	printf("New i = %d\nNew j = %d\n", i, j);
}