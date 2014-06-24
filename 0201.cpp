#include <cstdio>
#include <cstdlib>

#include <iostream>

#define N 6

int list[N];
void print(int *);
void init(int n) {
	for (int i = 0; i < N; i++)
		list[i] = i;
}



void rotate(int *a, int beg, int end) {
	int mid;
	int i;
	int tmp;
	int x;
	if (beg == end) 
		return;
	mid = (beg + end) / 2;

	std::cout << "mid = " << mid << "  " <<(beg+mid)/2  << std::endl;
	if ((mid-beg) %2 == 0)
		x = (mid-beg)/2 ;
	else 
		x = (mid-beg)/2 +1;
		for (i = 0; i < x; i++) {
			std::cout << (beg+mid)/2 + i + 1 << std::endl;
			tmp = a[(beg+mid)/2 + i + 1];
			a[(beg+mid)/2 + i + 1] = a[mid + 1 + i];
	       		a[mid +1  + i] = tmp;
		}

	std::cout << "after one rotation the list is " << std::endl;
	print(list);
	rotate(a, beg, mid);
	rotate(a, mid+1, end);
	
}

void print(int *a) {
	int i;
	for (i = 0; i < N; i++) {
		std::cout << a[i] <<" "; 
	}
		std::cout << std::endl;
}

int main() {
	init(N);
	print(list);
	rotate(list, 0, N-1);
	std::cout << std::endl;
	print(list);
}


