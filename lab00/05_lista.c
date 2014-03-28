#include <stdlib.h>
#include <stdio.h>

typedef struct lista_ lista;
struct lista_
{
    int valor;
    struct lista_ * siguiente;
};

lista * nuevo_elemento(int valor)
{
    lista * l = (lista *)malloc(sizeof(lista));
    l->valor = valor;
    l->siguiente = NULL;

    return l;
}

void imprimir_lista(lista * l) 
{
    do {
        printf("%p\n", l);
        printf("%d\n", l->valor);
        printf("\n");
        l = l->siguiente;  
    } while (l != NULL);
}

int main() 
{
    lista * l0 = (lista*)nuevo_elemento(10);
    lista * l1 = (lista*)nuevo_elemento(9);
    lista * l2 = (lista*)nuevo_elemento(8);
    lista * l3 = (lista*)nuevo_elemento(7);

    l0->siguiente = l1;
    l1->siguiente = l2;
    l2->siguiente = l3;

    imprimir_lista(l0);

    return 0;
}

