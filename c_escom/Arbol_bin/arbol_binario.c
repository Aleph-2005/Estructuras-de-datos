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

int max(int a,int b)
{
    if(a>b)
        return a;
    else if(b>a)
        return b;
    else
        return a;
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
    if(!raiz)
        return;
    inorderDFS(raiz->izq,print_type);
    //printf("El nodo tiene informaci\'on:");
    print_type(raiz->dato);
    inorderDFS(raiz->der,print_type);
}

void preorderDFS(struct nodo_arbol* raiz,void (print_type)(void *))
{
    if(!raiz)
        return;
    //printf("El nodo tiene informaci\'on:");
    print_type(raiz->dato);
    preorderDFS(raiz->izq,print_type);
    preorderDFS(raiz->der,print_type);
}

void postorderDFS(struct nodo_arbol* raiz,void (print_type)(void *))
{
    if(!raiz)
        return;
    postorderDFS(raiz->izq,print_type);
    postorderDFS(raiz->der,print_type);
    
    //printf("El nodo tiene informaci\'on:");
    print_type(raiz->dato);
}

void BFS(struct nodo_arbol* raiz,void (print_type)(void *))
{
    if(!raiz)
        return;
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

struct queue LVO(struct nodo_arbol* raiz) 
{
    struct queue lvo;
    init(&lvo);
    struct queue c;
    init(&c);
    if (!raiz) return lvo;
    encolar(&c, raiz);
    while (!isempty(&c)) {
        int nivel_len = len(&c);
        void **nivel_datos = malloc((nivel_len+1) * sizeof(void*));
        for (int i = 0; i < nivel_len; i++) 
        {
            struct nodo_arbol* actual = (struct nodo_arbol*)desencolar(&c);
            nivel_datos[i] =actual->dato;

            if (actual->izq)
                encolar(&c, actual->izq);
            if (actual->der)
                encolar(&c, actual->der);
        }
        nivel_datos[nivel_len]=NULL;
        encolar(&lvo, nivel_datos);  // Encolamos el arreglo de datos del nivel
    }
    return lvo;
}

int height(struct nodo_arbol *root) 
{
    if (!root)
        return -1;
    int lHeight = height(root->izq);
    int rHeight = height(root->der);
    return max(lHeight, rHeight) + 1;
}

int getLevel(struct nodo_arbol*root, void* target,int level,int (*cmp)(void*, void*)) 
{
    if (root == NULL) 
        return -1;
    if (cmp(target,root->dato))
        return level;
    int leftLevel = getLevel(root->izq, target, level + 1,cmp);
    if (leftLevel != -1) 
        return leftLevel;
    return getLevel(root->der, target, level + 1,cmp);
}
int buscarnodo(struct nodo_arbol*root,void*target,int (*cmp)(void*,void*))
{
    if(!root)
        return 0;
    if(cmp(root->dato,target))
        return 1;
    int l=buscarnodo(root->izq,target,cmp);
    if(l)
        return 1;
    int r=buscarnodo(root->der,target,cmp);
    if(r)
        return 1;
    return 0;
}