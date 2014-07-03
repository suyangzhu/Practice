#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
class Node {
  public:
  /** Constructor for node. Root is "empty" node. */
  Node() {
    mContent = ' ';
    mMaker = false;
  }

  ~Node() {}
  /** Return the element in this node. */
  char getContent() {
    return mContent;
  }
  
  /** Return whether this node makes a word. */
  bool getMaker() {
    return mMaker;
  }

  /** This node makes a word. */
  void setMaker() {
    mMaker = true;
  }

  /** Set the content for this word. */
  void setContent(char content) {
    mContent = content;
  }
 
  /** Add new nodes. */ 
  Node* addChildren(char content) {
    Node* node = new Node;
    node->setContent(content);
    mChildren.push_back(node);
    return node;
  }

  /** Test existence of content. */
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
  T mContent;   /**< Node content. */
  bool mMaker;  /**< Word boolean. */
  std::vector<Node*> mChildren;  /**< Children list. */
};
template <typename T, typename U>
class Trie {
  public: 
  Trie() { root = new Node<U>; }
  ~Trie() {}
  /** Add word to trie. */
  void addWord (T str) {
    Node<U>* current = root;
    Node<U>* nodePtr;
    int i;
    if (!(str.length() > 0)) 
      return ;

    for ( i = 0; i < str.length(); i++) {
      nodePtr = current->hasChild(str[i]);
      // If this char found among this nodes' children.
      // Shift to next node.
      if (nodePtr) {
        current = nodePtr;
      } else {
        current = current->addChildren(str[i]);     
      }
    }
    current->setMaker();
  } 
  /** Search word in trie. */
  bool searchWord (T str) {
    Node<U>* current = root;
    Node<U>* nodePtr;
    int i;
    if (!(str.length() > 0))
      return false;
    for (i = 0; i < str.length(); i++) {
      nodePtr = current->hasChild(str[i]);
      if (!nodePtr) 
        return false;
      else 
        current = nodePtr;
    }

    return (current->getMaker());
   }

  /** Search substring in trie. */
  bool hasSubString (T str) {
    Node<U>* current = root;
    Node<U>* nodePtr;
    int i;
    if (!(str.length() > 0))
      return false;
    for (i = 0; i < str.length(); i++) {
      nodePtr = current->hasChild(str[i]);
      if (!nodePtr) 
        return false;
      else 
        current = nodePtr;
    }

    return true;
   }
  private:
  Node<U>* root;  /**< Trie root. */

};

template<typename T, typename U> 
class SuffixTree {
  public:
  SuffixTree() { trie = new Trie<T, U>; }
  ~SuffixTree() {}

  void createSuffix(T str) {
    int i;
    int len = str.length();
    T sub_str;
    str += "$";
    
    for (i = 0; i < len; i++) {
      sub_str = str.substr(i,len - i);
      trie->addWord(sub_str); 
    }
  }

  bool hasSubString(T str) {
    return trie->hasSubString(str);  
  }

  private:
  Trie<T, U> * trie;
};

bool  testTrie () {
  Trie<std::string,char> trie;
  trie.addWord("Hello");
  trie.addWord("HelloolleH");
  trie.addWord("World");
  trie.addWord("ADA");
  if (!(trie.searchWord("Hello") && 
      trie.searchWord("World") &&
      trie.searchWord("ADA")   &&
      trie.searchWord("HelloolleH") )) 
    return false;

  if (trie.searchWord("Hell") ||
      trie.searchWord("orld") ||
      trie.searchWord("DA")) 
    return false;
  return true;
}

bool testSuffixTree() {
  SuffixTree<std::string, char> suffixTree;
  suffixTree.createSuffix("suyangzhu");
  if (!(suffixTree.hasSubString("su")   &&
        suffixTree.hasSubString("yang") &&
        suffixTree.hasSubString("zhu"))) 
    return false;
  if (suffixTree.hasSubString("en")   ||
      suffixTree.hasSubString("zha")  ||
      suffixTree.hasSubString("sua"))
    return false;
  return true;
}

int main(int argc, char** argv) {
  std::cout << "Test Trie ....";
  if (testTrie()) 
    std::cout << "DONE" << std::endl;
  else 
    std::cout << "FAIL" << std::endl;

  std::cout << "Test SuffixTree ....";
  if (testSuffixTree()) 
    std::cout << "DONE" << std::endl;
  else 
    std::cout << "FAIL" << std::endl;
  return 0;
}
