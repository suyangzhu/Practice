#include <iostream>
#include <deque> 

using namespace std;

int main() {
	std::deque<int> myDeque(10, 0);
	for (int i = 0; i < myDeque.size(); i++) {
		myDeque[i] = i;
	}
	for (int i = 0; i < myDeque.size(); i++) {
		std::cout << myDeque[i] << std::endl;
	}
	return 0;
}
