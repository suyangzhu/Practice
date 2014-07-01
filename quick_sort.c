#include <stdio.h>
#include <stdlib.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);

void quick_sort(int* A, int lo, int hi) {
  int pivot;
  if (hi > lo) {
    pivot = partition(A, lo, hi);
    quick_sort(A, lo, pivot - 1);
    quick_sort(A, pivot + 1, hi);
  }
}

int partition(int* A, int lo, int hi) {
  int i;
  int left = lo;
  int right = hi;
  int pivotIndex = lo;
  int pivotVal = A[pivotIndex];
  while (left < right) {
    while (A[left] <= pivotVal) 
      left++;
    while (A[right] > pivotVal)
      right--;
    if (left < right) {
      int tmp = A[left];
      A[left] = A[right];
      A[right] = tmp;
    }
  }
  A[lo] = A[right];
  A[right] = pivotVal;
  return right;
}

void print(int* A, int begin, int end) {
  int i;
  for (i = begin; i < end; i++) 
    printf("%d ", A[i]);
  printf("\n");
}

int main() {
  int A[10] = {2, 1, 5, 4, 6, 7, 9, 8,3, 0};
  int size = sizeof(A) / sizeof(int);
  quick_sort(A, 0, size-1);
  print(A, 0, 10);
  return 0;
}
