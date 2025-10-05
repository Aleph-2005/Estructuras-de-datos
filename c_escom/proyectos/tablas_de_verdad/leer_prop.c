#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pila_char_ptr.h"
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
    printf("\n");
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

int cantidad_de_variables(char** l)
{
    int cont=0;
    int c=0;
    while(*(l+c))
    {
        if(isalpha((int)**(l+c)))
            cont++;
        c++;
    }
    return cont;
}

char** variables(char**l)
{
    char** var=malloc(cantidad_de_variables(l)*sizeof(char*));
    int c=0;
    int i=0;
    while(*(l+c))
    {
        if(isalpha((int)**(l+c)))
        {
            *(var+i)=strdup(*(l+c));
            i++;
        }
        c++;
    }
    return var;
}

void valores(char**l,int*A)
{
    int c=0;
    int i=0;
    while(*(l+c))
    {
        if(isalpha((int)**(l+c)))
        {
            if(A[i]==0)
                *(l+c)=strdup("0");
            else
                *(l+c)=strdup("1");
            i++;
        }
        
        c++;
    }
}


char** clonar(char** expr) 
{
    int i = 0;
    while (expr[i]) i++;
    char** copia = malloc((i + 1) * sizeof(char*));
    for (int j = 0; j < i; j++)
        copia[j] = strdup(expr[j]);
    copia[i] = NULL;
    return copia;
}



int evaluar_postfija(char** expr) {
    struct pila p;
    init(&p);
    int i = 0;

    while (expr[i]) {
        if (strcmp(expr[i], "0") == 0 || strcmp(expr[i], "1") == 0) 
        {
            int* val = malloc(sizeof(int));
            *val = (strcmp(expr[i], "1") == 0) ? 1 : 0;
            push(val,&p);
        }
        else if (strcmp(expr[i], "!") == 0) {
            int* a = (int*)pop(&p);
            int* res = malloc(sizeof(int));
            *res = !(*a);
            push(res,&p);
            free(a);
        }
        else {
            int* b = (int*)pop(&p);
            int* a = (int*)pop(&p);
            int* res = malloc(sizeof(int));

            if (strcmp(expr[i], "&") == 0)
                *res = (*a && *b);
            else if (strcmp(expr[i], "|") == 0)
                *res = (*a || *b);
            else if (strcmp(expr[i], "->") == 0)
                *res = (!(*a) || *b);
            else if (strcmp(expr[i], "<->") == 0 || strcmp(expr[i], "↔") == 0)
                *res = (*a == *b);
            else
                *res = 0; // operador desconocido

            push(res,&p);
            free(a);
            free(b);
        }
        i++;
    }

    int* resultado = (int*)pop(&p);
    int final = *resultado;
    free(resultado);
    return final;
}