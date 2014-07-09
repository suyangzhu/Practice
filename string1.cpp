#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

void replace(char src, char dest, std::string& str) {
  int i = 0;
  for (std::string::iterator it = str.begin(); 
       it != str.end();
       it++) {
    if (*it == src) {
//      str.erase(it);
      str.insert(i, "0");
      it++;
      
    }
    i++;
  }
}

int main() {
  
  std::string str("hello world mama mia");
  std::cout << str << std::endl;
  replace(' ', ' ', str);
  std::cout << str << std::endl;
  return 0;
}
