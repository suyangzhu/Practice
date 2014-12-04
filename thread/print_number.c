#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 10
pthread_mutex_t muta;
pthread_t threads[NUM_THREADS];
void *Print(void *arg) {
	pthread_mutex_lock(&muta);
	printf("cnt is %d\n", (*(int*)arg)++);
	pthread_mutex_unlock(&muta);
}
int main() {
	int rc;
	int i;
	int *cnt = (int *) malloc (sizeof(int));
	*cnt = 1;
	pthread_attr_t attr;
	pthread_mutex_init(&muta, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (i = 0; i < 10; i++) {
		rc = pthread_create(&threads[i], &attr, Print, (void *)cnt);
		if (rc) {
			printf("pthread_create failure. Error code is %d\n", rc);
		}
	}

	for (i = 0; i < 10; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}
