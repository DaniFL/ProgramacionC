#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// open: esta función devuelve -1 en caso de error y >2 en caso de éxito. Recuerda que los valores 0, 1 y 2
// están reservados a los descriptores de la entrada estándar, salida estándar y error estándar

/* En este código vemos el concepto de los descriptores de archivos
Tras abrir dos ficheros prueba1 y prueba2 se designan dos descriptores 3 y 4 (las posiciones 0, 1 y 2 son
posiciones ocupadas por defecto)
*/

int main(void){

    int fd;
    fd = open("prueba1.txt",O_CREAT|O_RDONLY);
    printf("%d \n",fd);
    close (fd);
    fd = open("prueba2.txt",O_CREAT|O_RDONLY);
    printf("%d \n",fd);
    close(fd);
    return(0);
}
    

