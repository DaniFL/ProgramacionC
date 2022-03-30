#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int cuenta = 0; 
bool turno = 0;
bool estado1 = 0;
bool estado2 = 0;

    void * funcionSuma(void * args){
        for (int i = 0; i <10001; i++){
            while (turno != 0){ }
                while (estado2){
                estado1 = true; 
                cuenta++; 
                estado1 = false;
                } 
            cuenta = cuenta + 1;
            turno = 1;    
        }
    }

    void * funcionResta(void * args){
        for (int i = 0; i <10001; i++){
            while (turno != 1){}
                while (estado1){
                estado2 = true; 
                cuenta++; 
                estado2 = false; 
                }
            cuenta = cuenta - 1;
            turno = 0; 
        }
    }

void main(){

    pthread_t suma, resta; // variable tio thread
    pthread_create(&suma, NULL, funcionSuma, NULL);
    pthread_create(&resta, NULL, funcionResta, NULL);
    pthread_join(suma, NULL);
    pthread_join(resta, NULL);
    printf("%d\n", cuenta);
}
    