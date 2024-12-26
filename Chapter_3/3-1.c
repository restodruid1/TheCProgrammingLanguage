#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {
	int x = 6;
	int v[] = {1,2,3,4,5,6,7,8,9};
	int n = 10;

	printf("%d", binsearch(x, v, n));
}

int binsearch(int x, int v[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while (low <= high && v[mid] != x) {
		if (x < v[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}
	if (v[mid] == x) {
		return mid;
	}
	else {
		return -1;
	}
}