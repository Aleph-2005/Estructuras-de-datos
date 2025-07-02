#include <stdio.h>
#include "pila_char_ptr.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "arbol.h"

int leer_exp(char* expr, int i, char* token) {
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
        *(token+1) = '\0';
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

void vaciar(struct pila* p, char** new, int* r) 
{
    while (!isEmpty(p)) 
    {
        new[(*r)++] = pop(p);
    }
}

void vaciar1(struct pila *p,char **new,int* r)
{
    while((!isEmpty(p))&&(strcmp((p->tope)->valor,"(")!=0))
    {
        new[(*r)++]=(char*)pop(p);
    }
    pop(p);
    if(!isEmpty(p) && prioridad(p->tope->valor)==-2)
        new[(*r)++]=(char*)pop(p);
}

void vaciar2(struct pila *p,char **new,int* r,int dom)
{
    while((!isEmpty(p))&&prioridad((p->tope)->valor)>=dom)
    {
        new[(*r)++]=(char*)pop(p);
    }
}

void shuntingyard(char** cad,struct pila* p,char** new)
{
    int i=0;
    int r=0;
    while(*(cad+i))
    {
        if((isalpha(**(cad+i))|| isdigit(**(cad+i)) )&& prioridad(*(cad+i))!=-2)
        {
            *(new+r)=*(cad+i);
            r++;
        }
        else
        {   
            if(prioridad(*(cad+i))==0)
                vaciar1(p,new,&r);
            else if(prioridad(*(cad+i))==-1||prioridad(*(cad+i))==-2)
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
    new[r]=NULL;
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
        printf("Notacion postfija\n");
        imprimir(new2);
        printf("\n");
        printf("Notacion infija reconstruida por el arbol\n");
        imprimir_infijo(raiz);
        liberararb(raiz);
        liberar(new);
    }
    else
        printf("Entrada invalida");
}