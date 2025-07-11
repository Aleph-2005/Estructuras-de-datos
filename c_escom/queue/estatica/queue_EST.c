#include <stdio.h>
#include <stdlib.h>
#include "queue_EST.h"

void init(struct queue *p)
{
    p->tope=-1;
    p->final=-1;
}

int isEmpty(struct queue *p)
{
    if(p->tope==-1)
    {
        return 1;
    }
    return 0;
}

int isfull(struct queue *p)
{
    if(p->final==MAX-1)
    {
        return 1;
    }
    return 0;
    
}

void encolar(struct queue *p, void*val)
{
    if(isfull(p))
    {
        printf("La cola esta llena");
    }
    if(isEmpty(p))
    {
      p->ele[++(p->final)]=val;
      ++(p->tope);
    }
    else
    {
       p->ele[++(p->final)]=val;
    }
}

void* desencolar(struct queue *p)
{
    if(isEmpty(p))
    {
        return NULL;
    }
    else
    {
      void* tmp=p->ele[(p->tope)];
      (p->tope)++;
      if(p->final<p->tope)
      {
        (p->tope)=(p->final)=-1;
      }
      return tmp;
    }
}

void imprimircola(struct queue *p,void (print_tp)(void *))
{
    if(isEmpty(p))
        printf("Vacia\n");
    else
    {
        for(int i=p->tope;i<=p->final;i++)
        {
            print_tp(p->ele[i]);
        }
    }
}