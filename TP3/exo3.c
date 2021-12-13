#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


unsigned long cpt = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* compteur(void* ptr){
    for (int i=0; i <10000000; i++){
        pthread_mutex_lock(&mutex);
        unsigned long tmp = cpt;
        tmp = tmp + 1;
        cpt = tmp;
        pthread_mutex_unlock(&mutex);
    }

    printf("La variable cpt du thread est %lu \n", cpt);

    pthread_exit(NULL);
}



int main(){
    
    pthread_attr_t attr;
    pthread_t id1, id2;

    pthread_attr_init(&attr);
    pthread_create(&id1, &attr, &compteur, NULL);
    pthread_create(&id2, &attr, &compteur, NULL);

    printf("Les threads sont lances \n");

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}