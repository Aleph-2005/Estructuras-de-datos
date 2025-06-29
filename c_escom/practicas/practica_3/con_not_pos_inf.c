#include <stdio.h>
#include "pila_char.h"
#include <ctype.h>

int prioridad(char l)
{
    if((l=='+')||(l=='-'))
        return 1;
    if((l=='*')||(l=='/'))
        return 2;
    if(l==')')
        return 0;
    if(l=='(')
        return -1;
    return -2;
}

void vaciar1(struct pila *p,char *new,int* r)
{
    while((!isEmpty(p))&&(p->tope)->valor!='(')
    {
        *(new+*r)=pop(p);
        *r=*r+1;
    }
    pop(p);
}

void vaciar2(struct pila *p,char *new,int* r,int dom)
{
    while((!isEmpty(p))&&prioridad((p->tope)->valor)>=dom)
    {
        *(new+*r)=pop(p);
        *r=*r+1;
    }
}

void polaca(char* cad,struct pila* p,char* new)
{
    int i=0;
    int r=0;
    while(*(cad+i))
    {
        if(isdigit(*(cad+i)))
        {
            *(new+r)=*(cad+i);
            r++;
        }
        else
        {   
           
            if(prioridad(*(cad+i))==0)
                vaciar1(p,new,&r);
            else if(prioridad(*(cad+i))==-1)
                push(*(cad+i),p);
            else 
            {
                vaciar2(p,new,&r,prioridad(*(cad+i)));
                push(*(cad+i), p);
            }

        }            
        i++;
    }
    vaciar(p,new,&r);
    *(new+r)='\0';
}

int main()
{
    struct pila p;
    init(&p);
    char l[1000];
    char new[1000];
    scanf("%s",l);
    printf("Antes: %s\n",l);
    polaca(l,&p,new);
    printf("Despues: %s\n",new);
}