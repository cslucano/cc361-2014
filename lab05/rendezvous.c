#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

sem_t semaforo_enamorado;
sem_t semaforo_enamorada;

void * enamorado()
{
    printf("sentencia a\n");
    sem_post(&semaforo_enamorada);
    sem_wait(&semaforo_enamorado);
    //---------------------------------------
    printf("sentencia b\n");
}
 
void * enamorada()
{
    printf("sentencia m\n");
    sem_post(&semaforo_enamorado);
    sem_wait(&semaforo_enamorada);
    //---------------------------------------
    printf("sentencia n\n");
}
 
int main()
{
    pthread_t thread_enamorado;
    pthread_t thread_enamorada;

    sem_init(&semaforo_enamorado, 0, 0);
    sem_init(&semaforo_enamorada, 0, 0);

    pthread_create(&thread_enamorado, NULL, enamorado, NULL);
    pthread_create(&thread_enamorada, NULL, enamorada, NULL);

    void* ret = NULL;
    pthread_join(thread_enamorado, &ret);
    pthread_join(thread_enamorada, &ret);
 
    return 0;
}

