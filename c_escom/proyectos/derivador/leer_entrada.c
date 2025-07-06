#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "leer_entrada.h"
#include "pila_char_ptr.h"

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
    if (isdigit(*(expr+i)) || *(expr+i) == '.') {
        int j = 0;
        while (isdigit(expr[i + j]) || expr[i + j] == '.') 
        {
            *(token+j) = *(expr+i + j);
            j++;
        }
        *(token+j) = '\0';
        return j;
    }
    if (isalpha(*(expr+i))) 
    {
        int j = 0;
        while (isalpha(*(expr+i + j))) 
        {
            *(token+j) = *(expr+i + j);
            j++;
        }
        *(token+j) = '\0';
        return j;
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

void liberar(char* n[])
{
    int i=0;
    while(*(n+i))
    {
        free(*(n+i));
        i++;
    }
}

int parentesis(char **C)
{
    struct pila p;
    init(&p);
    while(*C)/*mientras el valor de la
    isesima posicion sea diferenete de NULL*/
    {
        if (strcmp(*C,"(")==0)
        /*si lo apuntado es un parentesis
        de abertura apilamos*/
        {
            push(*C,&p);
        }
        if(strcmp(*C,")")==0)
         /*si lo apuntado es un parentesis
        de cierre desapilamos
        */
        {
            if(!pop(&p))
             /*si dessapilamos una pila
             vacia retornamos 0*/
            {
                return 0;
            }
        }
        C++;
    }
    if (isEmpty(&p))
    {
        return 1;
        /*si la pila esta vacia
        retornamos 1*/
    }

    return 0;
    //si no retornamos 0
}