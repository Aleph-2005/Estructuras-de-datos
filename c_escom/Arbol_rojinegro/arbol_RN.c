#include <stdlib.h>
#include <stdio.h>
#include "arbol_RN.h"
//1->rojo
//0->negro

struct nodo_RN* crearnodo(void* val,int color)
{
    struct nodo_RN* nuevo=(struct nodo_RN*)malloc(sizeof(struct nodo_RN));
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
        nuevo->pad=NULL;
        nuevo->color=color;
        return nuevo;
    }
}

struct nodo_RN* crearnodoapuntado(void* val,struct nodo_RN* izq,struct nodo_RN* der,struct nodo_RN* pad,int color)
{
    struct nodo_RN* nuevo=(struct nodo_RN*)malloc(sizeof(struct nodo_RN));
    if(!nuevo)
    {
        printf("no se pudo asignar meemoria");
        return NULL;
    }
    else
    {
        nuevo->dato=val;
        nuevo->izq=izq;
        nuevo->pad=pad;
        nuevo->der=der;
        nuevo->color=color;
        return nuevo;
    }
}

void right_rotate_RN(struct nodo_RN* x,struct nodo_RN** root)
{
    if(!(x)||!(x->izq))
        return;
    else
    {
        struct nodo_RN*y=x->izq;
        x->izq=y->der;
        if(y->der)
            y->der->pad=x;
        y->pad=x->pad;
        if(!(x->pad))
            *root=y;
        else if(x==x->pad->der)
            x->pad->der=y;
        else
            x->pad->izq=y;
        y->der=x;
        x->pad=y;
    }
}

void left_rotate_RN(struct nodo_RN*x,struct nodo_RN** root)
{
     if(!(x)||!(x->der))
        return;
    else
    {
        struct nodo_RN*y=x->der;
        x->der=y->izq;
        if(y->izq)
            y->izq->pad=x;
        y->pad=x->pad;
        if(!(x->pad))
            *root=y;
        else if(x==x->pad->der)
            x->pad->der=y;
        else
            x->pad->izq=y;
        y->izq=x;
        x->pad=y;
    }
}

void fix_insert_RN(struct nodo_RN** root,struct nodo_RN* nuevo)
{
    while(nuevo!=*root && nuevo->pad->color==1)
    {
        struct nodo_RN* padre=nuevo->pad;
        struct nodo_RN* abuelo=padre->pad;
        if(!abuelo)
            break;
        //padre es hijo izquierdo
        if(padre==abuelo->izq)
        {
            struct nodo_RN* tio=abuelo->der;
            //caso 1
            if((tio)&&(tio->color==1))
            {
                padre->color=0;
                tio->color=0;
                abuelo->color=1;
                nuevo=abuelo;
            }
            else 
            {
                //caso 2
                if(nuevo==padre->der)
                {
                    nuevo=padre;
                    left_rotate_RN(padre,root);
                }
                //caso:3
                else
                {
                    padre->color=0;
                    abuelo->color=1;
                    right_rotate_RN(abuelo,root);
                }
            }
        }
        else
        {
            struct nodo_RN* tio=abuelo->izq;
            //caso 1 simetrico
            if((padre) && (tio)&&(tio->color==1))
            {
                padre->color=0;
                tio->color=0;
                abuelo->color=1;
                nuevo=abuelo;
            }
            else 
            {
                //caso 2 simetrico
                if(nuevo==padre->izq)
                {
                    nuevo=padre;
                    right_rotate_RN(padre,root);
                }
                //caso 3 simetrico
                else
                {
                    padre->color=0;
                    abuelo->color=1;
                    left_rotate_RN(abuelo,root);
                }
            }
        }
    }
    (*root)->color=0;
}

struct nodo_RN* insert_nodo(struct nodo_RN* root, void* dato, int (*cmp)(void*, void*)) 
{
    struct nodo_RN* actual = root;
    struct nodo_RN* padre = NULL;

    while (actual)//hasta llegar a una hoja 
    {
        padre = actual;//padre a raiz
        if (cmp(dato, actual->dato) < 0)//Dependiendo de la funcion cmp decidimos sobre que hijo ir
            actual = actual->izq;
        else
            actual = actual->der;
    }

    struct nodo_RN* nuevo = crearnodo(dato, 1); // rojo
    nuevo->pad = padre;//nos situamos sobre el punto donde añadiremos al nuevo nodo

    if (!padre)
    {
        nuevo->color=0;//es raiz
        return nuevo; // nuevo nodo es raíz
    }
    else if (cmp(dato, padre->dato) < 0)// segun cmp decidimos sobre que hijo debera ir nuestro nuevo nodo
        padre->izq = nuevo;
    else
        padre->der = nuevo;

    fix_insert_RN(&root, nuevo);
    return root;
}



void exportar_dot(struct nodo_RN* raiz, FILE* f) 
{
    if (!raiz) return;

    if(raiz->color==1)
        fprintf(f,"%d [fillcolor=red, fontcolor=white];\n",*((int*)raiz->dato));
    else
        fprintf(f,"%d [fillcolor=black, fontcolor=white];\n",*((int*)raiz->dato));
    
    if (raiz->izq) 
    {
        fprintf(f, "\"%d\" -- \"%d\";\n",*((int*)raiz->dato), *((int*)raiz->izq->dato));
        exportar_dot(raiz->izq, f);
    }
    if (raiz->der) 
    {
        fprintf(f, "\"%d\" -- \"%d\";\n",*((int*)raiz->dato), *((int*)raiz->der->dato));
        exportar_dot(raiz->der, f);
    }
}

void ExportaGraphizint(struct nodo_RN* raiz)
{
     FILE* f = fopen("Arbol.dot", "w");
    if (!f) {
        perror("No se pudo abrir el archivo");
        return;
    }
    fprintf(f, "graph Arbol {\n");
    fprintf(f, "    layout=neato;\n");
    fprintf(f, "    overlap=false;\n");
    fprintf(f, "    splines=true;\n");
    fprintf(f, "    nodesep=0.4;\n");
    fprintf(f, "    ranksep=0.6;\n");
    fprintf(f, "    node [\n");
    fprintf(f, "        shape=circle,\n");
    fprintf(f, "        style=filled,\n");
    fprintf(f, "        fillcolor=white,\n");
    fprintf(f, "        color=black,\n");
    fprintf(f, "        fontcolor=black,\n");
    fprintf(f, "        fontsize=10,\n");
    fprintf(f, "        width=0.3,\n");
    fprintf(f, "        height=0.3,\n");
    fprintf(f, "        fixedsize=true\n");
    fprintf(f, "    ];\n\n");
    fprintf(f,"node [shape=circle, style=filled];\n");
    exportar_dot(raiz,f);
    fprintf(f, "}\n");
    fclose(f);
}