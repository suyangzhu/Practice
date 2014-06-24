#include <cstdio>
#include <cstdlib>

#include <iostream>

void swap(int& a, int& b) {
	if (a != b) {
		a = a^b;
		b = a^b;
		a = a^b;
	}
}

int main() {
	int a = 3, b = 4;
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	return 0;
}
