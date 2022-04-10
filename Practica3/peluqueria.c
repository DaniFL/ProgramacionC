#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

sem_t aforo, peluquero, silla, sofa, sentado;
// aforo = Semáforo para controlar el aforo (personas dentro de peluquería).
// peluquero = Semáforo para controlar el peluquero.
// silla = Semáforo para controlar la silla (1 persona).
// sofa = Semáforo para controlar el sofa (5 personas).
// sentado = Semáforo para controlar el cliente mierntras el peluquero le corta el pelo.

// peluquero y cliente inicializados a 0
// aforo = permite 20 personas en peluqueria
// problema por capas aforo-sofa-silla-peluquero.
// en funcion peluquero, hay que dormir al peluquero, despertarlo con un cliente.
// tiempo que tarda en cortar pelo == sleep (x seconds)

void *funcionCliente(void *args)
{
    int clienteId = *(int *)args;

    sem_wait(&aforo); // espera a que haya lugar en la peluquería

    printf("Cliente %d entra a la peluqueria\n", clienteId);
    // fflush(stdout); // reinicia contador

    sem_wait(&sofa); // espera a que haya sitio en el sofa (5 personas)
    printf("Cliente %d pasa al sofa\n", clienteId);

    sem_wait(&silla); // espera a que haya sitio en la silla (1 persona)
    printf("Cliente %d pasa a la silla, dejando libre asiento en el sofa\n", clienteId);
    sem_post(&sofa); // desbloquea sofa

    printf("Cliente %d está sentado en la silla\n", clienteId);
    sem_post(&peluquero); // desbloquea peluquero
    printf("Cliente %d despierta al peluquero para que le corte el pelo\n", clienteId);
    sem_wait(&sentado); // espera a que haya sentado el cliente
    printf("Cliente %d termina de cortarse el pelo\n", clienteId);

    sem_post(&silla); // desbloquea silla
    printf("Cliente %d se levanta de la silla\n", clienteId);
    printf("Cliente %d sale de la peluqueria\n", clienteId);
    sem_post(&aforo); // desbloquea aforo
    // fflush(stdout);   // reinicia contador
}

void *funcionPeluquero(void *args)
{
    for (int i = 0; i < 50; i++)
    {
        sem_wait(&peluquero); // bloquea al peluquero hasta que haya un cliente.
        printf("El peluquero está cortando el pelo al cliente %d\n", i);
        sleep(2);           // tiempo que tarda en cortar el pelo
        sem_post(&sentado); // desbloquea al cliente tras haberse cortado el pelo.
    }
}

void main()
{
    // inicializar semáforos
    sem_init(&aforo, 0, 20);    // permite la entrada a 20 personas en la peluquería.
    sem_init(&peluquero, 0, 0); // peluquero etado inicial a 0, ya que necesita de un cliente para despertar.
    sem_init(&silla, 0, 1);     // silla inicialmente disponible para el primer cliente.
    sem_init(&sentado, 0, 0);   // inicialiado a 0 ya que bloquea al cliente mientras se corta el pelo.
    sem_init(&sofa, 0, 5);      // permite sentarse a 5 personas en el sofa.

    // crear 50 hilos (clientes)
    pthread_t clientes[50];

    // inicializar hilos de clientes
    for (int i = 0; i < 50; i++)
    {
        pthread_create(&clientes[i], NULL, funcionCliente, (void *)&i);
        sleep(1);
    }
    // unir hilos clientes
    for (int i = 0; i < 50; i++)
    {
        pthread_join(clientes[i], NULL);
    }

    pthread_t peluquero;                                      // crear hilo peluquero
    pthread_create(&peluquero, NULL, funcionPeluquero, NULL); // inicializar hilo peluquero
    pthread_join(peluquero, NULL);                            // unir hilo peluquero
}
