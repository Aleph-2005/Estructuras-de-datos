#include <stdio.h>
#include <stdlib.h>
#include "queue_EST.h"
void print_tp(void *l)
{
    printf("%d\n",*(int*)l);
}

int main()
{
    struct queue p;
    init(&p);
    for(int i=0;i<5;i++)
    {
        int *dato = (int *)malloc(sizeof(int));
        *dato = i;
        encolar( &p,dato);
    }
    imprimircola(&p,print_tp);
    printf("eliminamos %d\n",*(int*)desencolar(&p));
    imprimircola(&p,print_tp);
}