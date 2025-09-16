#include <stdio.h>
#include "lista_SE.h"
#include <stdlib.h>

void BFS()
{

}

void print_tp(void *l)
{
    printf("->%d",*(int*)l);
}


void imprimirgrafo(int n,struct lista* grafo)
{
    for(int i=0;i<n;i++)
    {
        printf("Vertice %d ",i+1);
        imprimirlista(&grafo[i],print_tp);
    }
}

struct lista* Escribirgrafo(int* tam)
{
    printf("Dame la cantidad de vertices del grafo\n");
    int n;
    scanf("%d",&n);
    *tam=n;
    struct lista* grafo=malloc(sizeof(struct lista)*n);
    for(int i=0;i<n;i++)
    {
        init(&grafo[i]);
        printf("Dame la cantidad de vecinos del nodo %d\n",i+1);
        int l;
        scanf("%d",&l);
        for(int j=0;j<l;j++)
        {
            printf("Dame un vecino del vertice %d\n",i+1);
            int r;
            scanf("%d",&r);
            int* vecino = malloc(sizeof(int));
            *vecino = r;
            insertinicio(&grafo[i], vecino);
        }
    }
    return grafo;
}

int** Grafomatrizdj()
{
    printf("Dame la cantidad de vertices del grafo\n");
    int n;
    scanf("%d",&n);
    int**Matrizdeady=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        Matrizdeady[i]=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Si el vertice %d es adyacente al %d presiona 1, si no 0",i,j);
            int flag;
            scanf("%d",&flag);
            Matrizdeady[i][j]=flag;
        }
    }
    return Matrizdeady;
}

int** Grafomatriindc()
{
    printf("Dame la cantidad de vertices del grafo\n");
    int n;
    scanf("%d",&n);
    printf("Dame la cantidad de aristas del grafo\n");
    int m;
    scanf("%d",&m);
    int**Matrizdeinc=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
        Matrizdeinc[i]=(int*)malloc(n*sizeof(int));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Si la arista %d es adyacente al vertice %d presiona 1, si no 0",i,j);
            int flag;
            scanf("%d",&flag);
            Matrizdeinc[i][j]=flag;
        }
    }
    return Matrizdeinc;
}



int main()
{
    int tam;
    struct lista* grafo=Escribirgrafo(&tam);
    imprimirgrafo(tam,grafo);
}