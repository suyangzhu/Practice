#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* With the boolean array to store the boolean value.
   O(N). Cost to speed*/
void removeDupliates(char* str) {
	int len;
	int i;
	int tail;

	len = strlen(str);
	tail = 1;

	if(len < 2)
		return;
	bool hit[256];
	for (i = 0; i < 256; i++)
		hit[i] = false;

	hit[str[0]] = true;

	for (i = 1; i < len; i++) {
		if (!hit[str[i]]) {
			str[tail++] = str[i];
			hit[str[i]] = true;
		}
	}
	str[tail] = '\0';

}

void print(char* str) {
	printf("String: %s\n", str);
}

int main() {
	char str[] = "abaa";
	removeDupliates (str);
	print(str);
	return 0;
}
