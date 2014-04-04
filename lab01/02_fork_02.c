#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("antes de crear un proceso hijo\n");
    printf("proceso padre PID(%d)\n", getpid());

    if (fork())
    {
        printf("Proceso padre %d\n", getpid());
        exit(0);
    } else {
        printf("Proceso hijo %d\n", getpid());
    }

    printf("sleep 100 segundos\n");
    sleep(100);

    return 0;
}
