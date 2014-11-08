
int Shortest(string* str, int n, string word1, string word2) {
	int min = INT_MAX;
	int idx1 = -1, idx2 = -1;
	for (int i = 0; i < n; i++) {
		if (str[i] == word1) {
			idx1 = i;
			if (idx2 >= 0 && idx1 - idx2 < min) {
				min = idx1-idx2;
			}	
		} else
		if (str[i] == word2) {
			idx2 = i;
			if (idx1 >= 0 && idx2 - idx1 < min) {
				min = idx2-idx1;
			}	
		}
	}	
	return min;
}
