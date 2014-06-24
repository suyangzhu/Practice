#include <cstdio>
#include <cstdlib>
#include <iostream>

int findMax(int a, int b) {
	int c = a - b;
	int d = c >> 32;
	std::cout << c << "   " << d << std::endl;
	return (a - d * c);
}

int main() {
	std::cout << findMax(10, 20) << std::endl;	
}
