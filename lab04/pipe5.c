#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[30];
int tuberia[2];

void * productor()
{
    while(scanf("%s", buffer))
    {
        printf("thread productor: escribiendo sobre el pipe\n");
        write(tuberia[1], buffer, strlen(buffer)+1);
    }
}

void * consumidor()
{
    while(read(tuberia[0], buffer, 10))
    {
        printf("thread consumidor: %s\n", buffer);
    }
}
 
int main()
{
    pipe(tuberia);

    pthread_t thread_consumidor;
    pthread_t thread_productor;

    pthread_create(&thread_consumidor, NULL, consumidor, NULL);
    pthread_create(&thread_productor, NULL, productor, NULL);

    sleep(3000);
 
    return 0;
}

