/* O(n^2) */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

void findPairs(int* array, int num ,int val) {
	/* 
	// Method one: this will find all the pairs.
	int i, j;
	std::sort(array, array + num);
	for (i = 0; i < num; i++) {
		for (j = num - 1; j > i; j--) {
			if ((array[i] + array[j]) == val) {
				printf("%d + %d = %d\n", array[i], array[j], val);
			} else if (array[i] + array[j] < val) {
				break;
			} else 
				continue;
		}
	}
	*/
	// Method Two: this will ignore the repeat pairs.
	int first, last;
	std::sort(array, array + num);
	first = 0; 
	last = num - 1;
	while (first < last) {
		int sum = array[first] + array[last];
		if (sum == val) {
			std::cout << array[first] << "+" << array[last] << "=" << val << std::endl;
			first++;
			last--;
		} else if (sum < val) {
			first++;
		} else {
			last--;
		}
	}
}

int main() {
	int num[] = {1, 4, 3, 2, 5, 2, 4, 5};
	findPairs(num, sizeof(num) / sizeof(int),  6);
	return 0;	
}
