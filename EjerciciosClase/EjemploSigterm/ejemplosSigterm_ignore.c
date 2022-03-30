#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

# define VUELTAS 10000000000

void Salir (int sig){
    switch (sig){
        case(SIGTERM):
            printf("Saliendo del programa al recibir la señal SIGTERM\n");
            exit(EXIT_SUCCESS);
        break;
    }
}

int main (void){

    int i;

    signal(SIGTERM, Salir);
    signal (SIGTERM, SIG_IGN);
    
    for (i=0; i<VUELTAS; i++){}
    printf ("Fin del programa sin recibir la señal SIGTERM\n");
    exit(EXIT_SUCCESS);
}