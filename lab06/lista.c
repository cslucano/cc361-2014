#include <stdio.h>
#include <stdlib.h>

typedef struct ElementoLista {
    char *dato;
    struct ElementoLista *siguiente;
} Elemento;

typedef struct ListaIdentificar {
    Elemento *inicio;
    Elemento *fin;
    int num_elementos;
} Lista;

void initLista(Lista * lst)
{
    lst->inicio = NULL;
    lst->fin = NULL;
    lst->num_elementos = 0;
}

void insertar(Lista * lst, char * c)
{
    Elemento * nuevoElemento = (Elemento*)malloc(sizeof(Elemento));
    nuevoElemento->dato = c;
    nuevoElemento->siguiente = NULL;

    if (lst->fin == NULL) {
        lst->inicio = nuevoElemento;
        lst->fin = nuevoElemento;
    } else {
        Elemento * ele = lst->fin;
        ele->siguiente = nuevoElemento;
        lst->fin = nuevoElemento;
    }
    lst->num_elementos++;
}

void imprimirLista(Lista * lst);
void * llenarLista(Lista * lst)
{
    while(1)
    {
        char * c = (char*)malloc(sizeof(char));
        *c = 'a' + (int)random()%26;
        
        insertar(lst, c);
        imprimirLista(lst);
        sleep(1);
    }
}

void imprimirLista(Lista * lst)
{
    Elemento * ele = lst->inicio;
    while(ele != NULL)
    {
        printf("%c ", *(ele->dato));
        ele = ele->siguiente;
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    Lista* lst = (Lista*)malloc(sizeof(Lista));
    initLista(lst);

    pthread_t thread_1;
    pthread_t thread_2;
    pthread_create(&thread_1, NULL, llenarLista, lst);
    pthread_create(&thread_2, NULL, llenarLista, lst);

    int ret;
    pthread_join(&thread_1, (void *)&ret);
    sleep(300);

    return 0;
}

