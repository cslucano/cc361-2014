#include <stdlib.h>
#include <stdio.h>

int main() {
    int x = 5;
    int y = 2;

    int z = x + y;
    
    printf("%d + %d = %d\n", x, y, z);

    // imprimimos las direcciones de las variables
    printf("dirección de main : %p\n", main);

    // imprimimos las direcciones de las variables
    printf("dirección de x : %p\n", &x);
    printf("dirección de y : %p\n", &y);
    printf("dirección de z : %p\n", &z);

    return 0; 
}

