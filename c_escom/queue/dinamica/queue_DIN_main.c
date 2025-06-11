#include <stdio.h>
#include "queue_DIN.h"

int main()
{
    struct queue p;
    init(&p);

    for(int i=0;i<5;i++)
        encolar(&p,i);
    
    imprimircola(&p);
    desencolar(&p);
    imprimircola(&p);
}