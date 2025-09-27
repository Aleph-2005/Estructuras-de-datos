#include <stdio.h>
#include <stdlib.h>
#include "pila_din.h"

void pila_inicializar(struct Pila* pila) 
{
    pila->tope = NULL;
}

int pila_esta_vacia(struct Pila* pila) 
{
    return (pila->tope == NULL);
}

void pila_apilar(void* elemento, struct Pila* pila) 
{
    struct NodoPila* nuevo = (struct NodoPila*)malloc(sizeof(struct NodoPila));
    nuevo->valor = elemento;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
}

void* pila_desapilar(struct Pila* pila) 
{
    if (pila_esta_vacia(pila))
        return NULL;

    struct NodoPila* temporal = pila->tope;
    void* valor = temporal->valor;
    pila->tope = temporal->siguiente;
    free(temporal);
    return valor;
}

void pila_mostrar(struct Pila* pila, void (*mostrar_dato)(void*)) 
{
    if (pila_esta_vacia(pila)) 
    {
        printf("Pila vacía\n");
        return;
    }

    struct NodoPila* actual = pila->tope;
    while (actual != NULL) 
    {
        mostrar_dato(actual->valor);
        actual = actual->siguiente;
    }
}

void pila_destruir(struct Pila* pila) 
{
    while (!pila_esta_vacia(pila))
        pila_desapilar(pila);
}