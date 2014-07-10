

// Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
// only one call to strstr (eg, “waterbottle” is a rotation of “erbottlewat”).
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
// The first solution is wrong cause it is not "rotation."
bool isRotation(char* str1, char* str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  int i, j;
  if (len1 != len2) 
    return false;
  j = len2;
  for (i = 0; i < len1; i++) {
    if (str1[i] !=  str2[--j])
      return false;
  }
  return true;
}
// concatenate the first string and see if the second string 
// is a substring of the concatenation of two strings.
bool isRotation1(char* str1, char* str2) {
  if (strlen(str1) != strlen(str2)) 
    return false;
  
  if (strstr(strcat(str1, str1), str2)) 
    return true;

  return false;
}

int main () {
  char a[10] = "abcdefg";
  char b[10] = "fgabcde";
  if (isRotation1(a, b))
    std::cout << "yes" << std::endl; 
  return 0;
}
