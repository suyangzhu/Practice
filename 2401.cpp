#include <iostream>
#include <cstdio>
#include <cstdlib>
template<typename T>
struct Node {
  T val;
  struct Node* left;
  struct Node* right;
};

template<typename T>
Node<T>* createBinaryTree (T* array, int begin, int end) {
  if (begin < end)
    return NULL; 
  Node<T>* tree = (Node<T>*) malloc (sizeof (Node<T>));
  int mid = (begin + end) / 2;
  tree->val = array[mid];
  tree->left = createBinaryTree(array, begin, mid - 1);
  tree->right = createBinaryTree(array, mid + 1, end);
  
  return tree;
}

template<typename T> 
void print(Node<T>* tree) {
  std::cout << "in the tree" << std::endl;
  if (tree == NULL)  {
    std::cout << "NULL" << std::endl;
    return ;
  }
  print(tree->left);
  std::cout << tree->val << std::endl;
  print(tree->right);
  return;
}


int main() {
  int array[10] = {0,1,2,3,4,5,6,7,8,9};
  Node<int>* tree = createBinaryTree(array, 0, 9);
  print(tree);
  return 0;
}
