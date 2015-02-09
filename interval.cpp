#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Interval {
public:
	Interval(int start, int end, int weight) : start(start), end(end), weight(weight) {}
	~Interval() {}
	int start;
	int end;
	int weight;
};
/** Return the max weight of non-overlapping intervals. */

struct Comparator {
	bool operator()(Interval & first, Interval & second) {
		return first.end > second.end;
	}
};

void TestSort(vector<Interval> vec) {
	sort(vec.begin(), vec.end(), Comparator());
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i].start << " " << vec[i].end << " " << vec[i].weight << std::endl;
	}
}

int MaxWeight(vector<Interval> &vec) {
}

int main() {
	vector<Interval> intervalVec;
	Interval itl1(0, 3, 1);
	Interval itl2(2, 7, 2);
	Interval itl3(4, 5, 2);
	intervalVec.push_back(itl1);
	intervalVec.push_back(itl2);
	intervalVec.push_back(itl3);
	TestSort(intervalVec);
	return 0;
}



