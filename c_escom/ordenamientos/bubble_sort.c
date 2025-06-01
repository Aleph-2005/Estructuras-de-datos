//Bubble sort
#include <stdio.h>

void swap(char*a,char*b)/*Funcion que intercambia
los valores de dos variables char a nivel de memoria*/
{
    char aux=*a;
    *a=*b;
    *b=aux;
}

void imprimirarreglo(char A[5])/*imprime un arreglo de 
caracteres a traves de un bucle for*/
{
    for (int l = 0; l < 5; l++)
        {
            printf("%c ",*(A+l));
        }
    printf("\n");
}

void bubblesort(char A[5])/*Ordenamiento burbuja*/
{
    for(int i=0;i<5;i++)/*Iteramos sobre todas las posiciones
    del arreglo*/
    {
       for(int l=0;l<4;l++)/*Iteramos las 
       posciones del arreglo excepto la n-1*/
       {
           if(*(A+l)<*(A+l+1))/*si los elementos
           no se encuentran ordenaos*/
           {
               swap((A+l),(A+l+1));/*Los intercambiamos*/
           }
       }
    }
}


int main()
{
    char A[5]={'D','L','A','Z','W'};//inicializamos el arreglo
    imprimirarreglo(A);
    bubblesort(A);
    imprimirarreglo(A);
}
