#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;

class ListNode {
	public:
		int val;
		ListNode* next;
		ListNode(int n) : val(n), next(NULL) {}
};

ListNode* remove(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	unordered_set<int> hashT;
	ListNode* ptr1 = dummy;
	ListNode* ptr2 = ptr1->next;
	while (ptr1) {
		ptr2 = ptr1->next;
		while (ptr2 && hashT.count(ptr2->val) > 0) ptr2 = ptr2->next;
		if (ptr2) hashT.insert(ptr2->val);
		ptr1->next = ptr2;
		ptr1 = ptr1->next;
	}
	return dummy->next;
}

ListNode* 

void Print(ListNode* head) {
	while (head) {
		std::cout << head->val << std::endl;
		head = head->next;
	}
}

int main() {
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(3);
	ListNode* p3 = new ListNode(1);
	ListNode* p4 = new ListNode(3);
	ListNode* p5 = new ListNode(9);
	ListNode* p6 = new ListNode(6);
	ListNode* p7 = new ListNode(1);
	ListNode* p8 = new ListNode(3);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = p8;
	
	Print(p1);
	ListNode* head = remove(p1);
	Print(head);
	return 0;
}
