#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

sem_t A, B, C, mutex, s1, s2, s3, control;

int numeroProductos = 0;

void *funcionLinea1(void *args)
{
    int pieza1 = 0;
    while (pieza1 < 20)
    {
        sem_wait(&control);
        sem_wait(&A);
        sem_wait(&B);
        sem_wait(&s1);
        pieza1++;
        printf("Pieza 1: %d\n", pieza1);
        sem_post(&s2);
        sem_post(&A);
        sem_post(&B);
        sem_post(&control);
    }
}
void *funcionLinea2(void *args)
{
    int pieza2 = 0;
    while (pieza2 < 20)
    {
        sem_wait(&control);
        sem_wait(&B);
        sem_wait(&C);
        sem_wait(&s2);
        pieza2++;
        printf("Pieza 2: %d\n", pieza2);
        sem_post(&s3);
        sem_post(&B);
        sem_post(&C);
        sem_post(&control);
    }
}
void *funcionLinea3(void *args)
{

    int pieza3 = 0;
    while (pieza3 < 20)
    {
        sem_wait(&control);
        sem_wait(&C);
        sem_wait(&A);
        sem_wait(&s3);
        pieza3++;
        printf("Pieza 3: %d\n", pieza3);
        sem_post(&s1);
        sem_post(&A);
        sem_post(&C);
        sem_wait(&mutex);
        numeroProductos++;
        printf("Productos terminados: %d\n", numeroProductos);
        sem_post(&mutex);
        sem_post(&control);
    }
}

void main()
{
    // crear semaforos
    sem_init(&A, 0, 1);
    sem_init(&B, 0, 1);
    sem_init(&C, 0, 1);
    sem_init(&mutex, 0, 1);
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);
    sem_init(&s3, 0, 0);
    sem_init(&control, 0, 2);

    // crear 4 hilos
    pthread_t linea1, linea2, linea3, mutex;

    // inicializar hilos
    pthread_create(&linea1, NULL, funcionLinea1, NULL);
    pthread_create(&linea2, NULL, funcionLinea2, NULL);
    pthread_create(&linea3, NULL, funcionLinea3, NULL);

    // unir hilos
    pthread_join(linea1, NULL);
    pthread_join(linea2, NULL);
    pthread_join(linea3, NULL);
}
