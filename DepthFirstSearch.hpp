#include "BinaryTree.hpp"
#include "stackqueue.hpp"

// Breadth_First_Search
// 1-> if root is not empty. Enqueue root.
// 2-> if queue is empty return NOT_FOUND. If queue is
// not empty. Dequeue node from queue. If node.val == key
// return node. otherwise enqueue all of node.successor.
// 3-> repeat step 2 until empty or key found.
// 4-> destroy queue

template<typename T>
TreeNode<T>* DFS(T key, TreeNode<T>* root) {
  Stack<TreeNode<T>* > stack;
  stack.push(root);
  TreeNode<T>* current;
  while (!stack.isEmpty()) {
    current = stack.pop();
    if (current->getVal() == key)
      return current;
    if (current->left) 
      stack.push(current->left);
    if (current->right)
      stack.push(current->right);
  }
  return NULL;
}

template<typename T>
TreeNode<T>* DFS_path(TreeNode<T>* root) {
  Stack<TreeNode<T>* > stack;
  stack.push(root);
  TreeNode<T>* current;
  while (!stack.isEmpty()) {
    current = stack.pop();
    std::cout << current->getVal() << "  ";
    if (current->left)  {
      stack.push(current->left);
    }
    if (current->right) {
      stack.push(current->right);
    }
  }
  return NULL;
}
