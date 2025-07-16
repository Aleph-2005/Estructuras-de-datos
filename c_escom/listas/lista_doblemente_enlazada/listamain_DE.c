#include <stdio.h>
#include <stdlib.h>
#include "lista_DE.h"
void print_tp(void *l)
{
    printf("%d  ",*(int*)l);
}

int main()
{
    struct lista p;
    init(&p);
    for(int i=0;i<5;i++)
    {
        int *dato = (int *)malloc(sizeof(int));
        *dato = i;
        insertinicio( &p,dato);
    }
   
    imprimirlista1(&p,print_tp);
    eliminarPosicion(&p,2);
    imprimirlista1(&p,print_tp);
    return 0;
}
