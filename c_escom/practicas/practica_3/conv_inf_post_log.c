#include <stdio.h>
#include "pila_char.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int leer_exp(const char* expr, int i, char* token) {
    if (*(expr+i) == '-' && *(expr+i+1) == '>') {
        strcpy(token, "->");
        return 2;
    }
    if (*(expr+i) == '<' && *(expr+i+1) == '-' && *(expr+i+2) == '>') {
        strcpy(token, "<->");
        return 3;
    }
    if (*(expr+i) == '&' || *(expr+i) == '|' || *(expr+i) == '!' || *(expr+i) == '(' || *(expr+i) == ')') {
        *token = *(expr+i);
        *(token+1) = '\0';
        return 1;
    }
    if (isalpha(*(expr+i))) {
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

void leer(char* l,char** token)
{
    int c=0;
    int i=0;
    while(*(l+c))
    {
        token[i] = (char*)malloc(10* sizeof(char));
       int acarreo=leer_exp(l,c,token[i]);
       if(acarreo==0)
       {
            printf("Entrada invalida");
            break;
       }
       c+=acarreo;
       i++;
    }
     token[i]=NULL;
}

int prioridad_str(const char* op) 
{
    if (strcmp(op, "!") == 0) return 5;
    if (strcmp(op, "&") == 0) return 4;
    if (strcmp(op, "|") == 0) return 3;
    if (strcmp(op, "->") == 0) return 2;
    if (strcmp(op, "<->") == 0) return 1;
    if(strcmp(op,"(")==0) return 0;
    if(strcmp(op,")")) return -1;
    return -2;
}


int main()
{
    struct pila p;
    init(&p);
    char l[1000];
    char* new[1000];
    scanf("%s",l);
    leer(l,new);
    imprimir(new);
}