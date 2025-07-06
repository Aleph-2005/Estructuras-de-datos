# include <stdio.h>
#include <malloc.h>
# include "pila_din.h"

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

void printstack(struct pila *p,void (print_tp)(void *))
{
    if(isEmpty(p))
        printf("Vacio\n");
    else
    {
        struct nodo* tmp=p->tope;
        while(tmp!=NULL)
        {
            print_tp(tmp->valor);
            tmp=tmp->siguiente;
        }
    }
}

void destroy (struct pila *p)
{
    while(!isEmpty(p))
        pop(p);
}