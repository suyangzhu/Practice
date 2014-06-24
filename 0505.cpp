#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Test {
	char * ptr;
};

void shallow_copy(Test& src, Test& dest) {
	dest.ptr = src.ptr;
}

void deep_copy(Test& src, Test& dest) {
	dest.ptr = (char*)malloc(strlen(src.ptr) + 1);
	memcpy(dest.ptr, src.ptr, strlen(src.ptr) + 1);
}

int main() {
}
