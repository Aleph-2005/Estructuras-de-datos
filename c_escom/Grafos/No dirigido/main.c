#include <stdio.h>
#include "lista_SE.h"
#include "grafo.h"
#include "pila_din.h"
#include <stdlib.h>

void print_tp(void *l)
{
    printf("->%d",*(int*)l);
}


void imprimirgrafo(int n,struct lista* grafo)
{
    for(int i=0;i<n;i++)
    {
        printf("Vertice %d ",i+1);
        imprimirlista(&grafo[i],print_tp);
    }
}

int main()
{
    int tam;
    struct lista* grafo=Escribirgrafo(&tam);
    imprimirgrafo(tam,grafo);
    exportarGraphviz(grafo,tam);
}