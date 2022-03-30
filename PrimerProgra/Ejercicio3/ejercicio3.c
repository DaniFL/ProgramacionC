#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void main(int argc, char *argv[]){
    
    char c [] = "HOLA BUENOS DIAS"; 
    int fd = open("fichero2.txt", O_CREAT|O_RDWR, 0666);

    write(fd,&c,strlen(c)); 
    execv("fichero2.txt","sort",(char*)&c);
}