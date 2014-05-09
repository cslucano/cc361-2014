#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

int contador;
sem_t semaforo;

void * productor()
{
    while(1)
    {
        sem_wait(&semaforo);
        printf("p:%d\n", contador++);
        sem_post(&semaforo);
    }
}

void * consumidor()
{
    while(1)
    {
        sem_wait(&semaforo);
        printf("c:%d\n", contador--);
        sem_post(&semaforo);
    }
}
 
int main()
{
    contador = 0;

    pthread_t thread_consumidor;
    pthread_t thread_productor;

    sem_init(&semaforo, 0, 1);

    pthread_create(&thread_consumidor, NULL, consumidor, NULL);
    pthread_create(&thread_productor, NULL, productor, NULL);

    sleep(3000);
 
    return 0;
}

