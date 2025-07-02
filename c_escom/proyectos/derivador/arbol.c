#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "pila_char_ptr.h"

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
            struct nodoarbol* op = crearnodoarbol(tokens[i]);
            op->izq = izq;
            op->der= der;
            push(op, &pila);
        } 
        else if (strcmp(tokens[i], "sen") == 0 || strcmp(tokens[i], "cos") == 0 || strcmp(tokens[i], "ln") == 0) 
        {
            struct nodoarbol* arg = (struct nodoarbol*)pop(&pila);
            struct nodoarbol* func = crearnodoarbol(tokens[i]);
            func->izq = arg;
            push(func, &pila);
        } 
        else 
        {
            push(crearnodoarbol(tokens[i]), &pila);
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
        //printf(" ");
        imprimir_infijo(raiz->izq);
        printf("%s", raiz->valor);
        imprimir_infijo(raiz->der);
        //printf(" ");
        return;
    }

    // Si es una hoja (número o variable)
    printf("%s", raiz->valor);
}