#include <stdio.h>
#include "lista_SE.h"
#include "grafo.h"
#include "pila_din.h"
#include <stdlib.h>


void exportarGraphviz(struct lista* Adj, int n) {
    FILE* f = fopen("grafo.dot", "w");
    if (!f) {
        perror("No se pudo abrir el archivo");
        return;
    }
    fprintf(f, "graph G {\n");
    fprintf(f, "    layout=neato;\n");
    fprintf(f, "    overlap=false;\n");
    fprintf(f, "    splines=true;\n");
    fprintf(f, "    nodesep=0.4;\n");
    fprintf(f, "    ranksep=0.6;\n");
    fprintf(f, "    node [\n");
    fprintf(f, "        shape=circle,\n");
    fprintf(f, "        style=filled,\n");
    fprintf(f, "        fillcolor=white,\n");
    fprintf(f, "        color=black,\n");
    fprintf(f, "        fontcolor=black,\n");
    fprintf(f, "        fontsize=10,\n");
    fprintf(f, "        width=0.3,\n");
    fprintf(f, "        height=0.3,\n");
    fprintf(f, "        fixedsize=true\n");
    fprintf(f, "    ];\n\n");
    for (int i = 0; i < n; i++) {
        struct nodo* actual = Adj[i].frente;//nos posicionamos sobre el frente de la lista
        while (actual != NULL) 
        {
            int vecino = *((int*)(actual->dato));
            if (i <= vecino) // evitar duplicados en grafo no dirigido (si quiero lazos)
            fprintf(f, "    %d -- %d;\n", i, vecino);
            actual = actual->siguiente;
        }
    }

    fprintf(f, "}\n");
    fclose(f);
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
        printf("Dame la cantidad de vecinos del nodo %d\n",i);
        int l;
        scanf("%d",&l);
        for(int j=0;j<l;j++)
        {
            printf("Dame un vecino del vertice %d\n",i);
            int r;
            scanf("%d",&r);
            int* vecino = malloc(sizeof(int));
            *vecino = r;
            insertinicio(&grafo[i], vecino);
        }
    }
    return grafo;
}

int** Grafomatrizadj()
{
    printf("Dame la cantidad de vertices del grafo\n");
    int n;
    scanf("%d",&n);
    int**Matrizdeady=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        Matrizdeady[i]=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            printf("Si el vertice %d es adyacente al %d presiona 1, si no 0",i,j);
            int flag;
            scanf("%d",&flag);
            Matrizdeady[i][j]=flag;
            Matrizdeady[j][i]=flag;
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
    int**Matrizdeinc=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        Matrizdeinc[i]=(int*)calloc(m,sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("Si la arista %d es adyacente al vertice %d presiona 1, si no 0",j,i);
            int flag;
            scanf("%d",&flag);
            Matrizdeinc[i][j]=flag;
        }
    }
    return Matrizdeinc;
}
