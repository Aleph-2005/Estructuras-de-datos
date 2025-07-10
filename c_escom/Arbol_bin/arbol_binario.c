#include <stdio.h>
#include <stdlib.h>
#include "arbol_binario.h"
#include "queue_DIN.h"

struct nodo_arbol* crearnodo(void* val)
{
    struct nodo_arbol* nuevo=(struct nodo_arbol*)malloc(sizeof(struct nodo_arbol));
    if(!nuevo)
    {
        printf("no se pudo asignar meemoria");
        return NULL;
    }
    else
    {
        nuevo->dato=val;
        nuevo->izq=NULL;
        nuevo->der=NULL;
        return nuevo;
    }
}

struct nodo_arbol* crearnodoapuntado(void* val,struct nodo_arbol* izq,struct nodo_arbol* der)
{
    struct nodo_arbol* nuevo=(struct nodo_arbol*)malloc(sizeof(struct nodo_arbol));
    if(!nuevo)
    {
        printf("no se pudo asignar meemoria");
        return NULL;
    }
    else
    {
        nuevo->dato=val;
        nuevo->izq=izq;
        nuevo->der=der;
        return nuevo;
    }
}

void inorderDFS(struct nodo_arbol* raiz,void (print_type)(void *))
{
    inorder(raiz->izq,print_type);
    printf("El nodo tiene informaci\'on:");
    print_type(raiz->dato);
    inorder(raiz->der,print_type);
}

void preorderDFS(struct nodo_arbol* raiz,void (print_type)(void *))
{
    printf("El nodo tiene informaci\'on:");
    print_type(raiz->dato);
    inorder(raiz->izq,print_type);
    inorder(raiz->der,print_type);
}

void postorderDFS(struct nodo_arbol* raiz,void (print_type)(void *))
{
    inorder(raiz->izq,print_type);
    inorder(raiz->der,print_type);
    printf("El nodo tiene informaci\'on:");
    print_type(raiz->dato);
}

void BFS(struct nodo_arbol* raiz,void (print_type)(void *))
{
    struct queue c;
    init(&c);
    encolar(&c,raiz);
    while(!isempty(&c))
    {
        struct nodo_arbol* nuevo=(struct nodo_arbol*)desencolar(&c);
        print_type(nuevo->dato);
        if(nuevo->izq)
            encolar(&c,nuevo->izq);
        if(nuevo->der)
            encolar(&c,nuevo->der);
    }
}

