#include "BinaryTree.hpp"

int main(int argc, char** argv) {
  BinaryTree<int>* bst = new BinaryTree<int>;
  int i, num;
  for (i = 0; i < 6; i++) {
    std::cout << "input: " << std::endl;
    std::cin >> num;
    bst->insertElement(num);
  }
  bst->print();
  std::cout << "-----------" << std::endl;
  TreeNode<int> node1 = bst->searchKey(1);
  TreeNode<int> node2 = bst->searchKey(4);
  TreeNode<int> node3 = bst->CommonAncestor(node1, node2);
  std::cout << "Node " << node1.getVal() << " and Node "
  << node2.getVal() << " least common ancestor is " 
  << node3.getVal() << std::endl;
  return 0;
}
