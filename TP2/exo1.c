#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void thread1(){
	while(1){
		printf(".\n");
		sleep(1);
	}
	pthread_exit(NULL);
}

void thread2(){
	printf("tapez un charactère : \n");
	char i;
	scanf("%c", &i);
	pthread_exit(&i);
}

int main(void){
        pthread_attr_t attr;
        pthread_t id1, id2;

        pthread_attr_init(&attr);
        pthread_create(&id1, &attr, (void*)thread1, NULL);
        pthread_create(&id2, &attr, (void*)thread2, NULL);

        pthread_join(id1, NULL);
        pthread_join(id2, NULL);

        exit(0);
}

