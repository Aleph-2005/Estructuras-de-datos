#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define MAX 1000
struct cola
{
  char *ele[MAX];
  int tope;
  int final;
};

void incializar(struct cola *p)
{
    p->tope=-1;
    p->final=-1;
}

int isempty(struct cola *p)
{
    if(p->tope==-1)
    {
        return 1;
    }
    return 0;
}

bool isfull(struct cola *p)
{
    if(p->final==MAX-1)
    {
        return true;
    }
    return false;
    
}

void insertar(struct cola *p, char*val)
{
    char* nval=strdup(val);
    if(isfull(p))
    {
        printf("La pila esta llena");
    }
    if(isempty(p))
    {
      p->ele[++(p->final)]=nval;
      ++(p->tope);
    }
    else
    {
       p->ele[++(p->final)]=nval;
    }
}

char* desencolar(struct cola *p)
{
    if(isempty(p))
    {
        return NULL;
    }
    else
    {
      char* tmp=p->ele[(p->tope)];
      (p->tope)++;
      if(p->final<p->tope)
      {
        (p->tope)=(p->final)=-1;
      }
      return tmp;
    }
}

void imprimirmenu()//funcion que imprime el menu
{
  printf("Bienvenido al sistema de simulacion de una fila\n");
  printf("Si quiere enfilar un cliente presione 1\n");
  printf("Si quiere despachar un cliente presione 2\n");
  printf("Si quiere ver el ultimo cliente en fila  presione 3\n");
  printf("Preione 4 para salir\n");
}

void cas(struct cola* p,int u, char*w, char st[11], int *r)
//funcion que dice que hacer en cada caso
{
  switch (u)
  {
    case 1:
    printf("Dame el nombre de la persona que deseas encolar, maximo 10 caracteres\n");
    scanf("%10s",st);
    //pedimos al usaurio el nombre de a persona
    insertar(p,st);
    //lo encolamos
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
    w=desencolar(p);
    //desencolamos
    if(w!=NULL)
    /*si la fila no estaba vacia mostramos
    a quien desencolamos*/
    {
      printf("Se ha atendido a %s\n",w);
    }
    else
    //en caso contrario mostramos un error
    {
      printf("Error, fila vacia\n");
    }
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
    /*si la fila no esta vacia* mostramos la persona
    formada al final, si lo esta lo decimos*/
    if(p->final==-1)
    {
      printf("fila vacia\n");
    }
    else
    {
      printf("en la ultima posicion se encuentra %s\n",p->ele[p->final]);
    }
    printf("si deseas continuar presiona 1 si no 0\n");
    scanf("%d",r);
    if((*r!=1) & (*r!=0))
    {
      printf("caracter invalido\n");
      break;
    }
    //preguntamos si desea continuar y validamos
    break;

    case 4:
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
  struct cola p;//structura lista
  incializar(&p);//incializamos
  int u;//variable a la que aplicaremos switch
  char w[11];//variab le para guardar el valor de desencolar
  char st[11];//variable para los nombres de las personas
  int r=1;//variable para iterar sobre el ciclo
  while(r!=0)
  //ciclamos para una buena simulacion
  {
    imprimirmenu();
    scanf("%d",&u);//le pedimos al usuario que quiere hacer
    cas(&p,u,w,st,&r); 
  }
  printf("gracias por usas el sistema");
}