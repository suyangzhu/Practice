#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int global;

void exitFunc(void) {
	printf("\nClean-up function\n");
}	

int main(int argc, char **argv) {
	pid_t child_pid;
	int status;
	int local = 0;
	printf("---------\n");
	child_pid = vfork();

	if (child_pid < 0) { 
		printf("\nfork failure\n");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) {
		printf("child process!\n");
		local++;
		global++;
		printf("child PID = %d, parent PID = %d\n", getpid(), getppid());
		printf("\nchild's local = %d, child's global = %d\n", local, global);
		exit(EXIT_SUCCESS);
	} else {
		
		printf("parent process!\n");
		wait(&status);
		printf("parent PID = %d, child PID = %d\n", getpid(), child_pid);
		
		printf("Child exit code: %d\n", WEXITSTATUS(status));
		printf("\nParent's local = %d, parent's global = %d\n", local, global);
		printf("Parent says bye!\n");
		exit(EXIT_SUCCESS);
	}
}
