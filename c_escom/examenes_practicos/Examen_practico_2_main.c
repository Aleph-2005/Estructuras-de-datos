#include <stdio.h>
#include <stdlib.h>
#include "lista_DE.h"


void swap(struct nodo*p)
{
    int aux=p->dato;
    char *auxn=p->nombre;
    p->dato=(p->siguiente)->dato;
    p->nombre=(p->siguiente)->nombre;
    (p->siguiente)->dato=aux;
    (p->siguiente)->nombre=auxn;
}

void bubblesort(struct lista *p)
{
    struct nodo* tmp=p->frente;
    while(tmp->siguiente!=NULL)
    {   
    struct nodo*tmp_2=p->frente;
       while((tmp_2->siguiente)!=NULL)
       {
           if((tmp_2->dato)<((tmp_2->siguiente)->dato))
           {    
                swap(tmp_2);
           }
           tmp_2=tmp_2->siguiente;
       }
       tmp=tmp->siguiente;
    }
}

int main()
{
    struct lista p;
    init(&p);

    insertinicio(&p,8,"Daniel");
    insertinicio(&p,5,"Elena");
    insertinicio(&p,2,"Pablo");
    insertinicio(&p,9,"Juan");
    insertinicio(&p,7,"Pamela");
    insertinicio(&p,4,"Alejandra");
    insertinicio(&p,1,"Pedro");
    insertinicio(&p,3,"Luis");
    insertinicio(&p,6,"Ana");
    insertinicio(&p,10,"Manuel");
    imprimirlista1(&p);
    bubblesort(&p);
    imprimirlista1(&p);
    imprimirlista2(&p);
    return 0;
}
