#include <cstdio>

#include <cstdlib>
#include <iostream>
#include <string.h>

class Test {
	public:
		Test() {}
		~Test() {}
		void Print() {
			std::cout << "Hello World" << std::endl;
		}
		int a;
		int b;
		int c[100];
		std::string str;
};

int main() {
	Test tt;
	Test *t = &tt;
//	memset(t, 0, sizeof(Test));
	std::cout << sizeof(Test) << std::endl;
	t->Print();
	return 0;
}
