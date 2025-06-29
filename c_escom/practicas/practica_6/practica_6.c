#include <stdio.h>
#include <string.h>
#include "lista_DE.h"

void imprimirmenu()//funcion que imprime el menu
{
  printf("Bienvenido al sistema de simulacion de un sistema escolar\n");
  printf("Si quiere agregar un alumno presione 1\n");
  printf("Si quiere eliminar un alumno presione 2\n");
  printf("Si quiere ver las lista de alumnos presione 3\n");
  printf("Si quiere encontrar un alumno presione 4\n");
  printf("Preione 5 para salir\n");
}

void decidir(int n,char* nombre,char* primerap,char* seguapll, char* matricula,struct lista* p)
{
    switch (n)
    {
    case 1:
        insertinicio(p,nombre,primerap,seguapll,matricula);
        break;
    case 2:
        insertfinal(p,nombre,primerap,seguapll,matricula);
        break;
    case 3:
        printf("Dame la posicion que quieres\n");
        int l;
        scanf("%d",&l);
        insertn(p,nombre,primerap,seguapll,matricula,l);
        break;
    default:
        printf("Caracter invalido\n");
        break;
    }
}

void decidir2(int n,struct lista* p)
{
    switch (n)
    {
    case 1:
        eliminarfrente(p);
        break;
    case 2:
        eliminarFinal(p);
        break;
    case 3:
        printf("Dame la posicion que quieres\n");
        int l;
        scanf("%d",&l);
        eliminarPosicion(p,l);
        break;
    default:
        printf("Caracter invalido\n");
        break;
    }
}
void cas(struct lista* p,int u,char* nombre,char* primerap,char* seguapll, char* matricula,int* r)
//funcion que dice que hacer en cada caso
{
  switch (u)
  {
    case 1:
    printf("Dame los datos del alumno que deseas enlistar, maximo 10 caracteres\n");
    printf("Dame el nombre\n");
    scanf("%10s",nombre);
    printf("Dame el primer apellido\n");
    scanf("%10s",primerap);
    printf("Dame el segundo apellido\n");
    scanf("%10s",seguapll);
    printf("Dame la matricula, maximo 6 caracteres\n");
    scanf("%7s",matricula);
    //le pedimos al usuario la posicion en la que se debe insertar
    printf("Donde lo quieres enlistar, frente:1,final:2,posicion especifica:3\n");
    int w;
    scanf("%d",&w);
    decidir(w,nombre,primerap,seguapll,matricula,p);
    printf("si deseas continuar presiona 1 si no 0\n");
    scanf("%d",r);
    if((*r!=1)& (*r!=0))
    {
      printf("caracter invalido\n");
      break;
    }
    //preguntamos si desea continuar y validamos
    break;

    case 2:
    if(!isempty(p))
    {
      printf("Que  quieres eliminar, frente:1,final:2, posicion especifica:3\n");
      int k;
      scanf("%d",&k);
      decidir2(k,p);
    }
    else
      printf("Lista vacia\n");
    printf("si deseas continuar presiona 1 si no 0\n");
    scanf("%d",r);
    if((*r!=1) & (*r!=0))
    {
      printf("caracter invalido\n");
      break;
    }
    //preguntamos si deesa continuar y validamos
    break;

    case 3:
    if(!isempty(p))
    {
      printf("como la quiere imprimir,1 descendente,2 ascendente\n");
      int q;
      scanf("%d",&q);
      if(q==1)
          imprimirlista1(p);
      else if(q==2)
          imprimirlista2(p);
      else
          printf("Caracter invalido");
    }
    else
      printf("Lista vacia\n");
    printf("si deseas continuar presiona 1 si no 0\n");
    scanf("%d",r);
    if((*r!=1) & (*r!=0))
    {
      printf("caracter invalido\n");
      break;
    }
  
    break;

    case 4:
    if(!isempty(p))
    {
      char b[6];
      printf("Dame la matricula que quieres encontrar\n");
      scanf("%6s",b);
      int cont=busqueda(p,b);
      if(cont==-1)
        printf("No encontrado\n");
      else
        printf("Esta en la posicion %d\n",cont);
    }
    else
      printf("Lista vacia\n");
    printf("si deseas continuar presiona 1 si no 0\n");
    scanf("%d",r);
    if((*r!=1) & (*r!=0))
    {
      printf("caracter invalido\n");
      break;
    }
    break;

    case 5:
    *r=0;
    //cambiamos lo apuntado por r para terminar el ciclo
    break;

    default:
    printf("Caracter invalido\n");
    break;
  }
}

int main()
{
    struct lista p;
    init(&p);
    int r=1;
    char nombre[10];
    char primerap[10];
    char seguap[10];
    char matricula[7];
    int u;
    while(r!=0)
  //ciclamos para una buena simulacion
    {
        imprimirmenu();
        scanf("%d",&u);//le pedimos al usuario que quiere hacer
        cas(&p,u,nombre,primerap,seguap,matricula,&r); 
    } 

    printf("gracias por usar el sistema");
}