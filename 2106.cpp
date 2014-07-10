
//Code: Reverse C-Style String. (C-String means that “abcd\n” is actually represented
//as six characters)


#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>

void reverse(char* str) {
  char* end = str;
  char tmp;
  if (str) {
    while (*end) 
      end++;
    end--;
    while (str < end) {
      tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
  }
}

int main() {
  char str[10] = "abc";
  int length = strlen(str) ;

  std::cout << "String: " << str << " length is " 
  << length << std::endl;
  reverse(str);
  std::cout << "String: " << str << " length is "
  << length << std::endl;
  return 0;
}
