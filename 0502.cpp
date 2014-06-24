#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#define SIZE 10

int main() {
	int index = 0;
	std::ifstream infile("0502.cpp");
	std::string line[SIZE];
	while (!infile.eof()) {
		getline(infile, line[index++ % SIZE]);
	}
	if (index < 10) 
		index = 0;

	for (int i = 0; i < SIZE; i++) {
		std::cout << line[(index + i)% SIZE] << std::endl;
	}
	return 0;
}
