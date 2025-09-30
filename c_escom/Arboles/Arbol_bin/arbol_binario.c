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
    if (!raiz) 
        return lvo;
    encolar(&c, raiz);
    while (!isempty(&c)) 
    {
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

void* findparent(struct nodo_arbol*root,void* target,void* padre,int (*cmp)(void*,void*))
{
    if(!root)
        return NULL;
    if(cmp(target,root->dato))
        return padre;
    void* izq=findparent(root->izq,target,root,cmp);
    if(izq)
        return izq;
    void* der=findparent(root->der,target,root,cmp);
    if(der)
        return der;
    return NULL;
}

struct nodo_arbol* copiar_subarbol(struct nodo_arbol* raiz)
{
    if(!raiz)
        return NULL;
    struct nodo_arbol*cop=crearnodo(raiz->dato);
    cop->izq=copiar_subarbol(raiz->izq);
    cop->der=copiar_subarbol(raiz->der);
    return cop;
}

struct queue leaf(struct nodo_arbol* raiz)
{
    struct queue leafs;
    init(&leafs);
    if(!raiz)
        return leafs;
    if(!raiz->der && !raiz->izq)
    {
        encolar(&leafs,raiz->dato);
        return leafs;
    }

    if(raiz->izq)
    {
        struct queue left=leaf(raiz->izq);
        while(!isempty(&left))
            encolar(&leafs,desencolar(&left));
    }

    if(raiz->der)
    {
       struct queue der=leaf(raiz->der);
        while(!isempty(&der))
            encolar(&leafs,desencolar(&der));
    }
    return leafs;
}

struct nodo_arbol* insert_nodo(struct nodo_arbol* root,void* dato)
{
    if(!root)
    {
        root=crearnodo(dato);
        return root;
    }
    struct queue q;
    init(&q);
    encolar(&q,root);
    while(!isempty(&q))
    {
        struct nodo_arbol* nodo=(struct nodo_arbol*)desencolar(&q);
        if(nodo->izq)
            encolar(&q,nodo->izq);
        else
        {
            nodo->izq=crearnodo(dato);
            return root;
        }
        if(nodo->der)
            encolar(&q,nodo->der);
        else
        {
            nodo->der=crearnodo(dato);
            return root;
        }
    }
}

void borrar_masprofundo(struct nodo_arbol* root,struct nodo_arbol* dir)
{
    struct queue q;
    init(&q);
    encolar(&q,root);
    struct nodo_arbol* tmp;
    while (!isempty(&q))
    {
        tmp=(struct nodo_arbol*)desencolar(&q);
        if(tmp==dir)
        {
            free(dir);
            return;
        }
        if(tmp->der)
        {
            if(tmp->der==dir)
            {
                tmp->der=NULL;
                free(dir);
                return;
            }
            encolar(&q,tmp->der);
        }
        if(tmp->izq)
        {
            if(tmp->izq==dir)
            {
                tmp->izq=NULL;
                free(dir);
                return;
            }
            encolar(&q,tmp->izq);
        }

    }
}



struct nodo_arbol* arboleliminado(struct nodo_arbol* root,void* dato)
{
    if(!root)
        return NULL;
    if(!root->izq && !root->der)
    {
        return NULL;
    }
     struct queue q;
    init(&q);
    encolar(&q,root);
    struct nodo_arbol* tmp;
    struct nodo_arbol* buscado=NULL;
    while (!isempty(&q))
    {
        tmp=(struct nodo_arbol*)desencolar(&q);
        if(tmp->dato==dato)
            buscado=tmp;
        if(tmp->izq)
            encolar(&q,tmp->izq);
        if(tmp->der)
            encolar(&q,tmp->der);
    }
    if(buscado)
    {
        buscado->dato=tmp->dato;
        borrar_masprofundo(root,tmp);
    }
    return root;
}

void exportar_dot(struct nodo_arbol* raiz, FILE* f) 
{
    if (!raiz) return;
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


void ExportaGraphizint(struct nodo_arbol* raiz)
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
    exportar_dot(raiz,f);
    fprintf(f, "}\n");
    fclose(f);
}