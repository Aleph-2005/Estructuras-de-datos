#include <stdio.h>
#include "pila_char_ptr.h"
#include <string.h>
#include <ctype.h>
#include "shunting_yard.h"

int prioridad(const char* op) 
{
    if (strcmp(op, "^") == 0) return 3;
    if (strcmp(op, "/") == 0 || strcmp(op,"*")==0) return 2;
    if (strcmp(op, "+") == 0 || strcmp(op,"-")==0) return 1;
    if(strcmp(op,")")==0) return 0;
    if(strcmp(op,"(")==0) return -1;
    if(strcmp(op,"sen")==0 || strcmp(op,"cos")==0 || strcmp(op,"ln")==0 ) return -2;
    return -3;
}

void vaciar(struct pila* p, char** n, int* r) 
{
    while (!isEmpty(p)) 
    {
        n[(*r)++] = pop(p);
    }
}

void vaciar1(struct pila *p,char **n,int* r)
{
    while((!isEmpty(p))&&(strcmp((p->tope)->valor,"(")!=0))
    {
        n[(*r)++]=(char*)pop(p);
    }
    pop(p);
    if(!isEmpty(p) && prioridad(p->tope->valor)==-2)
        n[(*r)++]=(char*)pop(p);
}

void vaciar2(struct pila *p,char **n,int* r,int dom)
{
    while((!isEmpty(p))&&prioridad((p->tope)->valor)>=dom)
    {
        n[(*r)++]=(char*)pop(p);
    }
}

void shuntingyard(char** cad,struct pila* p,char** n)
{
    int i=0;
    int r=0;
    while(*(cad+i))
    {
        if((isalpha(**(cad+i))|| isdigit(**(cad+i)) )&& prioridad(*(cad+i))!=-2)
        {
            *(n+r)=*(cad+i);
            r++;
        }
        else
        {   
            if(prioridad(*(cad+i))==0)
                vaciar1(p,n,&r);
            else if(prioridad(*(cad+i))==-1||prioridad(*(cad+i))==-2)
                push(*(cad+i),p);
            else 
            {
                vaciar2(p,n,&r,prioridad(*(cad+i)));
                push(*(cad+i), p);
            }

        }            
        i++;
    }
    vaciar(p,n,&r);
    n[r]=NULL;
}
