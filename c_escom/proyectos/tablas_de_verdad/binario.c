#include <stdio.h>
#include <math.h>
#include "leer_prop.h"
int* sumabinario(int* A,int tam)
{
   for(int i=tam-1;i>=0;i--)
   {
        if(A[i]==0)
        {
            A[i]=1;
            return A;
        }
        else
            A[i]=0;
   }
   return A;
}

void imprimir_arreglo(int* A,int tam )
{

    for(int i=0;i<tam;i++)
        printf(" %d  |",A[i]);
}

void linea_separadora(int r)
{
    for (int i = 0; i < r; i++)
        printf("----|");
    printf("----\n");
}

void combinaciones(int r, int* A, char** l,char**expr,char**var) 
{
    int taut=0;
    int lim = (int)pow(2, r);
    // Encabezado
    printf("\nTabla de verdad:\n");
    printf("\n");
    for (int i = 0; i < r; i++)
        printf(" %s  |",*(var+i));  
    imprimir(expr);
    linea_separadora(r);
    for (int i = 0; i < lim; i++) 
    {
        // Imprimir combinación
        imprimir_arreglo(A,r);
        // Evaluar expresión
        char** clon = clonar(l);
        valores(clon, A,var,r);
        int resultado = evaluar_postfija(clon);
        if(resultado==1)
            taut++;
        printf(" %d\n", resultado);
        liberar(clon);
        linea_separadora(r);
        // Preparar siguiente combinación
        if (i < lim - 1)
            sumabinario(A, r);
    }
    printf("\n");
    if(taut==lim)
        printf("Es una Tautologia\n");
    if(taut==0)
        printf("Es una contradiccion\n");
}