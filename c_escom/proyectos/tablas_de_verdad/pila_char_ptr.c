# include <stdio.h>
#include <stdlib.h>
# include "pila_char_ptr.h"

void init(struct pila *p)
{
    p->tope=NULL;
}

int isEmpty(struct pila* p)
{
    if(p->tope==NULL)
        return 1;
    return 0;
}

void push(void* l,struct pila *p)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->valor=l;
    nuevo->siguiente=p->tope;
    p->tope=nuevo;
}

void* pop(struct pila *p)
{
    if(isEmpty(p))
        return NULL;
    struct nodo* tmp=p->tope;
    void* val=tmp->valor;
    p->tope=tmp->siguiente;
    free(tmp);
    return val;
}
