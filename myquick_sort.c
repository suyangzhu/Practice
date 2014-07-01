#include <stdio.h>
#include <stdlib.h>
/**
 * @file myquick_sort.h
 * @brief quick sort for int array
 */

void quick_sort(int*, int, int);
int partition(int*, int, int);
void print(int*, int, int);
/** 1. quick sort */
void quick_sort(int* A, int lo, int hi) {
  int pivot;
  // hi > lo is necessary since program stops 
  // when lo >= hi. This is the situation 
  // that the recursion stops.
  if (hi > lo) {
    // Get the position of pivot.
    pivot = partition(A, lo, hi);
    quick_sort(A, lo, pivot - 1);
    quick_sort(A, pivot + 1, hi);
  }
}

/** 2. Partition the array. */
int partition(int*A, int lo, int hi) {
  int left = lo;
  int right = hi;
  int pivotIndex = lo;
  int val = A[pivotIndex];
  // This is an important method.
  // Finally the pivot is between 
  // left and right.
  while(left < right) {
    while (A[left] <= val) 
      left++;
    while (A[right] > val) 
      right--;
    // Again, left may be larger than right.
    if(left < right) {
      int tmp;
      tmp = A[left];
      A[left] = A[right];
      A[right] = tmp;
    }
  }
  A[lo] = A[right];
  A[right] = val;
  return right;
}

void print(int*A, int begin, int end) {
  int i;
  for (i = begin; i< end; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  int A[10] = {2, 1, 5, 4,3, 6, 8, 7, 9, 0};
  quick_sort(A, 0, sizeof(A)/sizeof(int) - 1);
  print(A, 0, sizeof(A)/sizeof(int));
  return 0; 
}
