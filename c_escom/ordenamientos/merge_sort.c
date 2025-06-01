//Merge sort
#include <stdio.h>

// Merge two subarrays L and M into arr
void merge(char arr[], int p, int q, int r) 
{

  // separamos la cantidad de elementos que tendra cada subarreglo
  int n1 = q - p + 1;
  int n2 = r - q;

  char L[n1], M[n2];
  //Copiamos la informacion a cada subarreglo
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  // Creamos indices para iniciar la mezcla de los arreglos
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  
  /*Mezclamos los arreglos y los reescribimos en el
  arreglo original*/
  while (i < n1 && j < n2) {
    if (L[i] >= M[j]) 
    /*Vemos que posocion del arreglo es la correcta respecto al orden 
    y la copiamos en el arreglo original*/
    {
      arr[k] = L[i];
      i++;
    } 
    else 
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  /*finalmente copiamos los arreglos restantes
  en el original*/  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

/*Divide el arreglo recursivamente el arreglo en mitades
y las ordena*/ 
void mergeSort(char arr[], int l, int r) {
  if (l < r)/*condicion de paro
  para la recursión, indica si aun es posible
  dividir el subarreglo en mitades*/
  {

    //m es el punto medio donde se dividira el arreglo
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);//generaamos 2 subarreglos
    mergeSort(arr, m + 1, r);

    //genera y ordena(Mezcla) los subarreglos
    merge(arr, l, m, r);
  }
}

// Imprime el arreglo con un ciclo for
void imprimirarreglo(char arr[], int size) 
{
    for (int i = 0; i < size; i++)
    printf("%c ", arr[i]);
    printf("\n");
}

// Implementacion
int main() 
{
    //inicializamos el arreglo char
    char arr[] = {'A', 'Z', 'R', 'S', 'M', 'U'};
    //encontramos la dimensiones del arreglo
    int size = sizeof(arr) / sizeof(arr[0]);
    imprimirarreglo(arr,size);
    mergeSort(arr, 0, size - 1);
    imprimirarreglo(arr, size);
}