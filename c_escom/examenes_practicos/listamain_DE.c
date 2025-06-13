#include <stdio.h>
#include <stdlib.h>
#include "lista_DE.h"

int main()
{
    struct lista p;
    init(&p);
    for(int i=0;i<5;i++)
    {
        insertinicio(&p,i);
    }
   
    imprimirlista1(&p);
    eliminarPosicion(&p,2);
    imprimirlista1(&p);
    return 0;
}
