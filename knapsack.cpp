#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int KnapSack(int target, int value[], int weight[], int record[], int n) {
	if (target == 0 || n == 0) return 0;
	if (target < weight[n-1]) {
		return KnapSack(target, value, weight, record, n-1);
	} else {
		int first = value[n-1] + KnapSack(target - weight[n-1], value, weight, record, n-1);
		int second = KnapSack(target, value, weight, record, n-1);
		if (first > second) std::cout << first << std::endl;
		else std::cout << second << std::endl;
		return first > second ? first : second;
	}
}

int KnapSack_DP(int target, int value[], int weight[], int record[], int n) {
	int DP[n+1][target+1];	// there are two parameters in previous recursion solution. Thus we can build a DP base on the two paras.
	int Path[n+1][target+1];
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < target+1; j++) {
			Path[i][j] = 0;
		}
	}
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < target+1; j++) {
			if (j == 0 || i == 0) {
				DP[i][j] = 0;
			}
			else if (j < weight[i-1]) {
				DP[i][j] = DP[i-1][j];
			} else {
				DP[i][j] = value[i-1] + DP[i-1][j-weight[i-1]] > DP[i-1][j]?
					   value[i-1] + DP[i-1][j-weight[i-1]] : DP[i-1][j];
				Path[i][j] = value[i-1] + DP[i-1][j-weight[i-1]] > DP[i-1][j] ? 1:0;
			}
		}
	}
	std::cout << "DP mat: " << std::endl;
	
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < target+1; j++) {
			std::cout << Path[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	return DP[n][target];
}

int main() {
	int value[5] = {4, 3, 5, 8, 12};
	int weight[5] = {3, 3, 8, 10, 8};
	int record[6] = {-1, -1, -1, -1, -1, -1};
	int target = 20;
	int n = 5;
	int profit = KnapSack_DP(target, value, weight,record, n);

	for (int i = 0; i < n; i++) {
		std::cout << value[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < n+1; i++) {
		std::cout << record[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Profit is : " << profit << std::endl;
	return 0;
}
