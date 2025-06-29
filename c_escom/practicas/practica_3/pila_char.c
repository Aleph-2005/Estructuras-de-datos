# include <stdio.h>
#include <malloc.h>
# include "pila_char.h"

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

void push(char l,struct pila *p)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->valor=l;
    nuevo->siguiente=p->tope;
    p->tope=nuevo;
}

char pop(struct pila *p)
{
    if(isEmpty(p))
        return -1;
    struct nodo* tmp=p->tope;
    char val=tmp->valor;
    p->tope=tmp->siguiente;
    free(tmp);
    return val;
}

void imprimirpila(struct pila *p)
{
    struct nodo* tmp=p->tope;
    while(tmp!=NULL)
    {
        printf("%c ",tmp->valor);
        tmp=tmp->siguiente;
    }
}

void vaciar(struct pila* p,char* new,int* r)
{
      while((!isEmpty(p)))
    {
        *(new+*r)=pop(p);
        *r=*r+1;
    }
}