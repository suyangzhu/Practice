#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

class Node {
  public:
  Node(bool maker=false) : mMaker(maker), mContent(' ') {}
  ~Node() {}

  char content() { return mContent; }
  void setContent(char c) { mContent = c; }
  bool wordMaker() { return mMaker; }
  void setWordMaker() { mMaker = true; }
  Node* findChild(char c) ;
  void appendChild(Node* child) { mChildren.push_back(child); }

  private:
  bool mMaker;
  char mContent;
  std::vector<Node* > mChildren;
};

Node* Node::findChild(char c) {
  int i;
  for (i = 0; i < mChildren.size(); i++) {
    Node* tmp = mChildren.at(i);
    if (tmp->content() == c) 
      return tmp;
  }
  return NULL;
}

class Trie {
  public:
  Trie() { root = new Node(); } 
  ~Trie() {} 
  void addWord(std::string s);
  bool searchWord(std::string s);
  void deleteWord(std::string s);
  
  private:
  Node* root; 
};

void Trie::addWord(std::string s) {
  int i; 
  Node* current =  root;
  if (s.length() == 0) {
    current->setWordMaker();
    return;
  }
  for (i = 0; i < s.length(); i++) {
    Node* child = current->findChild(s[i]);
    if (child) {
      current = child;
    }
    else {
      Node* tmp = new Node();
      tmp->setContent(s[i]);
      current->appendChild(tmp);
      current = tmp;
    }
  }
  current->setWordMaker();
}

bool Trie::searchWord(std::string s) {
  int i;
  Node* current = root;
  for (i = 0; i < s.length(); i++) {
    Node* tmp = current->findChild(s[i]);
    if (!tmp)
      return false;
    current = tmp;
  }
  return current->wordMaker();
}



int main() {
  Trie* trie = new Trie();
  trie->addWord("Hello");
  trie->addWord("World");
  if (trie->searchWord("Hell")) 
    std::cout << "Hell is a world" << std::endl;
  return 0;
}
