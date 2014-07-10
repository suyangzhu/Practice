#include "stackqueue.hpp"
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

void testMinStack() {
  int i;
  MinStack<int>* minStack = new MinStack<int>;
  minStack->push(5);
  minStack->push(3);
  minStack->push(4);
  std::cout << minStack->getMinVal() << std::endl;
  minStack->pop();
  std::cout << minStack->getMinVal() << std::endl;
  minStack->pop();
  std::cout << minStack->getMinVal() << std::endl;
  minStack->pop();
  std::cout << minStack->getMinVal() << std::endl;
}

void testAscend() {
  Stack<int>* src = new Stack<int>;
  Stack<int>* dest =  new Stack<int>;
  int i;
  for (i = 0; i < 1000; i++) 
    src->push(i);
  ascend(src, dest);
  i = 1000;
  while (!dest->isEmpty()) {
    assert(--i == dest->pop());
  }
}

void testDescend() {
  Stack<int>* src = new Stack<int>;
  Stack<int>* dest = new Stack<int>;

  int i;
  for (i = 100; i > 0; i-- ) {
    src->push(i);
  }
  i = 0;
  descend(src, dest);
  while (!dest->isEmpty()) {
    assert(++i == dest->pop());
  }
}

int main() {
  std::cout << "Test Stack ...." << std::endl;
  testStack() ;
  std::cout << "DONE" << std::endl;

  std::cout << "Test Queue ...." << std::endl;
  testQueue() ;
  std::cout << "DONE" << std::endl;

  std::cout << "Test MinStack ...." << std::endl;
  testMinStack();
  std::cout << "DONE" << std::endl;

  std::cout << "Test Ascend() ...." << std::endl;
  testAscend() ;
  std::cout << "DONE" << std::endl;

  std::cout << "Test Descend() ...." << std::endl;
  testDescend() ;
  std::cout << "DONE" << std::endl;
  return 0;
}
