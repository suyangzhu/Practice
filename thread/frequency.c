#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define NUM_THREADS 10
int cntA;
int cntB;
int cntC;

pthread_mutex_t mutaA;
pthread_mutex_t mutaB;
pthread_mutex_t mutaC;

pthread_t threads[NUM_THREADS];

int array[100*NUM_THREADS];
void *init(void *arg) {
	int idx = (*(int *) arg);
	int offset = idx * 100;
	int i;
	for (i = 0; i < 100; i++) {
		array[i+offset] = rand() % 3;
	}
	pthread_exit(NULL);
}
void *func(void *arg) {
	int idx = (*(int *) arg);
	int i;
	int offset = idx * 100;	
	for (i = 0; i < 100; i++) {
		if (array[i+offset] == 0) {
			pthread_mutex_lock(&mutaA);
			cntA++;
			pthread_mutex_unlock(&mutaA);
		} else if (array[i+offset] == 1) {
			pthread_mutex_lock(&mutaB);
			cntB++;
			pthread_mutex_unlock(&mutaB);
		} else {
			pthread_mutex_lock(&mutaC);
			cntC++;
			pthread_mutex_unlock(&mutaC);
		}
	}

	pthread_exit(NULL);
}



int main() {
	// initialize the random array.
	srand(time(NULL));
	int i;
	int rc = 0;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	
	pthread_mutex_init(&mutaA, NULL);
	pthread_mutex_init(&mutaB, NULL);
	pthread_mutex_init(&mutaC, NULL);

	cntA = 0;
	cntB = 0; 
	cntC = 0;

      	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_create(&threads[i], &attr, init, &i);
		if (rc) {
			printf("pthread_create failes, error code %d\n", rc);
			exit(0);
		}
	}

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(threads[i], NULL);
		if (rc) {
			printf("pthread_join fails, error code %d\n", rc);
			exit(0);
		}
	}

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_create(&threads[i], &attr, func, &i);
		if (rc) {
			printf("pthread_create fails, error code %d\n", rc);
			exit(0);
		}
	}

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(threads[i], NULL);
		if (rc) {
			printf("pthread_join fails, error code %d\n", rc);
			exit(0);
		}
	}

	printf("cntA = %d, cntB = %d, cntC = %d, total = %d\n", cntA, cntB, cntC, cntA + cntB + cntC);
	return 0;
}









