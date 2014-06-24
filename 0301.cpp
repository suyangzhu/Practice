#include <iostream>
#include <cstdio>
#include <cstdlib>

int BitSwapReqd(int a, int b) {
	int count = 0;
	for (int c = a ^ b; c != 0; c = c >> 1) {
		count += c & 1;
	}
	return count;
}

int main() {
	std::cout << BitSwapReqd(10, 11) << std::endl;
	return 0;
}
