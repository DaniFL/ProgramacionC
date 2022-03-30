#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

int numero;
printf("Introduce un número:");
scanf("%d", &numero); 

if (numero == 0 || numero == 1){ 
    printf("El número no es primo");
}else if(numero % 1 == 0 && numero % numero == 0){
    printf("El número introducido es primo");
}else{
    printf("El número introducido no es primo");
}
 
}
