#include <cstdio>
#include <cstdlib>
#include <iostream>

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
//  template<typename T>
  friend std::ostream& operator<< (std::ostream& os, const Node<T>& node){
    os << node.val << node.val << std::endl; 
  }

  private:
  T val;
  Node *next;
};

class LinkedList {
};

int main() {
  return 0;
}
