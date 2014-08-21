#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
bool isOp(char c) {
  if (c == '+' || c == '-' ||
      c == '*' || c == '/' ||
      c == 'i' || c == 't' ||
      c == '(' || c == ')')
    return true;
  else 
    return false;
}

int priority(char c) {
  if (c == '+' || c == '-') 
    return 1;
  else if (c == '*' || c == '/') 
    return 2;
  else if (c == 'i' || c == 't')
    return 3;
  else if (c == '(' || c == ')')
    return 4;
  return 0; 
}

void ipn2rpn(std::string& str) {
  std::stack<char> opStack;
  int size = str.length();
  int i;
  for (i = 0; i < size; i++) {
    if (!isOp(str[i])) {
      std::cout << str[i];
      continue;
    } else {
      if (str[i] == 'i') {
        i+=2;
        str[i] = 'i';
      } 
      if (str[i] == 't') {
        i+=4;
        str[i] = 't';
      }
      if (str[i] == ')') {
        while (!opStack.empty() && opStack.top() != '(') {
        std::cout << opStack.top();
        opStack.pop();
        }
        opStack.pop();
      } else
      if (opStack.empty()       || 
          opStack.top() == '('  ||
          priority(str[i]) > priority(opStack.top())) {
        opStack.push(str[i]);
      } else {
        while (!opStack.empty() && opStack.top() != '(' &&
               priority(str[i]) <= priority(opStack.top())) {
          std::cout << opStack.top();
          opStack.pop();
        }
        opStack.push(str[i]);
      }
    }
  }
  while (!opStack.empty()) {
    std::cout << opStack.top();
    opStack.pop();
  }
  std::cout << std::endl;
}

int main() {
  std::string str;
  std::cout << "Input expression: " << std::endl;
  std::getline(std::cin, str);
  std::string str2 = "";
  for (std::string::iterator it = str.begin(); it != str.end(); it++) {
    if (*it != ' ') 
      str2 += *it;
  }
  ipn2rpn(str2);
  return 0;
}

