#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct List {
	int val;
	List * next;
	List(int val) : val(val), next(NULL){}
};

List * Reverse(List * head) {
	if (!head || !head->next) return head;
	List * ptr1 = head;
	List * ptr2 = head->next;
	head->next = NULL;
	while (ptr2) {
		List * ptr2Next = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2Next;
	}
	return ptr1;
}

void Print(const List * head) {
	if (!head) return;
	while (head) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

void Test() {
	List * ptr0 = new List(0);
	List * ptr1 = new List(1);
	List * ptr2 = new List(2);
	List * ptr3 = new List(3);
	ptr0->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;
	Print(ptr0);
	ptr0 = Reverse(ptr0);
	Print(ptr0);
}

int main() {
	Test();
	return 0;
}
