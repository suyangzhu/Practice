#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int add(int x, int y) {
	if (y == 0) return x;

	int sum = x^y;
	int carry = (x&y) << 1;
	return add(sum, carry);
}

int main() {
	while (1) {
		int a, b;
		cin >>a;
		cin >>b;
		std::cout <<add(a, b) << std::endl;
	}
}
