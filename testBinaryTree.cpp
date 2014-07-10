#include "BinaryTree.hpp"

int main(int argc, char** argv) {
  BinaryTree<int>* bst = new BinaryTree<int>;
  int i, num;
  for (i = 0; i < 10; i++) {
    std::cout << "input: " << std::endl;
    std::cin >> num;
    bst->insertElement(num);
  }
  bst->print();
  std::cout << "-----------" << std::endl;
  Node<int> node = bst->searchKey(5);
  std::cout << node.getVal() << std::endl;

  return 0;
}
