// Runhe Tian Coding Practice

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;
struct Node {
  Node* ptr1;
  Node* ptr2;
};
typedef map<Node*, Node*> NodeMap;


Node* CopyRecursive(Node* cur, NodeMap& nodeMap) {
  if(cur == NULL)  {
    cout << "1" << endl;
    return cur;
  }
  NodeMap::iterator it = nodeMap.find(cur);
  if (it != nodeMap.end()) {
    cout << "2" << endl;
    return it->second;
  } else {
    cout << "3" << endl;
    Node* node = new Node;
    nodeMap[cur] = node;
    node->ptr1 = CopyRecursive (cur->ptr1, nodeMap);
    node->ptr2 = CopyRecursive (cur->ptr2, nodeMap);
    return node;
  }
}

Node* CopyStructure(Node* root) {
  NodeMap nodeMap;
  return CopyRecursive(root, nodeMap);
}

int main() {
  Node *ptr = new Node;
  CopyStructure(ptr);
  return 0;
}
