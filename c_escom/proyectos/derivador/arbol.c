#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arbol.h"
#include "pila_char_ptr.h"

 struct nodoarbol* crearnodoarbolbinario(char*valor,struct nodoarbol* izq,struct nodoarbol* der)
 {
    struct nodoarbol* nuevo=(struct nodoarbol*)malloc(sizeof(struct nodoarbol));
    nuevo->valor=strdup(valor);
    nuevo->izq=izq;
    nuevo->der=der;
    return nuevo;
 }

struct nodoarbol* crearnodoarbol(char*valor)
 {
    struct nodoarbol* nuevo=(struct nodoarbol*)malloc(sizeof(struct nodoarbol));
    nuevo->valor=strdup(valor);
    nuevo->izq=NULL;
    nuevo->der=NULL;
    return nuevo;
 }

 void liberararb(struct nodoarbol* raiz) 
 {
    if (!raiz) return;
    liberararb(raiz->izq);
    liberararb(raiz->der);
    free(raiz);
}

struct nodoarbol* construir_arbol_postfijo(char* tokens[]) 
{
    struct pila pila;
    init(&pila);
    int i = 0;
    while (tokens[i]) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0 ||
        strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0 ||
        strcmp(tokens[i], "^") == 0)
        {
            struct nodoarbol* der = (struct nodoarbol*)pop(&pila);
            struct nodoarbol* izq = (struct nodoarbol*)pop(&pila);
            struct nodoarbol* op = crearnodoarbolbinario(tokens[i],izq,der);
            
            push(op, &pila);
        } 
        else if (strcmp(tokens[i], "sen") == 0 || strcmp(tokens[i], "cos") == 0 || strcmp(tokens[i], "ln") == 0) 
        {
            struct nodoarbol* arg = (struct nodoarbol*)pop(&pila);
            struct nodoarbol* func = crearnodoarbolbinario(tokens[i],arg,NULL);
            push(func, &pila);
        } 
        else 
        {
            push(crearnodoarbolbinario(tokens[i],NULL,NULL), &pila);
        }
        i++;
    }

    return (struct nodoarbol*)pop(&pila);
}

void imprimir_infijo(struct nodoarbol* raiz) {
    if (!raiz) return;

    // Si es una función unaria
    if (strcmp(raiz->valor, "sen") == 0 || strcmp(raiz->valor, "cos") == 0 || strcmp(raiz->valor, "ln") == 0) {
        printf("%s(", raiz->valor);
        imprimir_infijo(raiz->izq);
        printf(")");
        return;
    }

    // Si es un operador binario
    if (raiz->izq && raiz->der) {
        printf("(");
        imprimir_infijo(raiz->izq);
        printf("%s", raiz->valor);
        imprimir_infijo(raiz->der);
        printf(")");
        return;
    }

    // Si es una hoja (número o variable)
    printf("%s", raiz->valor);
}

struct nodoarbol* copiar_subarbol(struct nodoarbol* raiz)
{
    if(!raiz)
        return NULL;
    struct nodoarbol*cop=crearnodoarbol(raiz->valor);
    cop->izq=copiar_subarbol(raiz->izq);
    cop->der=copiar_subarbol(raiz->der);
    return cop;
}
int esfuncion(char* l)
{
    if(strcmp(l,"x")==0|| strcmp(l,"cos")==0 || strcmp(l,"sen")==0 || strcmp(l,"ln")==0)
        return 1;
    return 0;
}

struct nodoarbol* derivada(struct nodoarbol* raiz)
{
    if(!raiz)
        return NULL;
    if(isdigit(*(raiz->valor)) || (isalpha(*(raiz->valor)) && !esfuncion(raiz->valor)))
        return crearnodoarbolbinario("0",NULL,NULL);
    if(strcmp(raiz->valor,"x")==0)
        return crearnodoarbolbinario("1",NULL,NULL);
    if(strcmp(raiz->valor,"+")==0 || strcmp(raiz->valor,"-")==0)
    {
        return crearnodoarbolbinario(raiz->valor,derivada(raiz->izq),derivada(raiz->der));
    }
    if(strcmp(raiz->valor,"sen")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("cos",copiar_subarbol(raiz->izq),NULL);
        struct nodoarbol* g=derivada(raiz->izq);
        return crearnodoarbolbinario("*",f,g);
    }
    if(strcmp(raiz->valor,"cos")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("sen",copiar_subarbol(raiz->izq),NULL);
        struct nodoarbol* f_=crearnodoarbolbinario("*",crearnodoarbol("-1"),f);
        struct nodoarbol* g=derivada(raiz->izq);
        return crearnodoarbolbinario("*",f_,g);
    }
    if(strcmp(raiz->valor,"ln")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("/",crearnodoarbol("1"),copiar_subarbol(raiz->izq));
        struct nodoarbol* g=derivada(raiz->izq);
        return crearnodoarbolbinario("*",f,g);
    }
    if(strcmp(raiz->valor,"*")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("*",derivada(raiz->izq),copiar_subarbol(raiz->der));
        struct nodoarbol* g=crearnodoarbolbinario("*",copiar_subarbol(raiz->izq),derivada(raiz->der));
        return crearnodoarbolbinario("+",f,g);
    }
    if(strcmp(raiz->valor,"/")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("*",derivada(raiz->izq),raiz->der);
        struct nodoarbol* g=crearnodoarbolbinario("*",raiz->izq,derivada(raiz->der));
        struct nodoarbol* l=crearnodoarbolbinario("-",f,g);
        return crearnodoarbolbinario("/",l,crearnodoarbolbinario("^",raiz->der,crearnodoarbol("2")));
    }
    if (strcmp(raiz->valor, "^") == 0) {
    if (strcmp(raiz->izq->valor, "x") == 0 && isdigit(*(raiz->der->valor)) )
    {
        int n = atoi(raiz->der->valor);
        char nuevo_exponente[10];
        sprintf(nuevo_exponente, "%d", n - 1);
        struct nodoarbol* coef = crearnodoarbolbinario(raiz->der->valor, NULL, NULL);
        struct nodoarbol* potencia = crearnodoarbolbinario("^", copiar_subarbol(raiz->izq), crearnodoarbol(nuevo_exponente));
        return crearnodoarbolbinario("*", coef, potencia);
    }
}
}