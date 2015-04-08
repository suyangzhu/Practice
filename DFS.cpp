// This test case is for the test of
// the DFS. I forget the algorithm??


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

class Node {
	public: 
		Node() {val = 0;}
		~Node() {}
		int GetVal() {
			return val;
		}
			
	private:
		int val;
		vector<Node *> child;
};

class DFS {
	public:
	private:
		map<Node *, bool> nodeMap;	
};

int main () {
	return 0;
}
