#include <stdio.h>
#include "pila_EST.h"

void inicializar(struct pila *p)
{
    p->tope=-1;
}

int isempty(struct pila *p)
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

void push(struct pila *p, int val)
{
    if(isfull(p))
        printf("La pila esta llena");
    else
        p->ele[++(p->tope)]=val;
}

int pop(struct pila *p)
{
    if(isempty(p))
        printf("La pila esta vacia");
    int valor=p->ele[p->tope];
    p->ele[p->tope]=0;
    p->tope--;
    return valor;
}

void imprimirpila(struct pila *p)
{
    for(int i=p->tope;i>-1;i--)
    {
        printf("%d\n",p->ele[i]);
    }
}