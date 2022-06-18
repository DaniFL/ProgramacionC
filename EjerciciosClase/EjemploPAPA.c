#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num;

    pid_t pid;
    pid = fork();

    for (num = 0; num < 3; num++)
    {
        printf("Soy el proceso de PID %d y mi padre tiene %d de PID\n", getpid(), getppid());
        if (pid > 0)
        {
            break;
        }
        while (wait(NULL) > 0)
        {
        }
        printf("Fin del proceso de de PID %d\n", getpid());
        return 0;
    }
}