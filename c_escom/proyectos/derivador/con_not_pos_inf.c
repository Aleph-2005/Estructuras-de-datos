#include <stdio.h>
#include "pila_char_ptr.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "arbol.h"
#include "shunting_yard.h"

int leer_exp(char* expr, int i, char* token) 
{
    if (strncmp(expr+i,"sen(",4)==0)
    {
        strcpy(token, "sen");
        return 3;
    }
    if (strncmp(expr+i,"cos(",4)==0)
    {
        strcpy(token, "cos");
        return 3;
    }
    if(strncmp(expr+i,"ln(",3)==0)
    {
        strcpy(token,"ln");
        return 2;
    }
    if (strchr("+-/*^()x",*(expr+i))) 
    {
        *token = *(expr+i);
        *(token+1) ='\0';
        return 1;
    }
    if (isalpha(*(expr+i))||isdigit(*(expr+i)) )
    {
        *token = *(expr+i);
        *(token+1) = '\0';
        return 1;
    }
    return 0;
}

void imprimir(char*token[1000])
{
    int i=0;
    while(token[i])
    {
        printf("%s ",token[i]);
        i++;
    }
}

int leer(char* l,char** token)
{
    int c=0;
    int i=0;
    while(*(l+c))
    {
        token[i] = (char*)malloc(10* sizeof(char));
       int acarreo=leer_exp(l,c,token[i]);
       if(acarreo==0)
            return 0;
       c+=acarreo;
       i++;
    }
     token[i]=NULL;
     return 1;
}

void liberar(char* new[])
{
    int i=0;
    while(*(new+i))
    {
        free(*(new+i));
        i++;
    }
}

int main()
{
    struct pila p;
    init(&p);
    char l[1000];
    char* new[1000];
    char* new2[1000];
    printf("Dame la funcion que quieres derivar\n");
    scanf("%s",l);
    if(leer(l,new)!=0)
    {
        shuntingyard(new,&p,new2);
        struct nodoarbol* raiz=construir_arbol_postfijo(new2);
        printf("Notacion postfija:\n");
        imprimir(new2);
        printf("\n");
        printf("Derivada:\n");
        imprimir_infijo(derivada(raiz));
        liberararb(raiz);
        liberar(new);
        liberar(new2);
    }
    else
        printf("Entrada invalida");
}