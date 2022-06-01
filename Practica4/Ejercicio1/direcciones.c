#include <stdlib.h>
#include <stdio.h>

int A;

void escribe(char *texto, void *dir)
{

    printf("Dirección de %-4s = %10x\n", texto, (unsigned int)dir);
}

int main(void)
{
    int B;
    int *C = malloc(0x1000);

    escribe("main", main);
    escribe("A", &A);
    escribe("B", &B);
    escribe("C", C);
    sleep(1000);
    exit(0);
}