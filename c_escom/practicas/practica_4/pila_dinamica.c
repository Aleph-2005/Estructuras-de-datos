#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

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

int pop()
{
    if(isempty())
    {
        //printf("ERROR");
        return 0;
    }
    else
    {
    struct nodo*temp=tope;
    if((temp->ele!='(')&(temp->ele!=')'))
    {
        printf("%c ",temp->ele);
    }
    tope=temp->siguiente;
    //char z=temp->ele;
    free(temp);
    return 1;
    }
}
 

int parentesis(char C[100])
{
    while(*(C++))/*mientras el valor de la
    isesima posicion sea diferenete de NULL*/
    
    {
        if (*C=='(')
        /*si lo apuntado es un parentesis
        de abertura apilamos*/
        {
            push(*C);
        }
        if(*C==')')
         /*si lo apuntado es un parentesis
        de cierre desapilamos
        */
        {
            if(!pop())
             /*si dessapilamos una pila
             vacia retornamos 0*/
            {
                return 0;
            }
        }
    }
    if (isempty())
    {
        return 1;
        /*si la pila esta vacia
        retornamos 1*/
    }

    return 0;
    //si no retornamos 0
}
int main()
{
    char A[100];
    fgets(A,100,stdin);
    if( parentesis(A))
     /*si la valuacion de paretesis
     fue positiva o negativa imprimimos 
     el respectivo mensaje*/
    {
        printf("Expresion correcta");
    }
    else
    {
        printf("Expresion incorrecta");
    }
}









