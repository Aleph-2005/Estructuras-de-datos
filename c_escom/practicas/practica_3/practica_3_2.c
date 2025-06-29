#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct nodo 
{
    char ele;
    struct nodo *siguiente;
};

struct nodo *tope=NULL;

int isempty()
{
    if(tope==NULL)
    {
        return 1;
    }
    return 0; 
}

void imprimirarreglo(char c[13])
{
    for (int l = 0; l < 13; l++)
        {
            printf("%c ",*(c+l));
        }
    printf("\n");
}

void push(char val)
{
    struct nodo* nuevo=(struct nodo*)malloc(sizeof(struct nodo));
    nuevo->ele=val;
    nuevo->siguiente=tope;
    tope=nuevo;
}

char pop()
{
    if(isempty())
    {
        printf("ERROR");
        return '0';
    }
    else
    {
    struct nodo*temp=tope;
    if((temp->ele!='(')&(temp->ele!=')'))
    {
        printf("%c ",temp->ele);
    }
    tope=temp->siguiente;
    char z=temp->ele;
    free(temp);
    return z;
    }
}
 
void vaciar()
{
    while(!isempty())
    {
        char z=pop();
        if(z=='(')
        {
            break;
        }
    }
}

void polaca(char cad[13])
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
                vaciar();
            }
            push(*(cad+i));
            if((*(cad+i)!='(')&(*(cad+i)!=')'))
            {
                temp=*(cad+i);
            }
        }
    }
    vaciar();
}

int main()
{
    char cad[13]={'5','+','3','*','7','+','(','2','+','1',')','*','9'};
    imprimirarreglo(cad);
    polaca(cad);
}









