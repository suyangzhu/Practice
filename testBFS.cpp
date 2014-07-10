#include "BreadthFirstSearch.hpp"

int main() {
  TreeNode<int>* root = new TreeNode<int>;
  int i, num;
  for (i = 0; i < 10; i++) {
    root->insert(i);
  }

  std::cout << "input value you would like to find" << std::endl;
  std::cin >> num;
  TreeNode<int>* node = BFS(num,root);
  if (node) {
    std::cout << "The node you are looking for has value " 
    << node->getVal() << std::endl;
  } else {
    std::cout << "Not found " << std::endl;
  }
  return 0;
}
