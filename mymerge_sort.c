#include <stdio.h>
#include <stdlib.h>

void merge_sort(int* , int* , int );
void merge_split_sort (int*, int, int, int*);
void copy(int*, int, int, int*);
void merge(int*, int, int, int, int*);
void print(int*, int, int);
/** 1. main function of merge sort */
void merge_sort(int* A, int* B, int n) {
  merge_split_sort(A, 0, n, B); // Array B is used for merge purpose.
}
/** 2. copy B to A. */
void copy(int* A, int begin, int end, int* B) {
  int i;
  for (i = begin; i < end; i++) 
    A[i] = B[i];
}
/** 3. The recursion solver for merge-sort. */
void merge_split_sort(int* A, int begin, int end, int* B) {
  // One number in the array. 
  // Already sorted.
  if (end - begin < 2)
    return;
  int middle;
  middle = (begin + end) / 2;
  // Merge sort the left half.
  merge_split_sort(A, begin, middle, B);
  // Merge sort the right half.
  merge_split_sort(A, middle, end, B);
  // Merge the left half and right half.
  merge(A, begin, middle, end, B);
}

/** 4. Merge two halves split by middle. */
void merge(int* A, int begin, int middle, int end, int* B) {
  int j;
  int i0 = begin; 
  int i1 = middle;
  for(j = begin; j < end; j++) {
    // the are elements in left  && no elements in right OR 
    // left element <= right element. 
    if ((i0 < middle) && (i1 >= end || A[i0] <= A[i1])) 
      B[j] = A[i0++];
    else 
      B[j] = A[i1++];
  }
  copy(A, begin, end, B);
}

/** 5. Print the array. */
void print(int* A, int begin, int end) {
  int i;
  for (i = begin; i < end; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

/** 6. Test case. */
int main() {
  int A[10] = {2, 1, 4, 3, 6, 5, 9, 7, 8, 0};
  int B[10];
  print(A, 0, 10);
  merge_sort(A, B, 10);
  print(A, 0, 10);  
  return 0;
}






