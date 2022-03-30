#include <stddef.h>
#include <pthread.h>
#include <stdio.h>

/*void * process(void * args){

    printf("%s", (char *) args);
    fflush(stdout);
    pthread_exit(0);
}

int main(){
    pthread_t th_a, th_b,th_c, th_d,th_e, th_f,th_g, th_h; // variable tio thread

    pthread_create(&th_a, NULL, process, "Soy el hilo 1\n");
    pthread_create(&th_b, NULL, process, "Soy el hilo 2\n");
    pthread_create(&th_c, NULL, process, "Soy el hilo 3\n");
    pthread_create(&th_d, NULL, process, "Soy el hilo 4\n");
    pthread_create(&th_e, NULL, process, "Soy el hilo 5\n");
    pthread_create(&th_f, NULL, process, "Soy el hilo 6\n");
    pthread_create(&th_g, NULL, process, "Soy el hilo 7\n");
    pthread_create(&th_h, NULL, process, "Soy el hilo 8\n");

    sleep(1);
}*/


void funcion (void* arg){
    int numeroHilo = *(int*)arg;
    printf("Soy el hilo %d\n", numeroHilo);
}
int main(){ 
    pthread_t th;
pthread_create(&th[i],NULL, process, &i);
    for (int i= 0, i<9, i++){
    pthread_join (th[i], NULL);
    sleep(1);
}
}
