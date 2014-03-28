#include <stdlib.h>
#include <stdio.h>

struct lista
{
    int valor;
    struct lista * siguiente;
};

int main() 
{
    struct lista * l0 = (struct lista *)malloc(sizeof(struct lista));
    l0->valor = 10;
    l0->siguiente = NULL;

    struct lista * l1 = (struct lista *)malloc(sizeof(struct lista));
    l1->valor = 9;
    l1->siguiente = NULL;
 
    l0->siguiente = l1;

    struct lista * l = l0;
    do {
        printf("%d\n", l->valor);
        l = l->siguiente;  
    } while (l != NULL);

    return 0;
}

