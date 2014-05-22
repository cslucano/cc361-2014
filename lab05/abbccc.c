#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

sem_t semaforo_a;
sem_t semaforo_b;

void * a()
{
    while(1)
    {
        sem_wait(&semaforo_a);
        printf("a\n");
        sem_post(&semaforo_b);
    }
}
 
void * b()
{
    while(1)
    {
        sem_wait(&semaforo_b);
        printf("b\n");
        printf("b\n");
        sem_post(&semaforo_a);
    }
}
 
void * c()
{
    while(1)
    {
        //sem_wait(&semaforo);
        printf("c\n");
        printf("c\n");
        printf("c\n");
        //sem_post(&semaforo);
    }
}
 
int main()
{
    pthread_t thread_a;
    pthread_t thread_b;
    pthread_t thread_c;

    sem_init(&semaforo_a, 0, 1);
    sem_init(&semaforo_b, 0, 0);

    pthread_create(&thread_a, NULL, a, NULL);
    pthread_create(&thread_b, NULL, b, NULL);
    //pthread_create(&thread_c, NULL, c, NULL);

    void* ret = NULL;
    pthread_join(thread_a, &ret);
 
    return 0;
}

