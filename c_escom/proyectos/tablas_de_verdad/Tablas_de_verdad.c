#include <stdio.h>
#include <stdlib.h>
#include "pila_char_ptr.h"
#include <string.h>
#include "shunting_yard_prop.h"
#include "leer_prop.h"
#include "binario.h"

int main()
{
    struct pila p;
    init(&p);
    char l[1000];
    char* new[1000];
    char* new2[1000];
    printf("Dame tu proposicion\n");
    scanf("%s",l);
    if(leer(l,new)!=0)
    {
        shuntingyard(new,&p,new2);
        printf("Notacion postfija\n");
        imprimir(new2);
        int tam=0;
        char**var=variables(new2,&tam);
        int* A=(int*)calloc(tam,sizeof(int));
        combinaciones(tam,A,new2,new,var);
        //liberar(new);
        //liberar(new2;
    }
    else
        printf("Entrada invalida");
  
}