#include <stdio.h>
#include <stdlib.h>

void main (int argc, char *argv[]){
  
int numero1 = atoi(argv[1]); 
int numero2 = atoi(argv [2]); 
int multiplicacion = numero1 * numero2; 

if(argc < 2){
    printf ("Ha ocurrido un error");
    exit(0); 
}else{
    printf("El resultado de la multiplicación es: %d \n" , multiplicacion); 
}
}