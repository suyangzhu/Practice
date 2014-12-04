#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define TICK 10
#define CNT_LIMIT 10

pthread_mutex_t muta;
pthread_cond_t cv;
int cnt;
pthread_t threads[NUM_THREADS];
void *inc_cnt(void *arg) {
	int i;
	int idx = (*(int *) arg);
	for (i = 0; i < TICK+10; i++) {
		sleep(1);
		if (cnt > CNT_LIMIT) {
			pthread_exit(NULL);
		}
		pthread_mutex_lock(&muta);
		cnt++;
		if (cnt == CNT_LIMIT) {
			printf("thread %d trigger signal\n", idx);
			pthread_cond_signal(&cv);
			printf("Signal!");
		}
		printf("--\n");
		pthread_mutex_unlock(&muta);
	}
	pthread_exit(NULL);
}

void *wait_cnt(void *arg) {
	int idx = (*(int *)arg);
	printf("thread %d starts waiting\n", idx);
	pthread_mutex_lock(&muta);
	pthread_cond_wait(&cv, &muta);
	printf("Finally thread %d ends waiting;\n", idx);	
	pthread_mutex_unlock(&muta);
	pthread_exit(NULL);
}

int main() {
	int i;
	int rc = 0;
	cnt = 0;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_mutex_init(&muta, NULL);
	pthread_cond_init(&cv, NULL);
	for (i = 0; i < NUM_THREADS - 1; i++) {
		rc = pthread_create(&threads[i], &attr, inc_cnt, &i);
		if (rc) {
			printf("create failure, rc = %d\n", rc);
			exit(0);
		}
	}	
	rc = pthread_create(&threads[i], &attr, wait_cnt, &i);
	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(threads[i], NULL);
		if (rc) {
			printf("pthread_join fails %d\n", rc);
		}
	}	
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&muta);
	pthread_cond_destroy(&cv);
	return 0;
}

