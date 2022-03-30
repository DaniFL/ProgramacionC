#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void main()
{
 
int fd;
 
int counter = 0;
 
fd = open("ficheroA.txt", O_CREAT|O_RDWR, 0666);
 
pid_t rtd = fork(); // Me hace un hijo
 
while (counter <3)
{
 
if(rtd == 0 && counter == 1)
 
{
 
char a[] = "a"; // Aqui el primer hijo que se me crea lo que hace es escribirme 'a' dentro del fichero
 
write(fd,a,strlen(a)
);
 
 
}
 
if(rtd == 0 && counter == 2) //Al hacer este bucle consigo que me haga otro hijo y puedo hacer que me escriba 'b' dentro del fichero
 
{
 
char b[] = "b";
 
write(fd,b,strlen(b)
);
 
}
 
counter++;
 
}
}