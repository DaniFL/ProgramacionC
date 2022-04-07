#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

sem_t aforo, peluquero, cliente, mutex, sofa, sentado;
// aforo = Semáforo para controlar el aforo (personas dentro de peluquería)
// peluquero = Semáforo para controlar el peluquero (silla)
// cliente = Semáforo para controlar la silla
// mutex = Semáforo para controlar variables comunes
// posible semaforo silla = cliente cortando pelo

// mutex wait inicio y post final método
// peluquero y cliente inicializados a 0
// aforo  = 20 permite 20 personas en peluqueria
// sofa = cliente = 5 personas sentadas en el sofa
// problema por capas aforo-sofa-silla-peluquero.
// en sofa se tienen que meter 5 personas seguidas
// en funcion peluquero hay que dormir al peluquero, despertarlo con un cliente, dormir al cliente y despertarlo con el peluquero
// tiempo que tarda en cortar pelo == sleep (x seconds)

void *funcionPeluquero(void *args)
{
    for (int i = 0; i < 50; i++)
    {
        sem_wait(&peluquero);
        printf("El peluquero está cortando el pelo a un cliente\n");
        sleep(3);
        sem_post(&sentado);
    }
}

void *funcionCliente(void *args)
{
    int numero = *(int *)args;
    sem_wait(&aforo); // Permite entrada peluquería <20
    printf("Cliente %d entra a la peluquería\n", numero);
    fflush(stdout);
    sem_wait(&sofa); // Permite entrada sofa <= 5
    printf("Cliente %d se ha sentado en el sofá\n", numero);
    sem_wait(&cliente);                                           // Permite sentarse en silla peluquero <= 1
    printf("Cliente %d pasa a la silla del peluquero\n", numero); // llega cliente a silla
    sem_post(&sofa);                                              // Se libera sitio en el sofa
    sem_post(&peluquero);                                         // Desbloquea a peluquero
    sem_wait(&sentado);                                           // Se bloquea al cliente mientras se le corta el pelo.
    printf("peluquero ya ha terminado de cortar el pelo\n");
    sem_post(&cliente); // cliente se levanta de la silla.
    printf("Cliente %d se levanta de la silla del peluqero\n", numero);
    sem_post(&aforo); // Cliente se va de la peluquería.
    printf("Cliente %d sale de la peluquería\n", numero);
    fflush(stdout);
}

void main()
{
    // inicializar semáforos
    sem_init(&aforo, 0, 20);
    sem_init(&peluquero, 0, 0);
    sem_init(&sentado, 0, 1);
    sem_init(&cliente, 0, 1);
    sem_init(&mutex, 0, 1);
    sem_init(&sofa, 0, 5);
    // crear 50 hilos (clientes)
    pthread_t clientes[50];
    // inicialzar hilos
    for (int i = 0; i < 50; i++)
    {
        pthread_create(&clientes[i], NULL, funcionCliente, (void *)&i);
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
