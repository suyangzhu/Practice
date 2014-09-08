#include <stdio.h>
#include <stdlib.h>

void merge_sort(int* A, int* B, int n);	// A the merged list. B the orgininal list. n the number of 
					// elements in the list.

void copy(int* A, int start, int end, int* B);       // A the dest, B the dest.

void merge_split_sort(int* A, int start, int end, int* B); // merge two split lists into one.

void merge(int* A, int start, int middle, int end, int* B); 	// merge 2 split lists.


void merge_sort(int* A, int* B, int n) {
	merge_split_sort(A, 0, n, B);
}

void copy(int* A, int begin, int end, int* B) {
	int i; 
	for (i = begin; i < end; i++) {
		A[i] = B[i];
	}
}

void merge_split_sort(int* A, int start, int end, int* B) {
	if (end - start < 2) 
		return;
	int middle = (start + end) / 2;
	merge_split_sort(A, start, middle, B);
	merge_split_sort(A, middle, end, B);
	merge(A, start, middle, end, B);
	copy(A, start, end, B);
}

void merge(int* A, int start, int middle, int end, int* B) {
	int i0 = start;
	int i1 = middle;
	int k;
	for (k = start; k < end; k++) {
		if ((i0 < middle) && ((i1 >= end) || A[i0] < A[i1]))
			B[k] = A[i0++];
		else 
			B[k] = A[i1++];

	}
}

void print(int* A, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main() {
	int A[5] = {3, 1, 2, 5, 4};
	int B[5];
	merge_sort(A, B, 5);
	print(A, 5);
	return 0;
}
