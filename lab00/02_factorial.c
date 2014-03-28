#include <stdlib.h>
#include <stdio.h>

int factorial(int n)
{
    printf("dirección de n : %p\n", &n);
    printf("dirección de factorial : %p\n", factorial);

    if (n > 1) {
        return n * factorial(n-1);
    }
    
    return 1;   
}

int main() {
    int x = 5;

    printf("factorial(%d) = %d\n", x, factorial(x));

    printf("dirección de main : %p\n", main);
    printf("dirección de factorial : %p\n", factorial);

    printf("dirección de x : %p\n", &x);

    return 0; 
}

