#include <stdio.h>
#include <stdlib.h>
#include "lista_SE.h"

void init (struct lista* p)
{
    p->frente=NULL;
}

int isempty(struct lista* p)
{
    if(p->frente==NULL)
        return 1; 
    return 0;
}

struct nodo* crearnodo(void* dat)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=dat;
    nuevo->color=0;
    nuevo->siguiente=NULL;
    return nuevo;
}

void insertinicio(struct lista* p,void* valor)
{
    struct nodo* nuevo=crearnodo(valor);
    if(isempty(p))
        p->frente=nuevo;
    else
    {
        nuevo->siguiente=p->frente;
        p->frente=nuevo;
    }
}

void insertfinal(struct lista* p,void* valor)
{
    struct nodo*nuevo=crearnodo(valor);
    if(isempty(p))
        p->frente=nuevo;
    else
    {
        struct nodo* tmp=p->frente;
        while(tmp->siguiente!=NULL)
            tmp=tmp->siguiente;
        tmp->siguiente=nuevo;
    }
}

void insertn(struct lista* p,void* valor,int n)
{
    struct nodo*nuevo=crearnodo(valor);
    if(isempty(p))
        p->frente=nuevo;
    else
    {   
        int tmp1=-1;
        struct nodo* tmp=p->frente;
        while((tmp->siguiente!=NULL)&(tmp1<n-1))
        {
            tmp=tmp->siguiente;
            tmp1++;
        }
        if(tmp1<n-1)
            printf("imposible insertar en la posiscion %d\n",n);
        else
        {
        nuevo->siguiente=tmp->siguiente;    
        tmp->siguiente=nuevo;
        }
    }
}

void imprimirlista(struct lista*p,void(print_tp)(void*))
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
        printf("->/0\n");
    }
}

void* eliminarfrente(struct lista* p){
    if (isempty(p))
    {
       printf("NO se puede sacar nada");
       return NULL;/* code */
    }
    void* valor =p->frente->dato;
    struct nodo* tmp=p->frente;
    p->frente=tmp->siguiente;
    free(tmp);

    return valor;
}

void* eliminarFinal(struct lista*p){
    int valor;
    
    if (isempty(p))
    {
       printf("NO le sabes");
       return NULL;/* code */
    }

    struct nodo* tmp=p->frente;

    if ((p->frente)->siguiente == NULL)
    {
       void* valor = p->frente-> dato;
       p->frente=NULL;
       free(tmp);
       return valor;/* code */
    }
    else
    {
     while ((tmp->siguiente)-> siguiente != NULL)
     {
       tmp = tmp->siguiente;
     }
     struct nodo* aux=tmp->siguiente;
     void* valor= aux-> dato;
     tmp->siguiente=NULL;
     free(aux);
     return valor;   /* code */
    }
}

void* eliminarPosicion(struct lista* p, int n)
{
    if (isempty(p))
    {
       printf("Lista vacia");
       return NULL;  
    }
    
    if(n==0)
        eliminarfrente(p);
    int cont=0;
    struct nodo *tmp=p->frente;
    while((tmp->siguiente!=NULL)&(cont<n-1))
    {
        tmp=tmp->siguiente;
        cont++;
    }
    if(cont<n-1)
    {
        printf("No se puede eliminar esa posicion");
        return NULL;
    }
    else
    {
        struct nodo*aux=tmp->siguiente;
        void* valor=aux->dato;
        tmp->siguiente=aux->siguiente;
        free(aux);
        return valor;
    }
}

