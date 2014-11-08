

int Rand(int first, int second) {
	return first + rand() % (second-first+1);
}
void Pick(int* src, int n, int* target, int m) {
	for (int i = 0; i < m; i++) {
		int idx = Rand(i, n-1);
		target[i] = src[idx];
		src[idx] = src[i];
	}
}

void Shuffle(int* card, int n) {
	for (int i = 0; i < n; i++) {
		int idx = Rand(i, n-1);
		int tmp = card[i];
		card[i] = card[idx];
		card[idx] = tmp;
	}
}
