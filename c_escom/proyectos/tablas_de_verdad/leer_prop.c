#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "leer_prop.h"

int leer_exp(const char* expr, int i, char* token) 
{
    if (*(expr+i) == '-' && *(expr+i+1) == '>') 
    {
        strcpy(token, "->");
        return 2;
    }
    if (*(expr+i) == '<' && *(expr+i+1) == '-' && *(expr+i+2) == '>') 
    {
        strcpy(token, "<->");
        return 3;
    }
    if (*(expr+i) == '&' || *(expr+i) == '|' || *(expr+i) == '!' || *(expr+i) == '(' || *(expr+i) == ')') 
    {
        *token = *(expr+i);
        *(token+1) = '\0';
        return 1;
    }
    if (isalpha(*(expr+i))) 
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
        printf("%s",token[i]);
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

void liberar(char* n[])
{
    int i=0;
    while(*(n+i))
    {
        free(*(n+i));
        i++;
    }
}