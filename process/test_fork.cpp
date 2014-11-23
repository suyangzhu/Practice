#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define NFORKS 5

void do_nothing() {
	int i; 
	i = 0;
}

int main (int argc, char** argv) {
	int pid , j, status;
	for (j = 0; j < NFORKS; j++) {
		if ((pid = fork()) < 0) {
			printf("fork failed with error code = %d\n", pid);
			exit(0);
		} else if (pid == 0) {
			printf("%d, %d\n", pid, j);
			do_nothing();
			exit(0);
		} else {
			printf("%d, %d\n", pid, j);
			waitpid(pid, &status, 0);
		}
		printf("double kill \n");
	}
	return 0;
}
