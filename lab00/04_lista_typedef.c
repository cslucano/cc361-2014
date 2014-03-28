#include <stdlib.h>
#include <stdio.h>

typedef struct lista_ lista;
struct lista_
{
    int valor;
    struct lista_ * siguiente;
};

int main() 
{
    lista * l0 = (lista *)malloc(sizeof(lista));
    l0->valor = 10;
    l0->siguiente = NULL;

    lista * l1 = (lista *)malloc(sizeof(lista));
    l1->valor = 9;
    l1->siguiente = NULL;
 
    l0->siguiente = l1;

    lista * l = l0;
    do {
        printf("%d\n", l->valor);
        l = l->siguiente;  
    } while (l != NULL);

    return 0;
}

