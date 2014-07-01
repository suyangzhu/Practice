#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_search(int*, int, int, const int);
void print(int*, int, int);

/** 1. binary search in a array for key. */
int binary_search(int* array, int begin, int end, const int key) {
  // if empty array  return
  if (end < begin) 
    return -1;
  else {
    // three way comparison
    int mid = (begin + end) / 2;
    if (key < array[mid]) 
      // key is in lower subset.
      return binary_search(array, begin, mid - 1, key);
    else if(key > array[mid])
      // key is in upper subset.
      return binary_search(array, mid + 1, end, key);
    else 
      return mid;
  }
}

void print(int* array, int begin, int end) {
  int i;
  for (i = begin; i < end; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int i;
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int index[10];
  memset (index, 0, 10);
  print(arr, 0, 10);
  print(index, 0, 10);
  
  for (i  = 0; i < 8; i++) {
    index[i] = binary_search(arr, 0, 10, i);
  }
  index[8] = binary_search(arr, 0, 10, 20);
  index[9] = binary_search(arr, 0, 10, -2);

  int b = binary_search(arr, 1, 1, 1);
  printf("b=%d\n", b);
   
  print(index, 0, 10);
}
