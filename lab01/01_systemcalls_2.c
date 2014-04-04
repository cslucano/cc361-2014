#include <stdlib.h>
#include <stdio.h>

int main() 
{
    FILE* file = fopen("temporal.txt", "wb");
    fclose(file);

    sleep(5);

    return 0;
}
