#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int sizeOfChar(char* str) {
  int i;
  if (str == NULL)
     return 0;
  for (i = 0;; i++) {
     if (str[i] == '\0')
       return i;
  }
}

void pre(char* dest, char* str, int n) {
  memcpy(dest, str, n);
  dest[n] = '\0';
}

void post(char* dest, char* str, int n) {
  int size = sizeOfChar(str);
  memcpy(dest, &str[size-n], n);
  dest[n] = '\0';
}
char* strStr(char* haystack, char* needle) {
  int size = sizeOfChar(needle);
  int hSize = sizeOfChar(haystack);
  if (size == 0 || hSize == 0)
      return NULL;
  if (size > hSize) 
     return NULL;
     
  if (hSize == size) {
    if (strcmp(haystack, needle) == 0) 
        return &haystack[0];
    else 
      return NULL;
  }
  vector<int> PMT(size, 0); // Partial Match Table
  int i;
  int j;
  bool match = false;
  for (i = 1; i <=size; i++) {
    char buff[i+1];
    memcpy(buff, needle, i);
    buff[i] = '\0';
    int len = 0;
    for (j = i-1; j > 0; j--) {
      char prefix[j+1];
      char postfix[j+1];
      pre(prefix, buff, j);
      post(postfix, buff, j);
      if (strcmp(prefix, postfix) == 0) {
        len = j;
        break;
      }
    }
    PMT[i-1] = len;
  }
  /* KMP matching. */
  for (i = 0; i <= hSize - size; i++) {
    
    for (j = 0; j < size; j++) {
      if (haystack[i+j] != needle[j])
        break;      
    }
    if (j == size) {
      return &haystack[i];
    }
    else {
      i = i + (j - PMT[j-1]);
    }
    
  }
  return NULL;
}

int main() {
  char haystack[] = "mississippi";
  char needle[] = "issi";
  char* pch = strStr(haystack, needle);
  strncpy(pch, "X", 1);
  std::cout << haystack << std::endl;
  return 0;
}
