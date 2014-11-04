#include <cstdio>
#include <cstdlib>
#include <iostream>

void Swap1(int &x, int &y) {
	if (&x == &y) return;
	x = x+y;
	y = x-y;
	x = x-y;
}

void Swap2(int &x, int &y) {
	if (&x == &y) return;
	x = x^y;
	y = x^y;
	x = x^y;
}

int main() {
	int x = 5;
	int y = 10;
	std::cout << "x = " << x << " y = " << y << std::endl;
        Swap1(x, y);	
	std::cout << "x = " << x << " y = " << y << std::endl;
	return 0;
}
