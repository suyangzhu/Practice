#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

void Translate(int n, string &str) {
	

		char tmp = n % 26 + 'A';
		str = tmp + str;
		n = n / 26;
		if (n == 0) {
			return;
		}
		Translate(n, str);
}

int main(){
	while(1) {
		int input;
		cin >> input;
		string str = "";
		Translate(input, str);
		std::cout <<str<<std::endl; 
	}
	return 0;
}
