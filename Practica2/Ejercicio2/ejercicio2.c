#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>



int fd;
long int iteraciones = 100000;

void Write(int signal)
{
    char apartadoB [] = "Soy el proceso P3 y he recibido una señal del proceso P5\n";
    char apartadoC [] = "He recibido una señal de mi proceso padre\n";
    char apartadoD [] = " Soy P6\n";

    char c;
    int fd1;

    switch(signal)
    {
        case SIGUSR1:
            write(1, apartadoB, strlen(apartadoB));
        break;
        case SIGUSR2:
            write(1, apartadoC, strlen(apartadoC));
        break;
        case SIGINT:
            fd1 = open("SIGINT.txt", O_CREAT|O_RDWR, 0666);
            write(fd1, apartadoD, strlen(apartadoD));
            lseek(fd1,0,SEEK_SET);
            while(read(fd1,&c,1)>0)
           {
                write(1,&c,1);
                sleep(1);
                fflush(stdout);
           }
        break;
    }
}
void main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3)
    {
        printf("Necesita de un fichero para ejecutar el comando cat\n");
    }else
    {
        char c;
        int origen = open(argv[1], O_RDWR, 0666);
        
        while(read(origen,&c,1) > 0){ 
            write(1,&c,1);
        }
    }
    for (int i = 0; i < 4 ;i++){
        int contador = 0;
        pid_t pid = fork(); 
        
        if (pid == 0) 
        {
            printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());

            if (i == 0)
            {
                contador ++;
                printf("El contador se ha sumado correctamente %d\n", contador);
            }

            if (i == 1)
            {
                contador ++;
                printf("El contador se ha sumado correctamente %d\n", contador);
                fd = open("Fichero.txt", O_CREAT|O_RDWR, 0666);
            }

            if(i == 2)
            {
                sleep(1);
                signal(SIGUSR1, Write);
                contador ++;
                printf("El contador se ha sumado correctamente %d\n", contador);
                pid_t pid2 = fork();
                
                if(pid2 == 0)
                {
                    printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
                    signal(SIGUSR2, Write);
                    kill(getppid(), SIGUSR1);
                    sleep(1);   
                }
                else { 
                    sleep(1);
                    kill(pid2, SIGUSR2);
                }
            }

            if (i == 3) 
            {
                pid_t pid3 = fork();

                if(pid3 == 0)
                {
                    printf("Soy el proceso p6, mi pid es: %d. Y mi PPID es: %d\n", getpid(), getppid());
                    signal(SIGINT, Write);
                    for (long int i=0; i<iteraciones; i++){}
				}
                
                else { 
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

