#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

    int dato;
    int *dir;
    long *dir2;

    void nolee(int s) {
    printf(" no legible\n");
    sleep(1000);
    exit(0);
    }

    void noescribe(int s) {
    printf(" no escribible\n");
    sleep(1000);
    exit(0);
    }

    void escribe(char* texto, void *dir) {
    printf ("Dirección de %-4s = 0x%lx\n", texto,(long)dir);
    }

    int main(int argc, char *argv[]) {
    int A;

    //escribe("A", &A);
    escribe("main", &main);
    //dir = (unsigned int*)&A;
    dir = (unsigned int*)&main;
    printf ("Probando la dirección virtual 0x%lx\n", (long)dir);
    signal(SIGSEGV, nolee);
    dato = *dir;
    printf(" legible\n");
    signal(SIGSEGV, noescribe);
    *dir = dato;
    printf(" escribible\n");
    sleep(1000);
    exit(0);
    }