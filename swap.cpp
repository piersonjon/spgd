#include <iostream>
#include <cstdio>
#include <stddef.h>

using namespace std;

int main() {
	const int ARRLEN = 10;					// to change the array length, change this value.
	int arr1[ARRLEN] = {};
	int arr2[ARRLEN] = {};
	int temp = 0;
	for (int i=0;i<ARRLEN;i++) {
		printf("Please enter number %i.\n", i+1);
		scanf("%i", &arr1[i]);
	}

	for(int k=0;k<ARRLEN;k++) {				// we need to run this as many times as we have values in our array [ARRLEN]
		for (int i=0;i<(ARRLEN-1);i++) {	// for every value in the array (stopping one short of the end)...
			if (arr1[i]  < arr1[i+1]) {		// if the value is greater than the one on the right...
				swap(arr1[i], arr1[i+1]);	// exchange the 2 values.
			}								// for least to greatest,  use >. for greatest to least, use <.
		}
	}

	printf("[");

	for (int i=0;i<9;i++) {
		printf("%i, ", arr1[i]);
	}

	printf("%i]", arr1[9]);


	// appeneded obtuse data opt.

	return 0;
}

void swap(int v1, int v2) {
	int temp = 0;
	temp = v1;
	v1 = v2;
	v2 = temp;
}
