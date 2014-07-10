#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

bool isUnique(std::string str) {
  bool uniqe[256];
  int i;

  for (i = 0; i < 256; i++) 
    uniqe[i] = false;
  
  for (i = 0; i < str.length(); i++) {
    if (uniqe[str[i]])
      return false;
    uniqe[str[i]] = true;
  }

  return true;
}

int main() {
  std::string str = "abbcde";
  if (isUnique(str))
    std::cout << "every uniqe" << std::endl;
  else 
    std::cout << "not every uniqe" << std::endl;
  return 0;
}
