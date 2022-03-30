#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

 char a []= "a"; 
 char b []= "b";

//meter un for para iterar 
void main(){

    int fd; 
    int count = 1; 
    fd = open("prueba1.txt",O_CREAT|O_RDWR, 0666); 
    pid_t pid = fork();

for (int i = 0; i < count; i++){

    if(pid == 0){

        write(fd,a,strlen(a));
        sleep(2);
        pid_t pid2 = fork();

        if (pid2 == 0) {
            write(fd,b,strlen(b));
            sleep(2);
        }  
    } 
}
}
