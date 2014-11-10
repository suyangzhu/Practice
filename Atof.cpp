#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <float.h>
#include <math.h>
using namespace std;

float Atof(const char* str) {
	if (!str || !*str) return 0;
	while (*str == ' ') str++;
	int sign = 1;
	if (*str == '-') {
		sign = -1;
		str++;
	} else if (*str == '+') {
		str++;
	}

	float base = 0.0;
	while (str && *str >= '0' && *str <= '9') {
		base = 10*base + *str-'0';
		str++;
	}
	if (str && *str != '.') return sign*base;
	if (*str == '.') str++;
	float decimal = 0.0;
	int cnt = 1;
	while (*str && *str >= '0' && *str <= '9' && cnt < 6) {
		decimal += (float)(*str-'0')/ pow(10, cnt++);
		str++;
	}
	return sign*(base + decimal);
}

int main() {
	while (1) {
		char num[100]; 
		cin >> num ;
		std::cout << Atof(num) << std::endl;
	}
	return 0;
}


