#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

# define VUELTAS 10000000000

void Salir (int sig){

    switch (sig){
        //Hemos cambiado la señal de SIGTERM A SIGINT
        case(SIGINT):
            printf("Saliendo del programa al recibir la señal SIGTERM\n");
            exit(EXIT_SUCCESS);
        break;
    }
}

int main (void){

    int i;
    printf("%d\n", getpid());
    signal(SIGINT, Salir); //Hemos cambiado la señal de SIGTERM A SIGINT

    for (i=0; i<VUELTAS; i++){}
        printf ("Fin del programa sin recibir la señal SIGTERM\n");
        exit(EXIT_SUCCESS);
}