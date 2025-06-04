# include <stdio.h>
#include <malloc.h>
# include "pila_din.h"

void init(struct pila *p)
{
    p->tope=NULL;
}

int isEmpty(struct nodo* tope)
{
    if(tope==NULL)
        return 1;
    return 0;
}

void push(int l,struct nodo**tope)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->valor=l;
    nuevo->siguiente=*tope;
    *tope=nuevo;
}

int pop(struct nodo**tope)
{
    if(isEmpty(*tope))
        return -1;
    struct nodo* tmp=*tope;
    int val=tmp->valor;
    *tope=tmp->siguiente;
    free(tmp);
    return val;
}

void imprimirpila(struct nodo*tope)
{
    struct nodo* tmp=tope;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->valor);
        tmp=tmp->siguiente;
    }
}