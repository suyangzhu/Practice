#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

bool checkAnagram(std::string& str1, std::string& str2) {
  int i, len;
  if (str1.length() != str2.length())
    return false;
  len = str1.length();
  for (i = 0; i < len; i++) {
    if (str1[i] != str2[len - i - 1])  {
      return false;
    }
  }
  return true;
}

int main() {
  std::string str1 = "abcde";
  std::string str2 = "edcba";
  std::string str3 = "eddba";
  if (checkAnagram(str1, str2))
    std::cout << str1 << " and " << str2 << " are anagram" << std::endl;

  if (!checkAnagram(str1, str3))
    std::cout << str1 << " and " << str3 << " are not anagram" << std::endl;
  return 0;
}
