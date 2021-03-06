#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <assert.h>
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

  T top() {
    return stack.back().getVal();
  }

  bool isEmpty() {
    return stack.empty();
  }


  int size() { return stack.size() ; }
  private:
  std::vector<Node<T> > stack;
};

template<typename T>
class MinStack {
  public:
  MinStack() {}
  ~MinStack() {}
  void push(T ele) {
    eleStack.push(ele);
    if ( minStack.isEmpty() || ele <= minStack.top()) {
      minStack.push(ele);
    }
  }

  T pop() {
    T ele = eleStack.pop();
    if (!minStack.isEmpty() && ele == minStack.top()) {
      minStack.pop();
    }
    return ele;
  }

  T top() {
    return eleStack.top();
  }

  bool empty() {
    return eleStack.isEmpty();
  }

  T getMinVal() {
    if (!minStack.isEmpty()) {
      return minStack.top();
    } else {
      return -1;
    }
  }
  private:
  Stack<T> eleStack;
  Stack<T> minStack;
};

template<typename T> 
class Queue {
  public:
  Queue() {}
  ~Queue() {}
  void enqueue(T ele) {
    stack1.push(ele);
  }

  bool isEmpty() {
    return stack1.isEmpty();
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
/** Sort stack in ascending order using two stacks. O(N) complexity. */
template<typename T> 
void ascend (Stack<T>* src, Stack<T>* dest) {
  while (!src->isEmpty()) {
    T ele = src->pop();
    while (!dest->isEmpty() && dest->top() > ele) {
      src->push(dest->pop());
    }
    dest->push(ele);
  }
}

/** Sort stack in descending order using two stacks. O(N) complexity. */
template<typename T> 
void descend(Stack<T>* src, Stack<T>* dest) {
  while(!src->isEmpty()) {
    T ele = src->pop();
    while (!dest->isEmpty() && dest->top() < ele) {
      src->push(dest->pop());
    }
    dest->push(ele);
  }
}


