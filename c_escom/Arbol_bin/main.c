#include <stdio.h>
#include <stdlib.h>
#include "arbol_binario.h"

void print_tp(void *l)
{
    printf("%d  ",*(int*)l);
}

int main()
{
    int a=1, b=2, c=3, d=4, e=5, f=6, g=7;
    struct nodo_arbol* root=crearnodo(&a);  
    struct nodo_arbol* dos=crearnodo(&b);
    struct nodo_arbol* tres=crearnodo(&c);
    struct nodo_arbol* cuatro=crearnodo(&d);
    struct nodo_arbol* cinco=crearnodo(&e);
    struct nodo_arbol* seis=crearnodo(&f);
    struct nodo_arbol* siete=crearnodo(&g);
    root->izq=dos;
    root->der=tres;
    dos->izq=cuatro;
    dos->der=cinco;
    tres->der=siete;
    tres->izq=seis;
    BFS(root, print_tp);
}