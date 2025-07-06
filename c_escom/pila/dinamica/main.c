#include <stdio.h>
#include <stdlib.h>
# include "pila_din.h"
void print_tp(void *l)
{
    printf("%d\n",*(int*)l);
}

int main()
 {
    struct pila p;
    init(&p);
    int i;
    for(i=0;i<5;i++)
    {
        int *dato = (int *)malloc(sizeof(int));
        *dato = i;
        push(dato, &p);
    }
    printstack(&p,print_tp);
    printf("%d\n",*(int*)pop(&p));
 }