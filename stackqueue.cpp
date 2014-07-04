#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T>
class Node {
  public:
  Node() {}
  ~Node() {}
  T getVal() { return mVal; }
  T getMin() { return mMin; }
  void set(T val, T min) { mVal = val; mMin = min; } 
  private:
  T mVal;
  T mMin;
};

template<typename T>
class Stack {
  public:
  Stack() {}
  ~Stack() { stack.clear(); } 
  void push(T ele) {
    Node<T> node;
    if (size() == 0)  {
      node.set(ele, ele);
    } else  {
      node.set(ele, ele < topMin() ? ele: topMin());
    }
    stack.push_back(node);
  }

  T pop() {
    Node<T> ele = stack.back();
    stack.pop_back();
    return ele.getVal();
  }

  T topMin() {
    return stack.back().getMin();
  }


  int size() { return stack.size() ; }
  private:
  std::vector<Node<T> > stack;
};

template<typename T> 
class Queue {
  public:
  Queue() {}
  ~Queue() {}
  void enqueue(T ele) {
    stack1.push(ele);
  }

  T dequeue() {
    while (stack1.size() ) {
      T ele = stack1.pop();
      stack2.push(ele);
    }
    T val = stack2.pop();     /**< reverse's reverse is in-order. */
    // Put the elements back into stack1. This is important.
    while (stack2.size()) { 
      T ele = stack2.pop();
      stack1.push(ele);
    }
    return val;
  }
  private:
  Stack<T> stack1;
  Stack<T> stack2;
};

void testStack () {
  Stack<int> *s = new Stack<int>();
  int i;
  for (i = 0; i < 10; i++) {
    s->push(i);
  }
  while(s->size()) {
    std::cout << s->pop()  << " top min = " << s->topMin() << std::endl;
  }
  return ;
}

void testQueue() {
  int i;
  Queue<int>* queue = new Queue<int>;
  for (i = 0; i < 10; i++) {
    queue->enqueue(i);
  }

  for (i = 0; i < 5; i++) {
    std::cout << queue->dequeue() << std::endl;
  }

  for (i = 0; i < 5; i++) {
    queue->enqueue(i+10);
  }

  for (i = 0; i < 10; i++) {
    std::cout << queue->dequeue() << std::endl;
  }
}

int main() {
  std::cout << "Test Stack ...." << std::endl;
  testStack() ;
  std::cout << "DONE" << std::endl;

  std::cout << "Test Queue ...." << std::endl;
  testQueue() ;
  std::cout << "DONE" << std::endl;
  return 0;
}
