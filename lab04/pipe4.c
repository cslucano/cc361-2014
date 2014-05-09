#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tuberia[2];
    pipe(tuberia);
    char buffer[30];
    char lorem[] = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n";

    if(fork())
    {
        printf("escribimos sobre el pipe \n");
        while(scanf("%s",buffer))
        {
            write(tuberia[1], buffer, strlen(buffer)+1);
        }
    } else {
        printf("leemos del pipe\n");
        
        while(read(tuberia[0], buffer, 10))
        {
            printf("%s\n", buffer);
        }
    }
    
    return 0;
}

