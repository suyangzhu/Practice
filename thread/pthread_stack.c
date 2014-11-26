#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	4
#define N 10000
#define MEGEXTRA 1000000

pthread_attr_t attr;

void *dowork(void *threadid) {
	double A[N][N];
	int i, j;
	long tid;
	size_t mystacksize;
	tid = *((long *)threadid);
	pthread_attr_getstacksize(&attr, &mystacksize);
	printf("Thread %ld: stack size = %li bytes\n", tid, mystacksize);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			A[i][j] = ((i * j)/3.452) + (N-i);
		}
	}
	pthread_exit(NULL);
}

int main(int argc, char **argv) {
	pthread_t threads[NUM_THREADS];
	size_t stacksize;
	int rc;
	long t;
	pthread_attr_init(&attr);
	pthread_attr_getstacksize(&attr, &stacksize);
	printf("Default stack size = %li\n", stacksize);
	stacksize = sizeof(double) * N * N + MEGEXTRA;
	printf("Amount of stack needed per thread = %li\n", stacksize);
	pthread_attr_setstacksize(&attr, stacksize);
	printf("Creating threads with stack size = %li bytes\n", stacksize);
	for (t = 0; t < NUM_THREADS; t++) {
		rc = pthread_create(&threads[t], &attr, dowork, (void*) &t);
		if (rc) {
			printf("ERROR. return code from pthread_create() is %d\n", rc) ;
			exit(EXIT_FAILURE);
		}
	}
	printf("Created %ld threads.\n", t);
	pthread_exit(NULL);
}
