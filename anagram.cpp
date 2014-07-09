#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

bool checkAnagram(std::string& str1, std::string& str2) {
//  return str1.sort() == str2.sort();
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  return str1 == str2;
}

int main() {
  std::string str1 = "abcde";
  std::string str2 = "deabc";
  sort(str2.begin(), str2.end());
  std::cout << str2 << std::endl;
  if (checkAnagram(str1, str2))
    std::cout << "yes" << std::endl;
  return 0;
}
