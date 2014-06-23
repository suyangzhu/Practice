#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>

void print(std::vector<std::string>&);
 
void Dec2Bin(int num) {
  int x;
  x = num;
  std::string bit;
  std::vector<std::string> binary;
  while (x > 0) {
    bit = std::to_string(x % 2);
    binary.push_back(bit);
    x /= 2;
  }
  print(binary);
}

void print(std::vector<std::string>& strVec) {
  std::cout << "0x";
  for (std::vector<std::string>::iterator it = strVec.end() - 1; 
       it >= strVec.begin(); it--) {
    std::cout << *it;
  }
  std::cout << std::endl;
}

int main() {
  Dec2Bin(4);
  std::string tmp = std::to_string(5);
  std::vector<std::string> a;
  std::cout << tmp << std::endl;
  a.push_back(tmp);
  return 0;
}
