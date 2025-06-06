#include <stdio.h>
#include <stdlib.h>
#include "lista_SE.h"

int main()
{
    struct lista p;
    init(&p);
    for(int i=0;i<10;i++)
    {
        insertinicio(&p,i);
        printf(" lista: %d\n",i);
        imprimirlista(&p);
    }
    insertn(&p,34,8);
    printf("ahora\n");
    imprimirlista(&p);
    printf("ahora_2\n");
    printf("%d\n",eliminarPosicion(&p,3));
    imprimirlista(&p);
    return 0;
}
