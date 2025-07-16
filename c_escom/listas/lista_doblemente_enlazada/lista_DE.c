#include <stdio.h>
#include <stdlib.h>
#include "lista_DE.h"

void init (struct lista* p)
{
    p->frente=NULL;
    p->final=NULL;
}

int isempty(struct lista* p)
{
    if(p->frente==NULL)
        return 1; 
    return 0;
}

struct nodo* crearnodo(void* dato)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    nuevo->anterior=NULL;
    return nuevo;
}

void insertinicio(struct lista* p,void* valor)
{
    struct nodo* nuevo=crearnodo(valor);
    if(isempty(p))
    {
        p->frente=nuevo;
        p->final=nuevo;
    }
    else
    {
        nuevo->siguiente=p->frente;
        (p->frente)->anterior=nuevo;
        p->frente=nuevo;
    }
}

void insertfinal(struct lista* p,void* valor)
{
    struct nodo*nuevo=crearnodo(valor);
    if(isempty(p))
    {
        p->frente=nuevo;
        p->final=nuevo;
    }
    else
    {
        (p->final)->siguiente=nuevo;
        nuevo->anterior=p->final;
        p->final=nuevo;
    }
}

void insertn(struct lista* p,void* valor,int n)
{
    struct nodo*nuevo=crearnodo(valor);
    if(isempty(p))
    {
        p->frente=nuevo;
        p->final=nuevo;
    }

    else
    {   
        int tmp1=-1;
        struct nodo* tmp=p->frente;
        while((tmp->siguiente!=NULL)&(tmp1<=n-1))
        {
            tmp=tmp->siguiente;
            tmp1++;
        }
        if(tmp1<n-1)
            printf("imposible insertar en la posiscion %d\n",n);
        else
        {
            nuevo->anterior=tmp->anterior;
            nuevo->siguiente=tmp;
            (tmp->anterior)->siguiente=nuevo;
            tmp->anterior=nuevo;
        }
    }
}

void imprimirlista1(struct lista*p,void (print_tp)(void *))
{
    struct nodo* tmp=p->frente;
    if(isempty(p))
        printf("Vacio\n");
    else
    {
        while(tmp!=NULL)
        {
            print_tp(tmp->dato);
            tmp=tmp->siguiente;
        }
        printf("<->/0\n");
    }
}

void imprimirlista2(struct lista*p,void (print_tp)(void *))
{
    struct nodo* tmp=p->final;
    if(isempty(p))
        printf("Vacio\n");
    else
    {
        while(tmp!=NULL)
        {
            print_tp(tmp->dato);
            tmp=tmp->anterior;
        }
        printf("<->/0\n");
    }
}

void* eliminarfrente(struct lista* p)
{
    if (isempty(p))
    {
       printf("NO se puede sacar nada");
       return NULL;/* code */
    }
    void* valor =(p->frente)->dato;
    struct nodo* tmp=p->frente;
    p->frente=tmp->siguiente;
    if(isempty(p))
    {
        p->final=NULL;
        return valor;
    }
    (p->frente)->anterior=tmp->anterior;
    free(tmp);

    return valor;
}

void* eliminarFinal(struct lista*p)
{
    if (isempty(p))
    {
       printf("NO le sabes");
       return NULL;/* code */
    }
    
    void* valor=(p->final)->dato;
    struct nodo* tmp=p->final;
    if(tmp->anterior==NULL)
    {
        eliminarfrente(p);
    }
    else
    {
        p->final=tmp->anterior;
        (p->final)->siguiente=tmp->siguiente;
        free(tmp);
        return valor;
    }
}

void* eliminarPosicion(struct lista* p, int n)
{
    if (isempty(p))
    {
       printf("Lista vacia");
       return NULL;  
    }
    void* w;
    if(n==0)
    {
       w=eliminarfrente(p);
       return w;
    }
    int cont=0;
    struct nodo *tmp=p->frente;
    while((tmp->siguiente!=NULL)&(cont<=n-1))
    {
        tmp=tmp->siguiente;
        cont++;
    }
    if(cont<n-1)
    {
        printf("No se puede eliminar\n");
        return NULL;
    }
    if(tmp->siguiente==NULL)
    {
        w=eliminarFinal(p);
        return w;
    }
    w=tmp->dato;
    (tmp->siguiente)->anterior=tmp->anterior;
    (tmp->anterior)->siguiente=tmp->siguiente;
    free(tmp);
    return w;
}
