#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
	public:
	int val;
	Node* next;
	Node(int n):val(n),next(NULL) {}
	~Node() {delete(next);}
};


void foo(Node*& ptr, Node*& p2, Node*& p3) {
	Node* p1 = new Node(1);
	
	p1->next = p2;
	p2->next = p3;
	ptr = p2;
}
int main() {
	Node* ptr;
	Node* p2 = new Node(2);
	Node* p3 = new Node(3);
	foo(ptr, p2, p3);
	std::cout << ptr->val << std::endl;
}
