#include <stdio.h>
#include <stdlib.h>

int findMax(int* list, int begin, int end) {
  int max = list[begin];
  int index = begin;
  int i;
  for (i = begin; i < end; i++) {
    if (max < list[i]) {
      max = list[i];
      index = i;
    }
  }
  return index;
}

void selection(int* list, int size) {
  int i;
  int index;
  int tmp;
  for (i = 0; i < size; i++) {
    index = findMax(list, i, size);
    tmp = list[i];
    list[i] = list[index];
    list[index] = tmp; 
  }
}

void print(int* list, int size) {
  int i; 
  for(i = 0; i < size; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

int main() {
  int list[10] = {2, 1, 0, 7, 9,8, 3, 4, 6, 5};
  print(list, 10);
  selection(list, 10);
  print(list, 10); 
}
