#include <stdio.h>
#include "pila_char_ptr.h"
#include <string.h>
#include "shunting_yard_prop.h"
#include "leer_prop.h"

int main()
{
    struct pila p;
    init(&p);
    char l[1000];
    char* new[1000];
    char* new2[1000];
    printf("dame tu proposicion\n");
    scanf("%s",l);
    if(leer(l,new)!=0)
    {
        shuntingyard(new,&p,new2);
        printf("Notacion postfija\n");
        imprimir(new2);
        liberar(new);
        liberar(new2);
    }
    else
        printf("Entrada invalida");
}