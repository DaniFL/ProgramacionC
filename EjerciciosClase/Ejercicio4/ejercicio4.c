#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//<errno.h> Error llamadas al sistema.

//Array
char name [] = "File.txt";
char mensaje [] = "Ejercicio Open-Write-Read";

void main(){

int fd;
fd = creat(name, 0666);

//Creación archivo txt
fd = open(name, O_CREAT|O_RDWR, 0666);

//Escritura sobre archivo txt
write(fd, mensaje,strlen(mensaje));
lseek(fd, 0, SEEK_SET);
//close(fd);
//open(fd,O_RDWR, 0666);

char c; 
//read(0,&c, 1);
//Lectura
while(read(fd, &c, 1) != 0){
    //write(1, &c, 1);
    printf("%c", c);
    fflush(stdout);
    sleep(1);
}
}
