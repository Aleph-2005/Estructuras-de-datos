#include <stdio.h>
#include <stdlib.h>
#include "arbol_binario.h"
#include "queue_DIN.h"

void print_tp(void *l)
{
    printf("%d  ",*(int*)l);
}

int cmp(void* l,void* r)
{
    if(*(int*)l==*(int*)r)
        return 1;
    return 0;
}

int main()
{
    //       1
    //     /   \
    //    2      3
    //   /  \   /  \
    //  4    5  6   7  
    // /  \   
    //8    9
    int a=1, b=2, c=3, d=4, e=5, f=6, g=7,h=8,i=9,j=10;
    struct nodo_arbol* root=crearnodo(&a);  
    struct nodo_arbol* dos=crearnodo(&b);
    struct nodo_arbol* tres=crearnodo(&c);
    struct nodo_arbol* cuatro=crearnodo(&d);
    struct nodo_arbol* cinco=crearnodo(&e);
    struct nodo_arbol* seis=crearnodo(&f);
    struct nodo_arbol* siete=crearnodo(&g);
    struct nodo_arbol* ocho=crearnodo(&h);
    struct nodo_arbol* nueve=crearnodo(&i);
    root->izq=dos;
    root->der=tres;
    dos->izq=cuatro;
    dos->der=cinco;
    tres->der=siete;
    tres->izq=seis;
    cuatro->izq=ocho;
    cuatro->der=nueve;
    struct queue lvo=LVO(root);
    while (!isempty(&lvo)) 
    {
        int **r = (int **)desencolar(&lvo);
        if (!r) {
            printf("[nivel vacío]\n");
            continue;
        }
        printf("[ ");
        int i = 0;
        while (r[i]) {
            printf("%d ", *(r[i]));  // r[i] debe ser puntero a int
            i++;
        }
        printf("]\n");
        //free(r);  // Liberar si fue asignado dinámicamente
    }
    printf("%d\n",height(root));
    printf("%d\n",getLevel(root,&d,1,cmp));
    printf("%d\n",buscarnodo(root,&j,cmp));
    
}