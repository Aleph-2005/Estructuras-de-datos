#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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

struct nodo* crearnodo(int dat)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->dato=dat;
    nuevo->siguiente=NULL;
    return nuevo;
}

void insertinicio(struct lista* p,int valor)
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

void insertfinal(struct lista* p,int valor)
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

void insertn(struct lista* p,int valor,int n)
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
        nuevo->siguiente=tmp->siguiente;    
        tmp->siguiente=nuevo;
        if(tmp1<n-1)
            printf("imposible insertar en la posiscion %d\n",n);
    }
}

void imprimirlista(struct lista*p)
{
    struct nodo* tmp=p->frente;
    if(isempty(p))
        printf("Vacio\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("%d\n",tmp->dato);
            tmp=tmp->siguiente;
        }
    }
}

int eliminarfrente(struct lista* p){
    if (isempty(p))
    {
       printf("NO se puede sacar nada");
       return -1;/* code */
    }
    int valor =p->frente->dato;
    struct nodo* tmp=p->frente;
    p->frente=tmp->siguiente;
    free(tmp);

    return valor;
}

int eliminarFinal(struct lista*p){
    int valor;
    
    if (isempty(p))
    {
       printf("NO le sabes");
       return -1;/* code */
    }

    struct nodo* tmp=p->frente;

    if ((p->frente)->siguiente == NULL)
    {
       int valor = p->frente-> dato;
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
     int valor= aux-> dato;
     tmp->siguiente=NULL;
     free(aux);
     return valor;   /* code */
    }
}

int eliminarPosicion(struct lista* p, int n)
{
    if (isempty(p))
    {
       printf("Lista vacia");
       return -1;  
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
        return -1;
    }
    else
    {
        struct nodo*aux=tmp->siguiente;
        int valor=aux->dato;
        tmp->siguiente=aux->siguiente;
        free(aux);
        return valor;
    }
}

