#include <stdio.h>
#include "queue_DIN.h"
#include <malloc.h>
 
void init(struct queue* p)
{
    p->frente=NULL;
    p->final=NULL;
}

int isempty(struct queue* p)
{
    if(p->frente==NULL)
        return 1;
    return 0;
}

void encolar(struct queue* p, int z)
{
    struct Nodo* nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato=z;
    nuevo->siguiente=NULL;
    if(isempty(p))
    {
       p->final=nuevo;
       p->frente=nuevo;
    }
    else
    {
        (p->final)->siguiente=nuevo;
        p->final=nuevo;
    }
}

int desencolar(struct queue* p)
{
    if(isempty(p))
        return -1;
    else
    {
         struct Nodo* tmp=p->frente;
         int z=tmp->dato;
         p->frente=tmp->siguiente;
         if(p->frente==NULL)
            p->final=p->frente;
        free(tmp);
        return z;
    }
}

void imprimircola(struct queue* p)
{
    struct Nodo* nuevo=p->frente;
    if(isempty(p))
        printf("vacio\n");
    else
    {
    while (nuevo!=NULL)
    {
        printf("%d\n",nuevo->dato);
        nuevo=nuevo->siguiente;
    }
    }
}