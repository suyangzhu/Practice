#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

int main () {
  std::string str = "Hello world" ;
  for (std::string::iterator it = str.begin(); it != str.end(); it++) {
    char t = *it;
    std::cout << t << std::endl;
  }
  
  return 0;
}


