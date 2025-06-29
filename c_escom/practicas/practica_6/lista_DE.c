#include <stdio.h>
#include <stdlib.h>
#include "lista_DE.h"
#include <string.h>

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

struct nodo* crearnodo(char* nombre,char* primerap,char* segapell,char* matricula)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->nombre=strdup(nombre);
    nuevo->primerap=strdup(primerap);
    nuevo->segapell=strdup(segapell);
    nuevo->matricula=strdup(matricula);
    nuevo->siguiente=NULL;
    nuevo->anterior=NULL;
    return nuevo;
}

void insertinicio(struct lista* p,char* nombre,char* primerap,char* segapell,char* matricula)
{
    struct nodo* nuevo=crearnodo(nombre,primerap,segapell,matricula);
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

void insertfinal(struct lista* p,char*nombre,char*primerap,char* segapell,char* matricula)
{
    struct nodo*nuevo=crearnodo(nombre,primerap,segapell, matricula);
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

void insertn(struct lista* p,char*nombre,char*primerap,char* segapell,char* matricula,int n)
{
    struct nodo*nuevo=crearnodo(nombre,primerap, segapell, matricula);
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

void imprimirlista1(struct lista*p)
{
    struct nodo* tmp=p->frente;
    if(isempty(p))
        printf("Vacio\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("<-> %s\n",tmp->nombre);
            printf("<-> %s\n",tmp->primerap);
            printf("<-> %s\n",tmp->segapell);
            printf("<-> %s\n",tmp->matricula);
            printf("\n");
            tmp=tmp->siguiente;
        }
        printf("<->/0\n");
    }
}

void imprimirlista2(struct lista*p)
{
    struct nodo* tmp=p->final;
    if(isempty(p))
        printf("Vacio\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("<-> %s\n",tmp->nombre);
            printf("<-> %s\n",tmp->primerap);
            printf("<-> %s\n",tmp->segapell);
            printf("<-> %s\n",tmp->matricula);
            printf("\n");
            tmp=tmp->anterior;
        }
        printf("<->/0\n");
    }
}

char* eliminarfrente(struct lista* p){
    if (isempty(p))
    {
       printf("NO se puede sacar nada");
       return NULL;/* code */
    }
    char* valor =(p->frente)->nombre;
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

char* eliminarFinal(struct lista*p){
    if (isempty(p))
    {
       printf("NO le sabes");
       return NULL;/* code */
    }
    
    char* valor=(p->final)->nombre;
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

char* eliminarPosicion(struct lista* p, int n)
{
    if (isempty(p))
    {
       printf("Lista vacia");
       return NULL;  
    }
    char* w;
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
    w=tmp->nombre;
    (tmp->siguiente)->anterior=tmp->anterior;
    (tmp->anterior)->siguiente=tmp->siguiente;
    free(tmp);
    return w;
}

int busqueda(struct lista* p,char* matricula)
{
     if (isempty(p))
    {
       printf("Lista vacia");
       return -1;  
    }
    char* w;
    int cont=0;
    struct nodo *tmp=p->frente;
    while((tmp->siguiente!=NULL)&&(strcasecmp(matricula,tmp->matricula)!=0))
    {
        tmp=tmp->siguiente;
        cont++;
    }
    if((tmp->siguiente==NULL)&&(strcasecmp(matricula,tmp->matricula)!=0))
    {
        return -1;
    }
    else
        return cont;
}