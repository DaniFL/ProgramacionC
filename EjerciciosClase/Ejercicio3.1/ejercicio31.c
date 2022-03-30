#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void main(void) {

    printf("Soy el proceso padre y mi Pid es: %d\n", getpid());
    pid_t pid = fork();
    if (pid == 0){
    printf("Soy el proceso hijo y mi Pid es: %d\n", getpid());
    }
}