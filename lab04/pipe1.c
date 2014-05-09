#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tuberia[2];
    pipe(tuberia);
    char buffer[30];
    char lorem[] = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n";

    printf("escribimos sobre el pipe %d\n", (int)strlen(lorem));
    
    write(tuberia[1], lorem, strlen(lorem));
    printf("leemos del pipei%d\n", read(tuberia[0], buffer, 10));
    while(read(tuberia[0], buffer, 10))
    {
        printf("%s", buffer);
    }
    
    return 0;
}

