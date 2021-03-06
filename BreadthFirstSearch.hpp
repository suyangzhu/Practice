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
TreeNode<T>* BFS(T key, TreeNode<T>* root) {
  Queue<TreeNode<T>* >  queue;
  if (root) {
    queue.enqueue(root);
  }
  while (!queue.isEmpty()) {
    // If this node has been visited. return.
    TreeNode<T>* node = queue.dequeue();
    if (node->getVal() == key) {
      return node;
    } else {    /**< Insert all its children into the queue. */
      if (node->left)
        queue.enqueue(node->left);
      if (node->right)
        queue.enqueue(node->right);
    }
  }
  return NULL;
}

template<typename T> 
void BFS_path(TreeNode<T>* root) {
  Queue<TreeNode<T>* > queue;
  if (root) {
    queue.enqueue(root);
  }
  while(!queue.isEmpty()) {
    TreeNode<T>* node = queue.dequeue();
    std::cout << node->getVal() << " ";
    if (node->left)
      queue.enqueue(node->left);
    if (node->right)
      queue.enqueue(node->right);
  }
}










