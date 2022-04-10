#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>

sem_t max_capacidad, sofa, silla, paco, trabajo;

//int aforo = 0;
//int silla = 0;
//int sofa = 0;

void *funcionpeuquero(void *args)
{
    for (int i = 0; i < 50; i++)
    {
        sem_wait(&paco);
        printf("El PELUQUERO esta cortando el pelo\n");
        sleep(2);
        sem_post(&trabajo);
    }
}

void *funcionclientes(void *args)
{
    int numero = *(int*) args;
    sem_wait(&max_capacidad);
    printf("EL cliente %d entra\n", numero);
    fflush(stdout);
    sem_wait(&sofa);
    printf("Soy el cliente %d y me siento en el SOFA\n", numero);
    sem_wait(&silla);
    printf("Soy el cliente %d y me siento en la SILLA\n", numero);
    sem_post(&paco);
    sem_post(&sofa);
    printf("Soy el cliente %d y me MUEVO en el SOFA\n", numero);
    sem_wait(&trabajo);
    printf("Soy el cliente %d YA MA HAN CORTADO EL PELO\n", numero);
    sem_post(&silla);
    printf("Soy el cliente %d ME VOY\n", numero);
    fflush(stdout);
    sem_post(&max_capacidad);
}

void main()
{
    sem_init(&max_capacidad, 0, 20);
    sem_init(&sofa, 0, 5);
    sem_init(&silla, 0, 1);
    sem_init(&paco, 0, 0);
    sem_init(&trabajo, 0, 0);

    pthread_t cliente[50];
    pthread_t peluquero;
    
    for (int i = 0; i < 50; i++)
    {
        pthread_create(&cliente[i], NULL, funcionclientes, (void*)&i);
    }

    pthread_create(&peluquero, NULL, funcionpeuquero, NULL);
    
    for (int i = 0; i < 50; i++)
    {
        pthread_join(cliente[i], NULL);
    }
}