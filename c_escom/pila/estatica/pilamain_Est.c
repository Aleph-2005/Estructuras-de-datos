#include <stdio.h>
#include <stdlib.h>
#include "pila_EST.h"
void print_tp(void *l)
{
    printf("%d\n",*(int*)l);
}

int main()
{
    struct pila p;
    inicializar(&p);
    for(int i=0;i<4;i++)
    {
        int *dato = (int *)malloc(sizeof(int));
        *dato = i;
        push( &p,dato);
    }
    imprimirpila(&p,print_tp);
    printf("Eliminamos %d\n",*(int*)pop(&p));
    imprimirpila(&p,print_tp);
    
}