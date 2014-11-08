#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int idx;
	string id;
};
bool cmp(Node* i, Node* j) {return i->idx>j->idx;}
int main() {
	vector<int> vec = {1, 2, -1, -2, 0};
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	vector<Node*> vec2;
	for (int i = 0; i < vec.size(); i++) {
		Node* nd = new Node();;
		nd->idx = vec[i];
		nd->id = "a";
		vec2.push_back(nd);
	}
	sort(vec2.begin(), vec2.end(), cmp);
	for (int i = 0; i < vec2.size(); i++) {
		std::cout << vec2[i]->idx << " ";
	}
	std::cout << std::endl;

}
