#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
class Node {
	public:
	Node* left;
	Node* right;
	int leftSize;
	int val;
	Node(int val) : val(val), leftSize(0), left(NULL), right(NULL) {}
	~Node() { delete left; delete right; }
};

void Insert(int key, Node* &root) {
	if (!root) {
		root = new Node(key);
		return;
	} else 
	if (key < root->val) {
		Insert(key, root->left);
		root->leftSize++;
	} else
	if (key > root->val) {
		Insert(key, root->right);
	}
}

int GetRank(int key, const Node* root) {
	if (key== root->val) {
		return root->leftSize;
	} else 
	if (key < root->val) {
		return GetRank(key, root->left);
	} else {
		return root->leftSize + 1 + GetRank(key, root->right);
	}
}

void LevelTraverse(Node* root) {	
	if (!root) return;
	queue<Node*> nodeQ;

	nodeQ.push(root);
	while (!nodeQ.empty()) {
		int levelCnt = nodeQ.size();
		while (levelCnt) {
			Node* curr = nodeQ.front();
			std::cout << curr->val << " + " << curr->leftSize << "    ";
			nodeQ.pop();
			if (curr->left) nodeQ.push(curr->left);
			if (curr->right) nodeQ.push(curr->right);
			levelCnt--;	
		}
		std::cout << std::endl;
	}	
}

int main() {
	Node* root = NULL;
	Insert(20, root);
	Insert(15, root);
	Insert(25, root);
	Insert(10, root);
	Insert(23, root);
	Insert(5, root);
	Insert(13, root);
	Insert(24, root);
	LevelTraverse(root);
	std::cout << "rank 20: " <<  GetRank(20, root) << std::endl;
	std::cout << "rank 15: " <<  GetRank(15, root) << std::endl;
	std::cout << "rank 25: " <<  GetRank(25, root) << std::endl;
	std::cout << "rank 10: " <<  GetRank(10, root) << std::endl;
	std::cout << "rank 23: " <<  GetRank(23, root) << std::endl;
	std::cout << "rank 5: " <<  GetRank(5, root) << std::endl;
	std::cout << "rank 13: " <<  GetRank(13, root) << std::endl;
	std::cout << "rank 24: " <<  GetRank(24, root) << std::endl;
	return 0;
}
