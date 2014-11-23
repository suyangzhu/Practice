#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

void exitFunc(void) {
	printf("\nClean-up function called\n");
}

int main(int argc, char **argv) {
	int cnt = 0;
	atexit(exitFunc);
	printf("\n");
	while (environ[cnt] != NULL) {
		printf("%s\n", environ[cnt++]);
	}
//	_exit(0);
	exit(EXIT_FAILURE);
}
