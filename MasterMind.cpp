#include <string>
#include <iostream>
using namespace std;
int code(char c) {
	switch(c) {
		case 'B':
			return 0;
		case 'G':
			return 1;
		case 'R':
			return 2;
		case 'Y':
			return 3;
		default:
			return -1;
	}
}

void Estimate(string guess, string solution, int &hit, int& pseudoHit) {
	if (guess.size() != solution.size()) return;
	int freq[4] = {0, 0, 0, 0};
	for (int i = 0; i < guess.size(); i++) {
		if (guess[i] == solution[i]) hit++;
		else {
			freq[code(solution[i])]++;
		}
	}

	for (int i = 0; i < guess.size(); i++) {
		int idx = code(guess[i]);
		if (idx >= 0 && freq[idx] && guess[i] != solution[i]) {
			pseudoHit++;
			freq[i]--;
		}
	}
}

int main() {
}
