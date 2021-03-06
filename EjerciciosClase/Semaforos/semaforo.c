#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

int cuenta = 0; 
int turno = 0; 
bool estado[2];
sem_t s1;

    void * funcionSuma(void * args){
        for (int i = 0; i <1000; i++){
            //while(true){
                estado[0] = true;
                turno = 1;
                //while(estado[1] && turno == 1){}
                //No hace nada 
                //sección critico 
                sem_wait(&s1); //Wait
                cuenta++;
                sem_post(&s1); //Signal 
                estado[0] = false;
                //resto
    //}
}
    }

void * funcionResta(void * args){
    for (int i = 0; i <1000; i++){
            //while(true){
                estado[1] = true;
                turno = 0;
                //while(estado[0] && turno == 0){}
                //No hace nada 
                //sección critico 
                sem_wait(&s1); //Wait
                cuenta--;
                sem_post(&s1); //Signal
                estado[1] = false;
                //resto
            //}
    }
}

void main(){
    
    sem_init(&s1, 0, 1); //Inicializamos semáforo.
    pthread_t suma, resta; // variable tio thread
    pthread_create(&suma, NULL, funcionSuma, NULL);
    pthread_create(&resta, NULL, funcionResta, NULL);
    pthread_join(suma, NULL);
    pthread_join(resta, NULL);
    printf("%d\n", cuenta);
}
