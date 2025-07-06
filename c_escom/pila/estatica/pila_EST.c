#include <stdio.h>
#include "pila_EST.h"

void inicializar(struct pila *p)
{
    p->tope=-1;
}

int isEmpty(struct pila *p)
{
    if(p->tope==-1)
        return 1;
    return 0;
}

int  isfull(struct pila *p)
{
    if(p->tope==MAX-1)
        return 1;
    return 0;
    
}

void push(struct pila *p, void* val)
{
    if(isfull(p))
        printf("La pila esta llena");
    else
        p->ele[++(p->tope)]=val;
}

void* pop(struct pila *p)
{
    if(isEmpty(p))
        printf("La pila esta vacia");
    void * valor=p->ele[p->tope];
    p->ele[p->tope]=0;
    p->tope--;
    return valor;
}

void imprimirpila(struct pila *p,void (print_tp)(void *))
{
    if(isEmpty(p))
        printf("Vacia\n");
    else
    {
        for(int i=p->tope;i>-1;i--)
        {
            print_tp(p->ele[i]);
        }
    }
}