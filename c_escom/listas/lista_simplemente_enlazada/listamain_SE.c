#include <stdio.h>
#include <stdlib.h>
#include "lista_SE.h"
void print_tp(void *l)
{
    printf("%d  ",*(int*)l);
}

int main()
{
    struct lista p;
    init(&p);
    for(int i=0;i<10;i++)
    {
        int *dato = (int *)malloc(sizeof(int));
        *dato = i;
        insertinicio(&p,dato);
    }
    int* a;
    *a=8;
    insertn(&p,a,3);
    printf("ahora\n");
    imprimirlista(&p,print_tp);
    printf("ahora_2\n");
    print_tp(eliminarPosicion(&p,3));
    printf("\n");
    imprimirlista(&p,print_tp);
    return 0;
}
