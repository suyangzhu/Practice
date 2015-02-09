#include <stdio.h>
#include <stdlib.h>

int StrCmp(const char *first, const char *second) {
	if (!*first && !*second) return 1;
	if (!*first || !*second) return 0;
	while (*first && *second) {
		if (*first == *second) {
			first++;
			second++;
			continue;
		} else {
			return 0;
		}
	}
	return !*first && !*second?1:0;
}

int main() {
	char a[10] = "";
	char b[100] = "abc";
	char c[20] = "bcd";
	char d[10] = "abc";
	if (StrCmp(b, d)) printf("1 True\n") ;
	else printf("1false\n");
}
