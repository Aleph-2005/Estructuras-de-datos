#include <stdio.h>
#include "queue_DIN.h"
#include <stdlib.h>
 
void init(struct queue* p)
{
    p->frente=NULL;
    p->final=NULL;
}

int isempty_1(struct queue* p)
{
    if(p->frente==NULL)
        return 1;
    return 0;
}

void encolar(struct queue* p, void* z)
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

void* desencolar(struct queue* p)
{
    if(isempty(p))
        return NULL;
    else
    {
         struct Nodo* tmp=p->frente;
         void* z=tmp->dato;
         p->frente=tmp->siguiente;
         if(p->frente==NULL)
            p->final=p->frente;
        free(tmp);
        return z;
    }
}

void imprimircola(struct queue* p,void (print_tp)(void*))
{
    struct Nodo* nuevo=p->frente;
    if(isempty(p))
        printf("vacio\n");
    else
    {
        while (nuevo!=NULL)
        {
            print_tp(nuevo->dato);
            nuevo=nuevo->siguiente;
        }
    }
}

void vaciar(struct queue*p)
{
    while(!isempty(p))
        desencolar(p);
}

int len(struct queue *p)
{
    int n=0;
    struct Nodo* tmp=p->frente;
    while(tmp)
    {
        tmp=tmp->siguiente;
        n++;
    }
    return n;
}