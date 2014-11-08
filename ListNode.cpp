#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <stack>
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

ListNode* Remove2(ListNode* head) {
	if (!head || !head->next) return head;
	
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* ptr = head;
	ListNode* ptr1 = head;
	ListNode* ptr2 = NULL;
	while(ptr) {
		ptr1 = ptr;
		int value = ptr1->val;
		while (ptr1) {
			ptr2 = ptr1->next;
			while (ptr2 && ptr2->val == value) ptr2 = ptr2->next;
			ptr1->next = ptr2;
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
	return head;
}

void Print(ListNode* head) {
	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

ListNode* LastKth(ListNode* head, int k) {
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* ptr1 = dummy;
	ListNode* ptr2 = ptr1;
	while (k) {
		ptr2 = ptr2->next;
		k--;
	}	
	if (k != 0) return NULL;
	while (ptr2) {
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;
	}
	return ptr1;
}

bool IsPalindrome(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	stack<int> s;
	while (fast && fast->next) {
		s.push(slow->val);
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast) { // odd
		s.pop();
		slow = slow->next;
	}
	while (slow) {
		if (slow->val != s.top()) return false;
		slow = slow->next;
		s.pop();
	}
	return true;
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

	std::cout << "Last 3th " << LastKth(p1, 3)->val << std::endl;
	Print(p1);
	ListNode* head = Remove2(p1);
	Print(head);
	return 0;
}
