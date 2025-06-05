#include <stdio.h>
# include "pila_din.h"

 int main()
 {
    struct pila p;
    init(&p);
    for(int i=0;i<5;i++)
        push(i,&p);
    imprimirpila(&p);
 }