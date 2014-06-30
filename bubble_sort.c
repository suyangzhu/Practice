#include <stdio.h>
#include <stdlib.h>


#define N 10

void BubbleSort (int *list, int size) {
  int i, j, swapTmp;
  for (i = size-1; i > 0; i--) {
    for (j = 0; j < i; j++) { 
      if (list[j] > list[j+1]) {
        swapTmp = list[j];
        list[j] = list[j + 1];
        list[j+1] = swapTmp;
      }
    }
  }
}

void print(int* list, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

int main() {
  int list[10] = {0, 2, 1, 3, 6, 5, 4, 9, 8, 7};
  print(list, 10);
  BubbleSort(list, 10);
  print(list, 10);
  return 0;
}

