#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

sem_t mutex;
sem_t semaforo_espacios_ocupados;
sem_t semaforo_espacios_vacios;

int buffer[50];
int sev; // indice siguiente espacio vacío

void generar()
{
    sem_wait(&mutex);
    buffer[sev] = random();
    sev++;
    sem_post(&mutex);
}

void procesar()
{
    sem_wait(&mutex);
    sev--;
    printf("procesado %d\n", sev);
    sem_post(&mutex);
}

void * productor()
{
    while(1) {
        sem_wait(&semaforo_espacios_vacios);
        generar();
        sem_post(&semaforo_espacios_ocupados);
    }
}
 
void * consumidor()
{
    while(1) {
        sem_wait(&semaforo_espacios_ocupados);
        procesar();
        sem_post(&semaforo_espacios_vacios);
    }
}
 
int main()
{
    sev = 0;

    pthread_t thread_productor;
    pthread_t thread_consumidor;

    sem_init(&mutex, 0, 1);
    sem_init(&semaforo_espacios_ocupados, 0, 0);
    sem_init(&semaforo_espacios_vacios, 0, 50);

    pthread_create(&thread_productor, NULL, productor, NULL);
    pthread_create(&thread_consumidor, NULL, consumidor, NULL);

    void* ret = NULL;
    pthread_join(thread_productor, &ret);
    pthread_join(thread_consumidor, &ret);
 
    return 0;
}

