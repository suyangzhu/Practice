#include <stdio.h>
#include <stdlib.h>

void merge(int* A, int* B, int sizeA, int sizeB) {
  // Note that starting point should be
  // 1 less than size. 
  int k = sizeA -1;   /**< size of large array */
  int m = sizeB -1;   /**< size of small array */
  int n = k - m - 1;  /**< size of actual large array */
  printf("k = %d  m = %d   n = %d\n", k, m, n);
  while (m >=0 && n >=0) {
    if (B[m] > A[n]) {
      A[k--] = B[m--];
    } else {
      A[k--] = A[n--];
    }
  }
  while(n >= 0) 
    A[k--] = A[n--];
  
  while(m >= 0) 
    A[k--] = B[m--];
}

void print(int*a, int size) {
  int i;
  for (i = 0; i < size; i++) 
    printf("%d ", a[i]);
  printf("\n");
}

int main() {
  int a[12] = {1, 2, 3, 4, 5, 6};
  int b[6] = {3, 4,5,6,7,8};
  merge(a, b, 12, 6);
  print(a, 12);
}

