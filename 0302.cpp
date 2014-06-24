#include <cstdio>
#include <cstdlib>
#include <iostream>


int swapOddEvenBits(int x) {
	return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
}

int main() {
	std::cout << swapOddEvenBits(1) <<  std::endl;
}
