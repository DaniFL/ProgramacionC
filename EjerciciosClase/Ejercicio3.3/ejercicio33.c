#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{

    printf("Partimos de un proceso padre %d\n", getppid());
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Se ha creado un proceso Hijo 1 %d\n", getppid(), getpid());
        pid_t pid2 = fork();

        if (pid2 == 0)
        {
            printf("Se ha creado un proceso Nieto %d\n", getppid(), getpid());
        }
    }
}
