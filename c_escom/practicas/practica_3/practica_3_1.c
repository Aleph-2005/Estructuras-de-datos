#include <stdio.h>
#include <stdbool.h>
#define MAX 20

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

char pop(struct pila *p)
{
    if(isempty(p))
    {
        printf("La pila esta vacia");
        return '0';
    }
    else
    {
        if((p->ele[p->tope]!='(')&(p->ele[p->tope]!=')'))
        {
            printf("%c ",p->ele[p->tope]);
        }
        char z=p->ele[p->tope];
        (p->tope)--;
        return z;

    }
}

void vaciar(struct pila *p)
{
    while(!isempty(p))
    {
        char z=pop(p);
        if(z=='(')
        {
            break;
        }
    }
}

void polaca(char cad[13],struct pila *p)
{
    char temp='+';
    for(int i=0;i<13;i++)
    {
        if((*(cad+i)<=57)&(*(cad+i)>=47))
        {
            printf("%c ",*(cad+i));
        }
        else
        {
            if((temp<*(cad+i))||(*(cad+i)==')'))
            {
                vaciar(p);
            }
            push(p,*(cad+i));
            if((*(cad+i)!='(')&(*(cad+i)!=')'))
            {
            temp=*(cad+i);
            }
        }
    }
    vaciar(p);
}

int main()
{
    struct pila p;
    incializar(&p);
    char cad[13]={'5','+','3','*','7','+','(','2','+','1',')','*','9'};
    imprimirarreglo(cad);
    polaca(cad,&p);

}