#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

char c [] = "Hilo %d", i; 

void main() {
    
    
    pthread_t hilo1, hilo2, hilo3; 
    pthread_create(&hilo1, NULL, funcionHilo1, NULL);
    pthread_create(&hilo2, NULL, funcionHilo2, NULL);
    pthread_create(&hilo3, NULL, funcionHilo3, NULL);
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);
}

/* 
sem_t s1, s2, s3;

void * funcionHilo1(void * args){
    for(int i = 0; i < 3; i++){
    sem_wait(&s1);
    printf("A");
    sem_post(&s2); 
    }
}

void * funcionHilo2(void * args){
    for(int i = 0; i < 3; i++){
    sem_wait(&s2);
    printf("B");
    sem_post(&s3);
    }
}

void * funcionHilo3(void * args){
    for(int i = 0; i < 3; i++){
    sem_wait(&s3);
    printf("C \n");
    sem_post(&s1);
    }
}
*/