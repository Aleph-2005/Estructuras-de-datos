#include <stdio.h>
#include "pila_char_ptr.h"
#include <string.h>
#include "arbol.h"
#include "shunting_yard.h"
#include "leer_entrada.h"

int main()
{
    struct pila p;
    init(&p);
    char l[1000];
    char* new[1000];
    char* new2[1000];
    printf("Dame la funcion que quieres derivar\n");
    scanf("%s",l);
    if(leer(l,new) && parentesis(new))
    {
        shuntingyard(new,&p,new2);
        struct nodoarbol* raiz=construir_arbol_postfijo(new2);
        printf("Notacion postfija:\n");
        imprimir(new2);
        printf("\n");
        printf("Derivada:\n");
        raiz=simplificar(derivada(raiz));
        imprimir_infijo(raiz);
        printf("\n");
        printf("Notacion en latex\n");
        imprimir_infijolatex(raiz);
        liberararb(raiz);
        liberar(new);
        liberar(new2);
    }
    else
        printf("Entrada invalida");
}