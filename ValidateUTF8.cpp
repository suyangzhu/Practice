#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

char mask(int n) {
	int first = 1;
	char tmp = (char) first;
	return (tmp << n);
}

bool CheckNext(const char* str) {
	char first = mask(7) & *str;
        char second = mask(6) & *str;	
	return (first && !second);
}
bool OneByte(const char* str) {
	char first = mask(7) & *str;
	return !first;
}

bool TwoByte(const char* str) {
	char first = mask(7) & *str;
	char second = mask(6) & *str;
	char third = mask(5) & *str;
	return (first && second && !third && CheckNext(str+1));
}

bool ThreeByte(const char* str) {
	char first = mask(7) & *str;
	char second = mask(6) & *str;
	char third = mask(5) & *str;
	char fourth = mask(4) & *str;
	return first && second && third && !fourth && CheckNext(str+1) && CheckNext(str+2);
}

bool FourByte(const char* str) {
	char first = mask(7) & *str;
	char second = mask(6) & *str;
	char third = mask(5) & *str;
	char fourth = mask(4) & *str;
	char fifth = mask(3) & *str;
	return first && second && third && fourth && !fifth && CheckNext(str+1) && CheckNext(str+2) && CheckNext(str+3);
}
bool IsUTF(const char* str) {
	while (*str) {
		if (OneByte(str)) {
			std::cout << "ascii" << std::endl;
			str++;
			continue;
		} else 
		if (TwoByte(str)) {
			str += 2;
			continue;
		} else 
		if (ThreeByte(str)) {
			std::cout << "chinese" << std::endl;
			str += 3;
			continue;
		} else
		if (FourByte(str)) {
			str += 4;
			continue;
		} else {
			return false;
		}
	}
	return true;

}


int main() {
	int a = 1;
	char b = (char)a;
	char str[10000] = "爱人afafafasdf" ;
	char *ptr = str;
	std::cout << ptr << std::endl;
	if (IsUTF(ptr)) std::cout << "TRUE" << std::endl;
	else std::cout << "FALSE" << std::endl;
	return 0;
}
