#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

template <typename T> 
class TreeNode {
  public:
  TreeNode() : val(), left(NULL), right(NULL), isSet(false) {}
  TreeNode(T val) : val(val), left(NULL), right(NULL), isSet(true){}
  ~TreeNode() { delete left; delete right; }
  TreeNode* getLeftChild() { return left; }
  TreeNode* getRightChild() { return right; }
  T getVal() { return val; }
  void setVal(T value) { val = value; }
  void insert(T value) {
    if (!isSet) {
      val = value;
      isSet = true;
    } else 
    if (value < getVal()){
      if (left) {
        left->insert(value);
      } else {
        left = new TreeNode<T>;
        left->insert(value);
      }
    } else {
      if(right) {
        right->insert(value);
      } else {
        right = new TreeNode<T>;
        right->insert(value);
      }
    }
  }
  void in_order() {
    if (!isSet) {
      return;
    }
    if (left != NULL)
      left->in_order();
    std::cout << val << std::endl;
    if (right != NULL)
      right->in_order();
  }

  TreeNode& search(T key) {
    if (!isSet || val == key)
      return *this;
    else 
    if (key < val) {
      return left->search(key);
    } else {
      return right->search(key);
    }
  }
  bool isChild(TreeNode& node) {
    if (this == NULL)
      return false;
    if (&node == this)
      return true;
    return left->isChild(node) ||
           right->isChild(node);
  }

  TreeNode& leastCommonAncestor(TreeNode& node1, TreeNode& node2) {
    if (left->isChild(node1) && 
        left->isChild(node2))
      return left->leastCommonAncestor(node1, node2);
    else if (right->isChild(node1) &&
             right->isChild(node2))
      return right->leastCommonAncestor(node1, node2);
    return *this;
  }

  TreeNode* left;
  TreeNode* right;
  private:
  T val;
  bool isSet;
};

template <typename T> 
class BinaryTree {
  public:
  BinaryTree() : nodeCnt(0) { root = new TreeNode<T>; }
  ~BinaryTree() { delete root; }
  void insertElement(T value) {
    root->insert(value);
  }
  void print() {
    root->in_order();
  }

  TreeNode<T>& searchKey(T key) {
    return root->search(key);
  }

  TreeNode<T>& CommonAncestor(TreeNode<T> node1, TreeNode<T> node2) {
   return root->leastCommonAncestor(node1, node2);
  }


  private:
  TreeNode<T>* root;
  int nodeCnt;
};
