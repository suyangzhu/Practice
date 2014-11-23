#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void exitFunc(void) {
	printf("\nClean-up function for exit\n");
}

int main(int argc, char **argv) {
	FILE *fp = NULL;
	pid_t process_id = 0;
	pid_t sid = 0;

	process_id = fork();
	// indicates fork failure;
	if (process_id < 0) {
		printf("\nfork failure\n");
		exit(EXIT_FAILURE);
	} 
	// indicates parent process;
	if (process_id > 0) {
		printf("\nprocess_id of child process %d\n", process_id);
		exit(EXIT_SUCCESS);
	}

	// unmask the file mode
	umask(0);
	sid = setsid();
	if (sid < 0) {
		printf("\nsetsid failure\n");
		exit(EXIT_FAILURE);
	}
	chdir("/");
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	fp = fopen("Log.txt", "w+");
	while(1) {
		float i = 1.1;
		i = i*i;
		fflush(fp);
	}
	fclose(fp);
	return 0;
}
