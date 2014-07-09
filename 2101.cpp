#include <cstdio>
#include <cstdlib>
#include <iostream>

int StringLens(char* str, int length) {
  int i;
  int spaceCnt = 0;
  for (i = 0; i < length; i++) {
    if (str[i] == ' ') 
      spaceCnt++;
  }
  return (2*spaceCnt + length);
}

void replace(char* src, char* dest, int srcLen, int destLen) {
  int i, j;
  j = 0;
  for (i = 0; i < srcLen; i++) {
    if (src[i] != ' ') {
      dest[j++] = src[i];
    } else {
      dest[j++] = '%';
      dest[j++] = '2';
      dest[j++] = '0';
    }
  }
  dest[j] = '\0'; 
}

int main() {
  char name[20] = "hello world m m";
  int len = StringLens(name, 20);
  char newName[len];
  replace(name, newName, 20, len);
  std::cout << "original string : ";
  std::cout << name << std::endl;
  std::cout << "new string: ";
  std::cout << newName << std::endl;
  return 0;
}
