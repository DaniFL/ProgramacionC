#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void main(){
    char c; 
    c = getchar();
    read(0, &c, 1);
}

void main(){
    char c; 
    c = "a";
    putchar(c);
    write(1, &c, 1);
}