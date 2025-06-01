#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

void imprimirarreglo(char c[13])
{
    for (int l = 0; l < 13; l++)
        {
            printf("%c ",*(c+l));
        }
    printf("\n");
}

struct pila
{
    char ele[MAX];
    int tope;
};

void incializar(struct pila *p)
{
    p->tope=-1;
}

int isempty(struct pila *p)
{
    if(p->tope==-1)
    {
        return 1;
    }
    return 0;
}

bool isfull(struct pila *p)
{
    if(p->tope==MAX-1)
    {
        return true;
    }
    return false;
    
}

void push(struct pila *p, char val)
{
    if(isfull(p))
    {
        printf("La pila esta llena");
    }
    else
    {
        p->ele[++(p->tope)]=val;
    }
}

int pop(struct pila *p)
{
    if(isempty(p))
    {
        return 0;
    }
    else
    {
        if((p->ele[p->tope]!='(')&(p->ele[p->tope]!=')'))
        {
            printf("%c ",p->ele[p->tope]);
        }
        //char z=p->ele[p->tope];
        (p->tope)--;
        return 1;

    }
}

int parentesis(char C[100],struct pila *p)
{
    while(*(C++))
    {
        if (*C=='(')
        {
            push(p,*C);
        }
        if(*C==')')
        {
            if(!pop(p))
            {
                return 0;
            }
        }
    }
    if (isempty(p))
    {
        return 1;
    }

    return 0;
}

int main()
{
    struct pila p;
    incializar(&p);
    char A[100];
    fgets(A,100,stdin);
    if( parentesis(A,&p))
    {
        printf("Expresion correcta");
    }
    else
    {
        printf("Expresion incorrecta");
    }
}