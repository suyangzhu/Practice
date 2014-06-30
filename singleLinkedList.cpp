#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>

template<typename T>
class Node {
  public:
  Node(const T& val) : val(val), next(NULL) {}
  ~Node() {}
  void SetNextNode(const Node* ptr) {
    next = ptr;
  }

  Node<T>& operator= (const Node<T>& node) {
    if (this != &node) {
      val = node.val;
      next = node.next;
    }
    return *this;
  }

  friend std::ostream& operator<< (std::ostream& os, Node<T>& node){
	  os << node.val << std::endl;
  }

  T val;
  Node *next;
};

template <typename T> 
class HashTable {
	public:
	HashTable() {}
	~HashTable() {}
	void add(const T& val) {
		hashMap.insert(std::make_pair(val, val));
	}

	bool contain(const T& val) {
		
		if (hashMap.find(val) != hashMap.end()){
			return true;
		} else 
			return false;
//		if (it) 
//			return true;
//		return false;
	}
	private:
		std::map<T, T> hashMap;
};

template <typename T>
class Stack {
	public:
		Stack() {}
		~Stack() {}
		void push(const T& val) {
			myStack.push(val);
		}

		T pop() {
			T elem = myStack.top();
			myStack.pop();
			return elem;
		}
		bool empty() {
			return myStack.empty();
		}
	private:
		std::stack<T> myStack;
};

template <typename T>
class LinkedList {
	public:
		LinkedList() : head(NULL), tail(NULL), length(0) {}
		LinkedList(Node<T>& head) : head(&head), tail(&head) { length = 1;}
		/** Return the first node which has the value T. */
		Node<T>& getNode(const T& val) { 
			Node<T>* ptr = head;
			while (ptr) {
				if (ptr->val == val)
					return *ptr;
				ptr = ptr->next;
			}
			return *ptr;
		}

		/** Insert node into linked list. */
		void insertNode(Node<T>& node) {
			tail->next = &node;
			tail = &node;
			length++;
			return;	
		}

		void deleteNode(const T& val) {
			Node<T>* ptr1 = head;
			Node<T>* ptr2 = ptr1;
			if (length == 0) {
				return;
			}
			if (ptr1->val == val) {
				head = head->next;
//				free ((void *)ptr1);
//				delete *ptr1;
				ptr1 = ptr2 = head;
			}
			ptr1 = ptr1->next;
			while (ptr1) {
				if (ptr1->val == val) {
					ptr1 = ptr1->next;
					ptr2->next = ptr1;
				} else {
					ptr2 = ptr1;
					ptr1 = ptr1->next;
				}
			}
		}

		void printList() {
			Node<T>* ptr = head;
			while(ptr) {
				std::cout << *ptr ;
				ptr = ptr->next;
			}
		}

		T* nthToLast(const int n) {
			if (head == NULL) 
				return NULL;
			Node<T>* ptr1;
			Node<T>* ptr2;
			ptr1 = ptr2 = head;
			for (int i = 0; i < n - 1; i++) {
				if (ptr1 == NULL) 
					return NULL;
				ptr1 =  ptr1->next;
			}
			while (ptr1->next) {
				ptr2 = ptr2->next;
				ptr1 = ptr1->next;
			}
			return &ptr2->val;
		}

		void deleteDuplicates() {
			HashTable<T> *table = new HashTable<T>();
			Node<T>* ptr1; Node<T>* ptr2;
			ptr1 = head->next;
			ptr2 = head;
			table->add(ptr2->val);
			while (ptr1) {
				if (table->contain(ptr1->val)) {
					ptr1 =  ptr1->next;
					ptr2->next = ptr1;
				} else {
					table->add(ptr1->val);
					ptr2 =  ptr1;
					ptr1 = ptr1->next;	
				}
			}
		}
		// ptr1 moves 1 step 
		// ptr2 moves 2 steps
		// they will meet 2 nodes from start of loop
		Node<T>* findLoopNode() {
			Node<T>* slowPtr;
			Node<T>* fastPtr;
			slowPtr = fastPtr = head;
			while (true) {
				slowPtr = slowPtr->next;
				fastPtr = fastPtr->next->next;
				if (slowPtr == fastPtr) 
					break;
			}
			slowPtr = head;
			while (slowPtr != fastPtr) {
				slowPtr = slowPtr->next;
				fastPtr = fastPtr->next;
			}
			return slowPtr;
		}

		void deleteNode2(const T& key) {
			Node<T>* ptr = head;
			while(ptr) {
				if (ptr->val == key)
					break;
				ptr = ptr->next;
			}
			Node<T>* tmp = ptr->next;
			(*ptr) = (*tmp);
		}

		void add(const LinkedList& list1, const LinkedList& list2) {
			Stack<T> stack1;
			Stack<T> stack2;
			Stack<T> stack3;
			Node<T>* ptr1 = list1.head;
			Node<T>* ptr2 = list2.head;
			while (ptr1) {
				std::cout << "....";
				std::cout << ptr1->val << std::endl;
				stack1.push(ptr1->val);
				ptr1 = ptr1->next;
			}

			while(ptr2) {
				std::cout << ">>>>> " << ptr2->val << std::endl;
				stack2.push(ptr2->val);
				ptr2 = ptr2->next;
			}

			T carry = 0;
			while (!stack1.empty() && !stack2.empty()) {
				T sum = stack1.pop() + stack2.pop() + carry;
				std::cout << "T = " << sum << std::endl;
				stack3.push(sum);
				carry = sum / 10;
			} 

			while (!stack1.empty()) {
				T sum = stack1.pop() + carry;
				stack3.push(sum);
				carry = sum / 10;
			}
			while(!stack2.empty()) {
				T sum = stack2.pop() + carry;
				stack3.push(sum);
				carry = sum / 10;
			}

			
			std::cout << "++++" << std::endl;
			while(!stack3.empty()) {
				T value(stack3.pop());
				
				std::cout << value << std::endl;
//				Node<T> n(value);
//				insertNode(n);
			}
//			printList();
			
		}




//	private:
		Node<T> *head;
		Node<T> *tail;
		int length;
	
	
};

//template <typename T> 
//LinkedList<T>& Add(const LinkedList<T>& list1, const LinkedList<T>& list2){
//	Stack<T> stack1;
//	Stack<T> stack2;
	
//}

int main() {
	Node<int> n0(0);
	Node<int> n1(1);
	Node<int> n2(2);
	Node<int> n3(3);
	Node<int> n4(4);

	LinkedList<int> list(n0);
	list.insertNode(n1);
	list.insertNode(n2);
	list.insertNode(n3);
	list.printList();
	std::cout << "-----------" << std::endl;

	int a ;
	a = *list.nthToLast(2);
	std::cout << "2 th to end is " << \
		a << std::endl;
	std::cout << "Test remove duplicates" << std::endl;
	list.deleteDuplicates();
	list.printList();

	std::cout << "---------------" << std::endl;
	std::cout << "Test deleteNode2" << std::endl;
	list.deleteNode2(2);
	list.printList();

	std::cout << "Test stack adder" << std::endl;
	Node<int> n5(1);
	Node<int> n6(2);
	LinkedList<int> list1(n5);
	list1.insertNode(n6);
	std::cout << "list1" << std::endl;
	list1.printList();
	Node<int> n7(2);
	Node<int> n8(3);
	LinkedList<int> list2(n7);
	list2.insertNode(n8);
	std::cout << "list2" << std::endl;
	list2.printList();	

	LinkedList<int> list3;
	list3.add(list1, list2);
	return 0;
}
