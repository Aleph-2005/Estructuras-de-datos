#include <stdio.h>
#include <stdlib.h>
#include "arbol_binario.h"
#include "queue_DIN.h"

void print_tp(void *l)
{
    printf("%d  ",*(int*)l);
}
void print_tp2(void *l)
{
    printf("%d\n",*(int*)l);
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
        void **r = (void **)desencolar(&lvo);
        if (!r) 
        {
            printf("[nivel vacío]\n");
            continue;
        }
        printf("[ ");
        int i = 0;
        while (r[i]) 
        {
            print_tp(r[i]);
            i++;
        }
        printf("]\n");
    }
    printf("%d\n",height(root));
    printf("%d\n",getLevel(root,&d,1,cmp));
    printf("%d\n",buscarnodo(root,&j,cmp));
    struct nodo_arbol *padre=(struct nodo_arbol*)findparent(root,&b,NULL,cmp);
    print_tp(padre->dato);
    printf("\n");
    struct nodo_arbol *nuevo=copiar_subarbol(dos);
    struct queue lvo2=LVO(nuevo);
    while (!isempty(&lvo2)) 
    {
        void **r = (void **)desencolar(&lvo2);
        if (!r) 
        {
            printf("[nivel vacío]\n");
            continue;
        }
        printf("[ ");
        int i = 0;
        while (r[i]) 
        {
            print_tp(r[i]);  // r[i] debe ser puntero a int
            i++;
        }
        printf("]\n");
    }

    struct queue leafs=leaf(root);
    imprimircola(&leafs,print_tp);
    printf("\n");
    insert_nodo(root,&j);
    struct queue lvo3=LVO(root);
    while (!isempty(&lvo3)) 
    {
        void **r = (void **)desencolar(&lvo3);
        if (!r) 
        {
            printf("[nivel vacío]\n");
            continue;
        }
        printf("[ ");
        int i = 0;
        while (r[i]) 
        {
            print_tp(r[i]);  // r[i] debe ser puntero a int
            i++;
        }
        printf("]\n");
    }
    arboleliminado(root,&c);
    struct queue lvo4=LVO(root);
     while (!isempty(&lvo4)) 
    {
        void **r = (void **)desencolar(&lvo4);
        if (!r) 
        {
            printf("[nivel vacío]\n");
            continue;
        }
        printf("[ ");
        int i = 0;
        while (r[i]) 
        {
            print_tp(r[i]);  // r[i] debe ser puntero a int
            i++;
        }
        printf("]\n");
    }
    vaciar(&lvo);
    vaciar(&lvo2);
    vaciar(&leafs);
    vaciar(&lvo3);
    vaciar(&lvo4);
}