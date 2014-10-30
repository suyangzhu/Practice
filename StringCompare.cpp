#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	string str1 ("ac");
	string str2 ("ab");
	std::cout << str1.compare(0, 1, str2, 0, 1) << std::endl;
	return 0;
}
