#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("listamos los archivos\n");

    if (fork())
    {
        exit(0);
    } else {
        char * argumentos[2];
        argumentos[0] = strdup("ls");
        argumentos[1] = NULL;
        execvp(argumentos[0], argumentos);
    }

    return 0;
}
