#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contador;
pthread_mutex_t mutex;

void * productor()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("p:%d\n", contador++);
        pthread_mutex_unlock(&mutex);
    }
}

void * consumidor()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("c:%d\n", contador--);
        pthread_mutex_unlock(&mutex);
    }
}
 
int main()
{
    contador = 0;

    pthread_t thread_consumidor;
    pthread_t thread_productor;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread_consumidor, NULL, consumidor, NULL);
    pthread_create(&thread_productor, NULL, productor, NULL);

    sleep(3000);
 
    return 0;
}

