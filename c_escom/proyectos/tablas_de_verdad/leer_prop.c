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

int binary_search(char **arr, int size, char *target) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // No encontrado
}

void ordenar_agregar(char **var, int* tam,char* nuevo)
{
    *(var+(*tam))=strdup(nuevo);
    (*tam)++;
    for(int i=(*tam)-1;i>0 && strcmp(*(var+i),*(var+(i-1)))<0;i--)
    {
        char*tmp=*(var+i);
        *(var+i)=*(var+(i-1));
        *(var+(i-1))=tmp;
    }
}

char** variables(char**l,int* tam)
{
    int capacidad=10;
    char** var=malloc(capacidad*sizeof(char*));
    (*tam)=0;
    int c=0;
    int i=0;
    while(*(l+c))
    {
        if(isalpha(**(l+c)))
        {
            if(binary_search(var,(*tam),*(l+c))==-1)
            {
                if((*tam)>=capacidad)
                {
                    capacidad*=2;
                    var=realloc(var,capacidad*sizeof(char*));
                }
                ordenar_agregar(var,tam,*(l+c));
            }
        }
        c++;
    }
    return var;
}

void valores(char**l,int*A,char** var,int tam)
{
    int c=0;
    while(*(l+c))
    {
        if(isalpha((int)**(l+c)))
        {
            int pos=binary_search(var,tam,*(l+c));
            if(pos!=-1)
            {
                free(*(l+c));
                *(l+c)=strdup(*(A+pos)==1 ?"1":"0");
            }
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