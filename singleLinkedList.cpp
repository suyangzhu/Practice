#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

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



	private:
		Node<T> *head;
		Node<T> *tail;
		int length;
	
	
};

int main() {
	Node<int> n0(0);
	Node<int> n1(1);
	Node<int> n2(1);
	Node<int> n3(3);

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
	
	return 0;
}
