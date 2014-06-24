#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[5] = {-4, -2, -4, -1, -28};
	int i;
	int sum = a[0];
	int maxsum = a[0];
	for (i = 0; i < 5; i++) {
		sum += a[i];
		if (maxsum < sum) {
			maxsum = sum;
		} else if (sum < 0) {
			sum = 0;
		}
	}
	printf("maxsum = %d\n", maxsum);
}
