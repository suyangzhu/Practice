#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS 5

void *BusyWork(void *t) {
	int i;
	long tid;
	double result = 0.0;
	tid = *((long*) t);
	printf("thread %ld starting...\n", tid);
	for (i = 0; i < 1000000; i++) {
		result += sin(i) * tan(i);
	}
	printf("thread %ld one, Result = %e\n", tid, result);
	pthread_exit((void*) t);
}

int main(int argc, char **argv) {
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;
	int rc; 
	long t;
	long *status;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (t = 0; t < NUM_THREADS; t++) {
		printf("Main: creating thread %ld\n", t);
		rc = pthread_create(&thread[t], &attr, BusyWork, (void*) &t);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(EXIT_FAILURE);
		}
	}
	pthread_attr_destroy(&attr);
	for (t = 0; t < NUM_THREADS; t++) {
		rc = pthread_join(thread[t], (void **)&status);
		if (rc) {
			printf("ERROR; return code from pthread_join() is %d\n", rc);
			exit(EXIT_FAILURE);
		}
		printf("Main: complete join with thread %ld having a status of %ld\n", t, *((long*) status));
	}
	printf("Main: program completed. Exiting\n");
	pthread_exit(NULL);
}







