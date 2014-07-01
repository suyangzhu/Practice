#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Node {
  public:
  Node(bool maker=false) : mMaker(maker), mContent(' ') {}
  ~Node() {}
  char getContent() { return mContent; }
  bool getMaker() { return mMaker; }
  void setMaker() { mMaker = true;}
  void setContent(char c) { mContent = c; }
  Node* hasChild (char c); 
  void appendChild(Node* node) { children.push_back(node); }
  private:
  bool mMaker;
  char mContent;
  std::vector<Node* > children;
};

Node* Node::hasChild (char c) {
  int i;
  for (i = 0; i < children.size(); i++) {
    if ( children.at(i)->getContent() == c )
      return children.at(i); 
  }
  return NULL;
}

class Trie {
  public:
  Trie() {root = new Node();}
  ~Trie() {}

  void addWord(std::string s) ;
  bool searchWord(std::string s);
  private:
  Node* root;
};

void Trie::addWord (std::string s) {
  int i;
  Node* current = root;

  if (!(s.length() > 0)) 
    return;
  for (i = 0; i < s.length(); i++) {
    Node* child = current->hasChild(s[i]);
    if (child) {
      current = child;
    } else { 
      Node* tmp = new Node();
      tmp->setContent(s[i]);
      current->appendChild(tmp);
      current =  tmp;
    }
  }
  current->setMaker();
}

bool Trie::searchWord(std::string s) {
  int i;
  Node* current = root;
  for (i = 0; i < s.length(); i++) {
    Node* tmp = current->hasChild(s[i]);
    if (!tmp) {
      return false;
    }
    current = tmp;
  }
  if (current->getMaker())
    return true;
  return false;
}

int main() {
  Trie trie;
  trie.addWord("Hello");
  if (trie.searchWord("Hello"))
    std::cout << "Hello inside" << std::endl;
  if (trie.searchWord("Hell"))
    std::cout << "Hell inside" << std::endl;
  trie.addWord("Helloa");
  if (trie.searchWord("Helloa"))
    std::cout << "Helloa" << std::endl;
}















