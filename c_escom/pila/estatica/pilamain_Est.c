#include <stdio.h>
#include "pila_EST.h"

int main()
{
    struct pila p;
    inicializar(&p);
    for(int i=0;i<4;i++)
    {
        push(&p,i);
    }
    imprimirpila(&p);
    printf("Eliminamos %d\n",pop(&p));
    imprimirpila(&p);
    
}