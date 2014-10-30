#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
	public:
	int BinarySearch(vector<string>& str, int start, int end, string target) {
		if (start > end) return -1;
		int middle = (start + end) / 2;
		if (str[middle] == "") {
			int left = middle - 1;
			int right = middle + 1;
			while (1) {
				if (left < start && right > end) {
					return -1;
				} else 
				if (right <= end && str[right] != "") {
					middle = right;
					break;
				} else 
				if (left >= start && str[left] != "") {
					middle = left;
					break;
				}
				right++;
				left--;
			}
		}

		if (str[middle] == target) return middle;
		else 
		if (target.compare(str[middle]) < 0) {
			return BinarySearch(str, start, middle-1, target);
		} else {
			return BinarySearch(str, middle+1, end, target);
		}
	}
};

int main() {

	vector<string> str;
	str.push_back("a");
	str.push_back("");
	str.push_back("");
	str.push_back("");
	str.push_back("b");
	str.push_back("");
	str.push_back("c");
	str.push_back("");
	Solution sol;
	std::cout << sol.BinarySearch(str, 0, str.size() -1 , "d") << std::endl;
	return 0;
}
