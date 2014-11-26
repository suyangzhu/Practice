#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int var_glb;

int main(int argc, char **argv) {
	pid_t child_pid;
	int var_lcl = 0;
	int status;
	child_pid = vfork();

	if (child_pid < 0) {
		printf("\nfork failed\n");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) {
		var_glb++;
		var_lcl++;
		printf("child global = %d, local = %d\n", var_glb, var_lcl);
		exit(EXIT_SUCCESS);	
	} 
	wait(&status);
	printf("parent global = %d, local = %d\n", var_glb, var_lcl);
	return 0;
}	
