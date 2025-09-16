#include <stdio.h>
#include <string.h>    
#include <stdlib.h>  
#include <math.h>
#define MAX 128
#define CARD 64

void mascarabit(char *t,unsigned long long int* s)
{
    char *v=strtok(t,",");
    while (v)
    {
        *s|=(1ULL<<atoi(v));
        v=strtok(NULL,",");
    }
    
}

void mascarabit2(int n,unsigned long long int* un )
{
    for(int i=0;i<n;i++)
    {
        *(un)|=(1ULL<<i);
    }
}

int vacio(unsigned long long int un)
{
    if(un==0)
        return 1;
    return 0;
}

void traductor(unsigned long long int n )
{
    if(vacio(n))
    {
        printf("Es vacio\n");
        return;
    } 
    int z=0;
    unsigned long long int num=n;
    while(num>1)
    {
        if(num%2==1)
        {
            printf("%d, ",z);
        }
        z++;
        num=num/2;
    }
    printf("%d ", z);
    printf("\n");
}

unsigned long long int un(unsigned long long int a, unsigned long long int b)
{
    return a|b;
}

unsigned long long int inter(unsigned long long int a, unsigned long long int b)
{
    return a & b;
}

unsigned long long int difsim(unsigned long long int a, unsigned long long int b)
{
    return a ^ b;
}

unsigned long long int compl(unsigned long long int a, unsigned long long int un)
{
    return ~a & un;
}

unsigned long long int menos(unsigned long long int a,unsigned long long int b, unsigned long long int un)
{
    return a & compl(b,un);
}

 



int main ()
{
    char s[MAX];
    char l[MAX];
    int c;
    unsigned long long int conjA=0;
    unsigned long long int uni=0;
    unsigned long long int conjB=0;
    printf("Dame la cardinalidad de tu universo\n");
    scanf("%d",&c);
    mascarabit2(c,&uni);
    getchar();
    printf("Dame el conjunto A\n");
    fgets (s, MAX, stdin);
    mascarabit(s,&conjA);
    printf("Dame el conjunto B\n");
    fgets(l,MAX,stdin);
    mascarabit(l,&conjB);
    printf("\n");
    printf("Universo\n");
    traductor(uni);
    printf("\n");
    printf("\n");
    printf("Union\n");
    traductor(un(conjA,conjB));
    printf("Valor:%llu",un(conjA,conjB));
    printf("\n");
    printf("\n");
    printf("Inteseccion\n");
    traductor(inter(conjA,conjB));
    printf("Valor:%llu",inter(conjA,conjB));
    printf("\n");
    printf("\n");
    printf("Diferencia simetrica\n");
    traductor(difsim(conjA,conjB));
    printf("Valor:%llu",difsim(conjA,conjB));
    printf("\n");
    printf("\n");
    printf("A complemento\n");
    traductor(compl(conjA,uni));
    printf("Valor:%llu",compl(conjA,uni));
    printf("\n");
    printf("\n");
    printf("B complemento\n");
    traductor(compl(conjB,uni));
    printf("Valor:%llu",compl(conjB,uni));
    printf("\n");
    printf("\n");
    printf("A menos B\n");
    traductor(menos(conjA,conjB,uni));
    printf("Valor:%llu",menos(conjA,conjB,uni));
    printf("\n");
    printf("\n");
    printf("B menos A\n");
    traductor(menos(conjB,conjA,uni));
    printf("Valor:%llu",menos(conjB,conjA,uni));
    printf("\n");
    printf("\n");
    return 0;
}