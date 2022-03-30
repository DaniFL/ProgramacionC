#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    
    // char c[] = "Soy el proceso PID_del_proceso y mi padre es PPID_del proceso";
    for (int i = 0; i < 4; i++)
    {
        int contador = 0;
        pid_t pid = fork();

        if (pid == 0)
        {
            printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());

            if(i == 0){
                contador ++;
                printf("El contador se ha sumado correctamente %d\n", contador);
            }
            if(i == 1){
                contador ++;
                printf("El contador se ha sumado correctamente %d\n", contador);
            }
            
            if(i == 2)
            {
                contador ++;
                printf("El contador se ha sumado correctamente %d\n", contador);
                pid_t pid2 = fork();
                // printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
                if (pid2 == 0)
                {
                    printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
                    sleep(1);
                }
                else {
                    sleep(1);
                }

            } if(i == 3){
            
                pid_t pid3 = fork();
                if(pid3 == 0){
                    printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
                }
                else {
                    sleep(1);
                    execl("/bin/ps","ps","-l",(char*)0);
                }
            }
            break;        
        }    
    }
    while (wait(NULL)>0)
    {
        sleep(1);
    }    
}
