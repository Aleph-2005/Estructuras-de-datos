# include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void push(char* l,struct pila *p)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->valor=strdup(l);
    nuevo->siguiente=p->tope;
    p->tope=nuevo;
}

char* pop(struct pila *p)
{
    if(isEmpty(p))
        return NULL;
    struct nodo* tmp=p->tope;
    char* val=tmp->valor;
    p->tope=tmp->siguiente;
    free(tmp);
    return val;
}

void imprimirpila(struct pila *p)
{
    struct nodo* tmp=p->tope;
    while(tmp!=NULL)
    {
        printf("%s ",tmp->valor);
        tmp=tmp->siguiente;
    }
}

void destroy(struct pila *p) 
{
    while (!isEmpty(p)) 
    {
        char* val = pop(p);
        free(val);  // Liberamos la cadena
    }
}
