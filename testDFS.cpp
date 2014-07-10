#include "DepthFirstSearch.hpp"

int main() {
  TreeNode<int>* root = new TreeNode<int>;
  int i, num;
  root->insert(5);
  root->insert(3);
  root->insert(1);
  root->insert(9);
  root->insert(6);
  root->insert(2);
  root->insert(8);
  root->insert(4);
  root->insert(7);
  root->insert(0);
  std::cout << "DFS path: " << std::endl;
  DFS_path(root);
  std::cout << std::endl;

  std::cout << "input value you would like to find" << std::endl;
  std::cin >> num;
  TreeNode<int>* node = DFS(num,root);
  if (node) {
    std::cout << "The node you are looking for has value " 
    << node->getVal() << std::endl;
  } else {
    std::cout << "Not found " << std::endl;
  }
  return 0;
}

