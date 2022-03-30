#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void main(){

    printf("Partimos de un proceso padre con PPID: %d\n", getppid());
    pid_t pid = fork();

 if(pid == 0){
 
        printf("Se ha creado un proceso hijo con PPID: %d\n", getppid());
        
        pid_t pid2 = fork();
 
        if(pid2 == 0){
 
            printf("Se ha creado un proceso nieto con PPID: %d\n", getppid());
            sleep(1);
            execl("/bin/ps","ps",(char*)0);
            exit(0);
        }
        else
        {
            execl("/bin/ls","ls",(char*)0);
        }
        
 
    }
 
}
