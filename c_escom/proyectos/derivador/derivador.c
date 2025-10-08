#include <stdio.h>
#include "pila_char_ptr.h"
#include <string.h>
#include <stdlib.h>
#include "arbol.h"
#include "shunting_yard.h"
#include "leer_entrada.h"

int main()
{
    struct pila p;
    init(&p);
    char l[1000];
    char* new[1000];
    char* new2[1000];
    long double y;
    printf("Dame la funcion que quieres derivar\n");
    scanf("%s",l);
    printf("Dame el punto en donde quieres valuar la derivada\n");
    scanf("%Lf",&y);
    if(leer(l,new) && parentesis(new))
    {
        shuntingyard(new,&p,new2);
        struct nodoarbol* raiz=construir_arbol_postfijo(new2);
        printf("Notacion postfija:\n");
        imprimir(new2);
        printf("\n");
        printf("Derivada:\n");
        raiz=simplificar(derivada(raiz));
        imprimir_infijo(raiz);
        printf("\n"); 
        char* valor=evaluarArbolComoCadena(raiz,y);
        printf("La derivada en %Lf\n",y);
        if(esNumerico(valor))
        {
            long double aproximado = strtod(valor,NULL);
            printf("f'(%Lf) = %.10Lf\n", y, aproximado);
        }
        else
            printf("f(%Lf)=%s",y,valor);
        
        FILE* archivo = fopen("derivada.tex", "w");
        if (archivo) 
        {
            fprintf(archivo, "\\documentclass{article}\n\\usepackage{amsmath}\n\\begin{document}\n");
            fprintf(archivo, "La derivada es:\n\\[\n");
            fprintf(archivo,"f'(x)=");
            imprimir_infijolatex_en_archivo(raiz, archivo);
            fprintf(archivo, "\n\\]\\\\");
            fprintf(archivo, "La derivada en el punto $x_0=%Lf$:\n\\[\n",y);
            fprintf(archivo,"f'(%Lf)=%s",y,valor);
            fprintf(archivo, "\n\\]\n\\end{document}");
            fclose(archivo);    
        }  
        //liberararb(raiz);
        //liberar(new);
        //liberar(new2);
    }
    else
        printf("Entrada invalida");
}