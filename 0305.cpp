#include <cstdio>
#include <cstdlib>

int foo(int n, int m, int i, int j) {
	int max = ~0;
	int left = max - ((1 << j) - 1);
	int right = ((1 << i) - 1);
	int mask = left | right;
	return ((n & mask) | (m << i));
}

int main() {
	foo(30, 13, 1, 2);
}
