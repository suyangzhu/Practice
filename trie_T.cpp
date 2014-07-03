#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class Node {
  public:
  Node() {
    mContent = ' ';
    mMaker = false;
  }

  ~Node() {}
  char getContent() {
    return mContent;
  }

  bool getMaker() {
    return mMaker;
  }

  void setMaker() {
    mMaker = true;
  }

  void setContent(char content) {
    mContent = content;
  }
  
  void addChildren(char content) {
    Node* node = new Node;
    node->setContent(content);
    mChildren.push_back(node);
  }

  Node* hasChild (char content) {
    int i;
    for (i = 0; i < mChildren.size(); i++) {
      Node* nodePtr = mChildren.at(i);
      if (nodePtr->getContent() == content)
        return nodePtr;
    }
    return NULL;
  }



  private:
  char mContent;
  bool mMaker;
  vector<Node*> mChildren;
};
