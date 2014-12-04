#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int val;
};

struct Comparator {
	bool operator() (Node &a, Node &b) {
		return a.val > b.val;
	}
};


void TestPriorityQueue() {
	priority_queue<Node, vector<Node>, Comparator> pq;
	for (int i = 0; i < 10; i++) {
		Node n;
		n.val = i;
		pq.push(n);
	}
	while (!pq.empty()) {
		std::cout << pq.top().val << std::endl;
		pq.pop();
	}
}

int main() {
	TestPriorityQueue();
	return 0;
}
