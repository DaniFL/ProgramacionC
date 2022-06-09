#include <unistd.h>
#include <fcntl.h>
#include <string.h> 
#include <stdlib.h>
#include <stdio.h>
#define TAMANO 1024

char buf[TAMANO];

    /*static void error(char* mensaje) { 
        write(2, mensaje, strlen(mensaje)); exit(1);
    }
    */

   
    static void error(char* mensaje) { 
        fprintf(stderr, "%s", mensaje); exit(1); 
    }
    
    int main(int argc, char* argv[]) {
        int leidos, escritos, origen, destino;
        if (argc!=3)
    
        error("Error en argumentos\n");
        if ((origen = open(argv[1], O_RDONLY)) < 0)

        error("Error en origen\n");
        if ((destino = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666)) < 0)

        error("Error en destino\n");
        while ((leidos = read(origen, buf, TAMANO)) > 0) {
            if ((escritos = write(destino, buf, leidos)) < 0) error("Error en escritura\n");
        }

        if (leidos < 0)
        error("Error en lectura\n"); close(origen);
        close(destino); exit(0);
}