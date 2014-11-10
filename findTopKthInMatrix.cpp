#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct Node { 
	int val;
	int x;
	int y;
	Node(int val, int x, int y) : val(val), x(x), y(y) {}
};

struct Comparator {
	bool operator()(Node first, Node second) {
		first.val > second.val;	// min heap
	}
};
vector<int> FirstKElement(vector<vector<int> > A, int k) {
	priority_queue<Node, vector<Node>, Comparator> minHeap;
	Node head (A[0][0], 0, 0);
	vector<int> result;
	minHeap.push(head);
	int n = A.size();	
	for (int i = 0; i < k; i++) {
		if (!minHeap.empty()) {
			Node node = minHeap.top();
			minHeap.pop();
			while (!minHeap.empty() && minHeap.top().val == node.val) minHeap.pop();
			if (node.x == n-1 && node.y == n-1) {
				continue;
			} else if (node.x == n-1) {
				Node left(A[node.x][node.y+1], node.x, node.y+1);
				minHeap.push(left);
			} else if (node.y == n-1) {
				Node down(A[node.x+1][node.y], node.x+1, node.y);
				minHeap.push(down);
			} else {
				Node left(A[node.x][node.y+1], node.x, node.y+1);
				minHeap.push(left);
				Node down(A[node.x+1][node.y], node.x+1, node.y);
				minHeap.push(down);
			}
			result.push_back(node.val);
		}
	}
	return result;
}

int main() {
	vector<int> vec(10, 0);
	for (int i = 0; i < 10; i++) {
		vec[i] = i;
	}
	vector<vector<int> > A;
	for (int i = 0; i < 10; i++) {
		vector<int> vec1 = vec;
		for (int j = 0; j < 10; j++) {
			vec1[j] += j;
		}
		A.push_back(vec1);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	int k = 10;
	
	vector<int> result = FirstKElement(A, k);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
