#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

long *taskids[NUM_THREADS];
void *PrintHello(void *threadid) {
	long tid; 
	tid = *((long*) threadid);
	printf("Hello world from thread %ld\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char **argv) {
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for (t = 0; t < NUM_THREADS; t++) {
		taskids[t] = (long*) malloc(sizeof(long));
		*taskids[t] = t;
		printf("Creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)taskids[t]);
	}
	if (rc) {
		printf("ERROR, return code from pthread_create is %d\n", rc);
		exit(EXIT_FAILURE);
	}
	pthread_exit(NULL);
}
