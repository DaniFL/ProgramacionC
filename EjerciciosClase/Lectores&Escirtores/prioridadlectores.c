#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>

sem_t mutex = 1;
sem_t writer = 1;
int readers = 0;

void * lectura(void * args){
    wait(mutex);
    readers = readers+1;
    if (readers==1) wait(writer);
    signal(mutex);
    leer();
    wait(mutex);
    readers = readers-1;
    if (readers==0) signal(writer);
    signal(mutex);
}


void * escritura(void * args){
    wait(writer);
    escribir();
    signal(writer);
}


void main(){
    
    pthread_t lectura1, lectura2, escritura1, escritura2;
    pthread_create(&lectura1, NULL, lectura, NULL);
    pthread_create(&lectura2, NULL, lectura, NULL);
    pthread_create(&escritura1, NULL, escritura, NULL);
    pthread_create(&escritura2, NULL, escritura, NULL);
    pthread_join(lectura1, NULL);
    pthread_join(lectura2, NULL);
    pthread_join(escritura1, NULL);
    pthread_join(escritura2, NULL);
}
    

