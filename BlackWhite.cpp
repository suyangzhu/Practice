#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void DFS(int start, int& size, int& cnt, int prev1, int prev2) {
	if (start == size) {
		cnt++;
		return;
	}
	if (start == 0 || start == 1) {
		DFS(start+1, size, cnt, 0, prev1);
		DFS(start+1, size, cnt, 1, prev1);
	} else {
		if (prev1 != prev2) {
			DFS(start+1, size, cnt, 1, prev1);
			DFS(start+1, size, cnt, 0, prev1);
		} else 
		if(prev1 == 0) {
			DFS(start+1, size, cnt, 1, prev1);
		} else {
			DFS(start+1, size, cnt, 0, prev1);
		}
	}	
}

int main() {
	while (1) {
	int size;
	cin >> size;
	int cnt = 0;
	DFS(0, size, cnt, 0, 0);
	std::cout << size << "  " << cnt << std::endl;
	}
}
