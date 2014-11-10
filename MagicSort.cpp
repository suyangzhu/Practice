#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool Comparator(const string& first, const string& second) {
	return first + second < second + first;
}

string SmallestCombine(vector<string>& str) {
	sort(str.begin(), str.end(), Comparator);
	string result;
	for (int i = 0; i < str.size(); i++) {
		result.append(str[i]);
	}
	return result;
}

int main() {
	vector<string> vec;
	vec.push_back("546");
	vec.push_back("54");
	vec.push_back("542");
	vec.push_back("60");
	std::cout << SmallestCombine(vec) << std::endl;
}
