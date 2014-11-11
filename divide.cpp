#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;
string Divide(int a, int b) {
	string integer = "";
	string decimal = "";
	string sign = "";
	int cnt = 0; 
	if (b == 0) return "";
	if (a == 0) return "0";
	if (a > 0 && b > 0 || a < 0 && b < 0) {
		sign = "";
	} else {
		sign = "-";
	}
	a = a > 0?a:-a;
	b = b > 0?b:-b; 
	while (a >= b) {
		a -= b;
		cnt++;
	}
	integer.append(to_string(cnt));
	int remain = a;
	int idx = 0;
	unordered_map<int, int> usedNumber;
	while (remain != 0) {
		remain *= 10;
		if (usedNumber.count(remain) > 0) {
			decimal.insert(usedNumber[remain], "(");
			decimal.push_back(')');
			break;
		}
		usedNumber.insert(make_pair(remain, idx++));
		cnt = 0;
		while (remain >= b) {
			remain -= b;
			cnt++;
		}
		decimal.append(to_string(cnt));
	}
	return sign+integer+"."+decimal;
}

int main() {
	while (1) {
		int a;
		int b; 
		cin >> a;
		cin >> b;
		std::cout << Divide(a, b) << " = " <<double(a) / (double) b << std::endl;
	}
}
