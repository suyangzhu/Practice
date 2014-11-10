#include <stdio.h>
#include <stdlib.h>

void quick_sort(int*, int, int);
int partition(int*, int, int);

void quick_sort(int* A, int lo, int hi) {
  int pivot;
  if (lo < hi) {
    pivot = partition(A, lo, hi);
    quick_sort(A, lo, pivot - 1);
    quick_sort(A, pivot + 1, hi);
  }
}

void swap(int* A, int first, int second) {
	int tmp = A[first];
	A[first] = A[second];
	A[second] = tmp;
}
/** Random choose. */
int ChoosePivot(int lo, int hi) {
	return lo + rand() % (hi-lo+1);
}

int partition(int* A, int lo, int hi) {
	int pivotIdx = ChoosePivot(lo, hi);
	int pivotVal = A[pivotIdx];
	swap(A, pivotIdx, hi);
	int storeIdx = lo;
	int i;
	for (i = lo; i < hi; i++) {
		if (A[i] < pivotVal) {
			swap(A, i, storeIdx);
			storeIdx++;
		}
	}
	swap(A, storeIdx, hi);
	return storeIdx;
}
/*
int partition(int* A, int lo, int hi) {
	int pivotIdx = RandomSelect(lo, hi);
	int pivotValue = A[pivotIdx];
	swap(A, pivotIdx, hi);
	int storeIdx = lo;
	for (int i = 0; i < hi; i++) {
		if (A[i]  < pivotValue) {
			swap(A, i, storeIdx);
			storeIdx++;
		}
	}
	swap(A, storeIdx, hi);
	return storeIdx;
}
*/
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

  int B[0] = {};
  size = sizeof(B)/sizeof(int);
  quick_sort(B, 0, size-1);
  print(B, 0, size);

  int C[1] = {1};
  size = sizeof(C)/sizeof(int);
  quick_sort(C, 0, size-1);
  print(C, 0, size);


  int D[10] = {12, 32, 22, 22, 22, 12, -1, 12, 0, -100};
  size = sizeof(D)/sizeof(int);
  quick_sort(D, 0, size-1);
  print(D, 0, size);
  return 0;
}
