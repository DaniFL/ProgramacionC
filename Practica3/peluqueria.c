#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <semaphore.h>

sem_t aforo, peluquero, cliente, mutex;
// Semáforo para controlar el aforo
// Semáforo para controlar el peluquero (silla)
// Semáforo para controlar el cliente (sofa + de pie)
// Semáforo para controlar variables comunes

int clientes = 0;

void *funcionPeluquero(void *args)
{
    sem_wait(peluquero); // Espera a que haya clientes
    sleep(5);            // Peluquero pasa a dormir
    sem_post(cliente);   // Libera el cliente
    sem_post(peluquero); // Libera el peluquero
}

void *funcionCliente(void *args)
{
    sem_wait(aforo); // Espera a que haya lugar en el aforo
    sem_wait(mutex); // Espera a que no haya otro cliente
    clientes++;      // Incrementa el número de clientes
    printf("Cliente %d entra al aforo\n", clientes);
    sem_post(mutex);     // Libera el mutex
    sem_post(peluquero); // Libera el peluquero
    sem_wait(cliente);   // Espera a que el peluquero pase a dormir
    sem_wait(mutex);     // Espera a que no haya otro cliente
    clientes--;          // Decrementa el número de clientes
    printf("Cliente %d sale del aforo\n", clientes);
    sem_post(mutex); // Libera el mutex
    sem_post(aforo); // Libera el aforo
}

void main()
{
    // inicializar semáforos
    sem_init(&aforo, 0, 20);
    sem_init(&peluquero, 0, 0);
    sem_init(&cliente, 0, 0);
    sem_init(&mutex, 0, 1);
    // crear 50 hilos (clientes)
    pthread_t clientes[50];
    // inicialzar hilos
    for (int i = 0; i < 50; i++)
    {
        pthread_create(&clientes[i], NULL, funcionCliente, NULL);
    }
    // unir hilos
    for (int i = 0; i < 50; i++)
    {
        pthread_join(clientes[i], NULL);
    }

    // crear hilo peluquero
    pthread_t peluquero;
    pthread_create(&peluquero, NULL, funcionPeluquero, NULL);
    // unir hilo peluquero
    pthread_join(peluquero, NULL);
}
