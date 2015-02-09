#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	char a[5] = "abcd";
	char *ptr = a;
	printf("%c\n", *ptr);
	ptr--;
	for (int i = 0; i <20; i++) ptr++;
	printf("%c\n", *ptr);

}
