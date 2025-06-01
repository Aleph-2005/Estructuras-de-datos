#include <stdio.h>

void swap(char*a,char*b)/*funcion swap nos ayuda a intercambiar 
los valores de dos variables*/
{
    char aux=*a;
    *a=*b;
    *b=aux;
}

void selectionsort(char A[5])
{
    for(int i=0;i<5;i++)/*Iteramos sobre todas las posiciones del arreglo*/
    {
        int aux=*(A+i);/*Definimos una variable auxiliar que
        nos servira para guardar el minimo, la incializamos
        con el elemento i_esimo del arreglo*/
        int l;/*variable donde almacenaremos el indice del
        elemento menos*/
        for(int j=i;j<5;j++)/*iteramos sobre los elementos
        restantes del i_esimo al n-1_esimo*/
        {
            if(*(A+j)<=aux)/*si encontramos un elemento
            menor a nuestro auxiliar*/
            {
                aux=*(A+j);/*Redefinimos a nuestro auxilar*/
                l=j;/*guardamos el nuevo indice del elemento menor*/
            }
        }
        swap((A+i),(A+l));/*Al encontra el elemento menor
        simplemente lo intercambiamos con la posicion i_esima
        de nuestro arreglo, pues es primera*/
    }
}
void imprimirarreglo(char c[5])/*imprime un arreglo de 
caracteres a traves de un bucle for*/
{
    for (int l = 0; l < 5; l++)
        {
            printf("%c ",*(c+l));
        }
    printf("\n");
}

int main()
{
    char A[5]={'D','L','A','Z','W'};//inicilalizamos el arreglo a ordenar
    imprimirarreglo(A);
    selectionsort(A);
    imprimirarreglo(A);
}