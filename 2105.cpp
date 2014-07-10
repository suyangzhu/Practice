
// Given a sorted array of strings which is interspersed
// with empty strings, write
// a method to find the start location of a given string.
//
// strings = ["", "", "ab", "", "bc", "", ""], find string "bc".
// Sorted array. consider binary search.
//


#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
/** return the index of string among string set with empty strings. */
int search (std::string* strs, std::string str, int begin, int end) {
  // this is not recursion.
  while (end >= begin) {
    // left shifting to skip empty strings on the right.
    while ((end >= begin )&& (strs[end].length() == 0)) 
      end--;
    // all elements in the string set are empty strings.
    if (end < begin) 
      return -1;
    int mid = (begin + end) / 2;
    // right shifting to skip empty strings on the left.  
    while (strs[mid].length() == 0) 
      mid++;
    if (strs[mid] == str) {
      return mid;
    } else
    if (strs[mid] < str) {
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
}
/** recursion for binary search. */
int search2(std::string* strs, std::string str, int begin, int end) {
  if (end < begin)
    return -1;
  while ((end >= begin) && (strs[end].length() == 0))
    end--;
  if (end < begin)
    return -1;
  int mid = (begin + end) / 2;
  // shifting mid cursor is very important.
  // otherwise the program will not be right.
  while (strs[mid].length() == 0) 
    mid++;
  if (strs[mid] < str) {
    return search2(strs, str, mid + 1, end);
  } else 
  if (strs[mid] > str) {
    return search2(strs, str, begin, mid - 1);
  } else {
    return mid;
  }
}

int main() {
  std::string strings[10] = {"", "ab", "", "bc", "cc", "", "de", "ef", "", ""};
  std::string str = "cc";
  
  std::cout << "ca index = " << search2(strings, str, 0, 9) << std::endl;
  return 0;
}









