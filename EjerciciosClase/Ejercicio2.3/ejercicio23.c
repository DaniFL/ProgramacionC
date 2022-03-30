#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char *argv[]) {

    int fd1, fd2; 
     
    //fd1 = creat(file, 0666);
    //fd2 = creat(file2, 0666);
    fd1 = open(argv[1], O_CREAT|O_RDWR, 0666);
    fd2 = open(argv[2], O_CREAT|O_RDWR, 0666); 

    char c;

    while(read(fd1, &c, 1) > 0){ //Lee el contenido del fichero origen y lo escribe en el fichero destino.
        write(fd2, &c, 1);       
    }
    
    lseek(fd1, 0, SEEK_SET); //Actualiza posición del puntero1
    
    while(read(fd1, &c, 1) > 0){ //lee el contenido del fichero origen y lo imprime por pantalla. (cat)
        write(1, &c, 1);
    }

    lseek(fd2, 0, SEEK_SET); //Actualiza posición del puntero2

     while(read(fd2, &c, 1) > 0){ //lee el contenido del fichero destino y lo imprime por pantalla. (cat)
        write(1, &c, 1);
    }

    lseek(fd1, 0, SEEK_SET);

    while(read(fd1, &c, 1)>0){ 

        int i = 0; 
        if (c == ' '){
            i++;
        }else if (d == c){
            printf("La palabra se encuentra en el fichero");
            break;
        }else if (c!= d){
            i++; 
        }
            
        }

        
        
        
}


