#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "This is a simple string";
  char * pch;
  char str1[] = "aaaaaa";
  pch = strstr(str, "simple");
  strncpy(pch, str1, 3);
  printf("%s\n", str);
  return 0;
}
