#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (fork())
    {
        exit(0);
    } 
    
    while (1) {
        fprintf(stderr, "sleep 100 segundos\n");
        sleep(1);
    }

    return 0;
}
