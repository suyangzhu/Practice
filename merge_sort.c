#include <stdio.h>
#include <stdlib.h>

void print(int* list, int begin, int end) ;
void TopDownMerge(int* listA, int begin, int middle, int end, int* listB);
void TopDownSplitMerge (int* listA, int begin, int end, int* listB);

void TopDownMergeSort(int* listA, int* listB, int n) {
  TopDownSplitMerge(listA, 0, n, listB);
}

void CopyArray(int* listB, int begin, int end, int* listA) {
  int i;
  for (i = begin; i < end; i++) {
    listA[i] = listB[i];
  }
}

void TopDownSplitMerge (int* listA, int begin, int end, int* listB) {
  if ((end - begin) < 2) 
    return;
  int middle = (begin + end) / 2;
  TopDownSplitMerge( listA, begin, middle, listB);
  TopDownSplitMerge( listA, middle, end,  listB);
  TopDownMerge(listA, begin, middle, end, listB);
  CopyArray(listB, begin, end, listA);
}

void TopDownMerge(int* listA, int begin, int middle, int end, int* listB) {
  int i0 = begin;
  int i1 = middle;
  int j;
  for (j =  begin; j < end; j++)  {
    if (i0 < middle && (i1 >= end  || listA[i0] <= listA[i1])) {
      listB[j] = listA[i0];
      i0++;
    }
    else {
      listB[j] = listA[i1];
      i1++;
    }
  }
}
void print(int* list, int begin, int end) {
  int i; 
  for (i = begin; i < end; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
}
int main() {
  int A[2] = {2,1};
  int B[2];
  print(A, 0, 2);
  TopDownMergeSort(A, B, 2);
  print(A, 0, 2);  

  return 0;
}
