#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("antes de crear un proceso hijo\n");
    printf("proceso padre PID(%d)\n", getpid());

    if (fork())
    {
        printf("Proceso padre %d\n", getpid());
    } else {
        printf("Proceso hijo %d\n", getpid());
    }

    sleep(100);

    return 0;
}
