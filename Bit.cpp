#include <climits> 
#include <cstdio>
#include <cstdlib>
#include <iostream>
int flip(int bit) {
	return 1^bit;
}
/** return 1 when a positive, 0 when a negative */
int sign(int a) {
	return flip ((a >> 31)& 0x1);
}

int FindMax(int a, int b) {
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);

	int use_sign_a = sa ^ sb;
	int use_sign_c = flip(sa^sb);
	int k = use_sign_a * sa + use_sign_c * sc;
	int q = flip(k);
	return k * a + q * b;
}


int main() {
	int val = INT_MIN;
	std::cout << FindMax(-10, INT_MIN) << std::endl;
	std::cout << std::endl;
}
