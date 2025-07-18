#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "arbol.h"
#include "pila_char_ptr.h"

 struct nodoarbol* crearnodoarbolbinario(char*valor,struct nodoarbol* izq,struct nodoarbol* der)
 {
    struct nodoarbol* nuevo=(struct nodoarbol*)malloc(sizeof(struct nodoarbol));
    nuevo->valor=strdup(valor);
    nuevo->izq=izq;
    nuevo->der=der;
    return nuevo;
 }

struct nodoarbol* crearnodoarbol(char*valor)
 {
    struct nodoarbol* nuevo=(struct nodoarbol*)malloc(sizeof(struct nodoarbol));
    nuevo->valor=strdup(valor);
    nuevo->izq=NULL;
    nuevo->der=NULL;
    return nuevo;
 }

 void liberararb(struct nodoarbol* raiz) 
 {
    if (!raiz) return;
    liberararb(raiz->izq);
    liberararb(raiz->der);
    free(raiz);
}
int esfuncion(char* l)
{
    if(strcmp(l,"x")==0|| strcmp(l,"cos")==0 || strcmp(l,"sen")==0 || strcmp(l,"ln")==0)
        return 1;
    return 0;
}

int esoperador(char*l)
{
    if (strcmp(l, "+") == 0 || strcmp(l, "-") == 0 ||
    strcmp(l, "*") == 0 || strcmp(l, "/") == 0 ||
    strcmp(l, "^") == 0)
        return 1;
    return 0;
}

struct nodoarbol* construir_arbol_postfijo(char* tokens[]) 
{
    struct pila pila;
    init(&pila);
    int i = 0;
    while (tokens[i]) {
        if (esoperador(tokens[i]))
        {
            struct nodoarbol* der = (struct nodoarbol*)pop(&pila);
            struct nodoarbol* izq = (struct nodoarbol*)pop(&pila);
            struct nodoarbol* op = crearnodoarbolbinario(tokens[i],izq,der);
            
            push(op, &pila);
        } 
        else if (strcmp(tokens[i], "sen") == 0 || strcmp(tokens[i], "cos") == 0 || strcmp(tokens[i], "ln") == 0) 
        {
            struct nodoarbol* arg = (struct nodoarbol*)pop(&pila);
            struct nodoarbol* func = crearnodoarbolbinario(tokens[i],arg,NULL);
            push(func, &pila);
        } 
        else 
        {
            push(crearnodoarbolbinario(tokens[i],NULL,NULL), &pila);
        }
        i++;
    }

    return (struct nodoarbol*)pop(&pila);
}

void imprimir_infijo(struct nodoarbol* raiz) {
    if (!raiz) return;

    // Si es una función unaria
    if (strcmp(raiz->valor, "sen") == 0 || strcmp(raiz->valor, "cos") == 0 || strcmp(raiz->valor, "ln") == 0) {
        printf("%s(", raiz->valor);
        imprimir_infijo(raiz->izq);
        printf(")");
        return;
    }

    // Si es un operador binario
    if (raiz->izq && raiz->der) {
        printf("(");
        imprimir_infijo(raiz->izq);
        printf("%s", raiz->valor);
        imprimir_infijo(raiz->der);
        printf(")");
        return;
    }

    // Si es una hoja (número o variable)
    printf("%s", raiz->valor);
}

struct nodoarbol* copiar_subarbol(struct nodoarbol* raiz)
{
    if(!raiz)
        return NULL;
    struct nodoarbol*cop=crearnodoarbol(raiz->valor);
    cop->izq=copiar_subarbol(raiz->izq);
    cop->der=copiar_subarbol(raiz->der);
    return cop;
}


struct nodoarbol* derivada(struct nodoarbol* raiz)
{
    if(!raiz)
        return NULL;
    if(isdigit(*(raiz->valor)) || (isalpha(*(raiz->valor)) && !esfuncion(raiz->valor)))
        return crearnodoarbol("0");
    if(strcmp(raiz->valor,"x")==0)
        return crearnodoarbol("1");
    if(strcmp(raiz->valor,"+")==0 || strcmp(raiz->valor,"-")==0)
    {
        return crearnodoarbolbinario(raiz->valor,derivada(raiz->izq),derivada(raiz->der));
    }
    if(strcmp(raiz->valor,"sen")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("cos",copiar_subarbol(raiz->izq),NULL);
        struct nodoarbol* g=derivada(raiz->izq);
        return crearnodoarbolbinario("*",f,g);
    }
    if(strcmp(raiz->valor,"cos")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("sen",copiar_subarbol(raiz->izq),NULL);
        struct nodoarbol* f_=crearnodoarbolbinario("*",crearnodoarbol("-1"),f);
        struct nodoarbol* g=derivada(raiz->izq);
        return crearnodoarbolbinario("*",f_,g);
    }
    if(strcmp(raiz->valor,"ln")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("/",crearnodoarbol("1"),copiar_subarbol(raiz->izq));
        struct nodoarbol* g=derivada(raiz->izq);
        return crearnodoarbolbinario("*",f,g);
    }
    if(strcmp(raiz->valor,"*")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("*",derivada(raiz->izq),copiar_subarbol(raiz->der));
        struct nodoarbol* g=crearnodoarbolbinario("*",copiar_subarbol(raiz->izq),derivada(raiz->der));
        return crearnodoarbolbinario("+",f,g);
    }
    if(strcmp(raiz->valor,"/")==0)
    {
        struct nodoarbol* f=crearnodoarbolbinario("*",derivada(raiz->izq),raiz->der);
        struct nodoarbol* g=crearnodoarbolbinario("*",raiz->izq,derivada(raiz->der));
        struct nodoarbol* l=crearnodoarbolbinario("-",f,g);
        return crearnodoarbolbinario("/",l,crearnodoarbolbinario("^",raiz->der,crearnodoarbol("2")));
    }
    if (strcmp(raiz->valor, "^") == 0) 
    {
    if (strcmp(raiz->izq->valor, "x") == 0 && isdigit(*(raiz->der->valor)) )
    {
        int n = atoi(raiz->der->valor);
        char nuevo_exponente[10];
        sprintf(nuevo_exponente, "%d", n - 1);
        struct nodoarbol* coef = crearnodoarbolbinario(raiz->der->valor, NULL, NULL);
        struct nodoarbol* potencia = crearnodoarbolbinario("^", copiar_subarbol(raiz->izq), crearnodoarbol(nuevo_exponente));
        return crearnodoarbolbinario("*", coef, potencia);
    }
    if (strcmp(raiz->izq->valor, "x") == 0 && isalpha(*(raiz->der->valor)) && !esfuncion(raiz->der->valor))
    {
        char nuevo_exponente[10];
        sprintf(nuevo_exponente, "%s-%d",raiz->der->valor,1);
        struct nodoarbol* coef = crearnodoarbolbinario(raiz->der->valor, NULL, NULL);
        struct nodoarbol* potencia = crearnodoarbolbinario("^", copiar_subarbol(raiz->izq), crearnodoarbol(nuevo_exponente));
        return crearnodoarbolbinario("*", coef, potencia);
    }
    if(esfuncion(raiz->der->valor)  && esfuncion(raiz->izq->valor))
    {
        struct nodoarbol* l=crearnodoarbolbinario("ln",copiar_subarbol(raiz->izq),NULL);
        struct nodoarbol* r=crearnodoarbolbinario("*",l,raiz->der);
        return crearnodoarbolbinario("*",derivada(r),raiz);
    }

    if(strcmp(raiz->izq->valor,"e")==0 && esfuncion(raiz->der->valor))
    {
        struct nodoarbol* l=crearnodoarbolbinario("^",crearnodoarbol("e"),copiar_subarbol(raiz->der));
         return crearnodoarbolbinario("*",derivada(raiz->der),l);
    }

    if(isalpha(*(raiz->izq->valor)) && isalpha(*(raiz->der->valor)))
    {
        return crearnodoarbol("0");
    }
    }
}

struct nodoarbol* simplificar(struct nodoarbol* raiz)
{
    if (!raiz) return NULL;

    raiz->izq = simplificar(raiz->izq);
    raiz->der = simplificar(raiz->der);

    // Simplificación de suma
    if (strcmp(raiz->valor, "+") == 0) {
        if (raiz->izq && strcmp(raiz->izq->valor, "0") == 0) {
            struct nodoarbol* temp = raiz->der;
            free(raiz->valor);
            free(raiz);
            return temp;
        }
        if (raiz->der && strcmp(raiz->der->valor, "0") == 0) {
            struct nodoarbol* temp = raiz->izq;
            free(raiz->valor);
            free(raiz);
            return temp;
        }
    }

    // Simplificación de multiplicación
    if (strcmp(raiz->valor, "*") == 0) {
        if ((raiz->izq && strcmp(raiz->izq->valor, "0") == 0) ||
            (raiz->der && strcmp(raiz->der->valor, "0") == 0)) {
            liberararb(raiz->izq);
            liberararb(raiz->der);
            free(raiz->valor);
            free(raiz);
            return crearnodoarbol("0");
        }
        if (raiz->izq && strcmp(raiz->izq->valor, "1") == 0) {
            struct nodoarbol* temp = raiz->der;
            free(raiz->valor);
            free(raiz);
            return temp;
        }
        if (raiz->der && strcmp(raiz->der->valor, "1") == 0) {
            struct nodoarbol* temp = raiz->izq;
            free(raiz->valor);
            free(raiz);
            return temp;
        }
    }

    // Simplificación de potencia
    if (strcmp(raiz->valor, "^") == 0) {
        if (raiz->der && strcmp(raiz->der->valor, "1") == 0) {
            struct nodoarbol* temp = raiz->izq;
            free(raiz->valor);
            free(raiz->der);
            free(raiz);
            return temp;
        }
        if (raiz->der && strcmp(raiz->der->valor, "0") == 0) {
            liberararb(raiz->izq);
            free(raiz->valor);
            free(raiz->der);
            free(raiz);
            return crearnodoarbol("1");
        }
    }

    return raiz;
}

void imprimir_infijolatex(struct nodoarbol* raiz) 
{
    if (!raiz) return;

    // Funciones unarias como \sen, \cos, \ln
    if ( strcmp(raiz->valor, "cos") == 0 || strcmp(raiz->valor, "ln") == 0) 
    {
        printf("\\left(\\%s", raiz->valor);
        imprimir_infijolatex(raiz->izq);
        printf("\\right)");
        return;
    }
    
    if ( strcmp(raiz->valor, "sen") == 0) 
    {
        printf("\\left(\\sin");
        imprimir_infijolatex(raiz->izq);
        printf("\\right)");
        return;
    }

    // Operadores binarios
    if (raiz->izq && raiz->der) {
        printf("\\left(");
        

        // Imprimir operador en formato LaTeX
        if (strcmp(raiz->valor, "*") == 0)
        {
            imprimir_infijolatex(raiz->izq);
            printf("\\cdot ");
        }
        else if (strcmp(raiz->valor, "/") == 0)
        {
            printf("\\frac{");
            imprimir_infijolatex(raiz->izq);
            printf("}");
        }
        else if (strcmp(raiz->valor, "^") == 0)
        {
            imprimir_infijolatex(raiz->izq);
            printf("^{");
        }
        else
        {
            imprimir_infijolatex(raiz->izq);
            printf("%s", raiz->valor);  // +, -, etc.
        }

        // Casos especiales como fracciones y potencias
        if (strcmp(raiz->valor, "/") == 0) 
        {
            printf("{");
            imprimir_infijolatex(raiz->der);
            printf("}");
        } 
        else if (strcmp(raiz->valor, "^") == 0) 
        {
            imprimir_infijolatex(raiz->der);
            printf("}");
        } 
        else 
        {
            imprimir_infijolatex(raiz->der);
        }

        printf("\\right)");
        return;
    }

    // Hoja (número o variable)
    if(strcmp(raiz->valor,"x")==0)
    {
        printf("(%s)",raiz->valor);
        return;
    }
    printf("%s", raiz->valor);
}

double aplicarfuncion(char*l,char* arg)
{
    if(strcmp("sen",l)==0)
    {
       return sin(strtod(arg,NULL));
    }
    if(strcmp("cos",l)==0)
    {
       return cos(strtod(arg,NULL));
    }
    if(strcmp("ln",l)==0)
    {
        if(atof(arg)<0)
            return NAN;
        return log(atof(arg));
    }
    return NAN;
}

double aplicaroperacion(char*l,char*izq,char*der)
{
    double valizq=strtod(izq,NULL);
    double valder=strtod(der,NULL);
    if(strcmp(l,"^")==0)
    {
        return pow(valizq,valder);
    }
    if(strcmp(l,"+")==0)
    {
        return valder+valizq;
    }
    if(strcmp(l,"-")==0)
    {
        return valder-valizq;
    }
    if(strcmp(l,"*")==0)
    {
        return valder*valizq;
    }
    if(strcmp(l,"/")==0)
    {
        if(valder==0)
            return NAN;
        return valizq/valder;
    }
    return NAN;
}


int esNumerico(const char *cadena) 
{
    if (cadena == NULL || *cadena == '\0') 
        return 0;
    // Ignorar espacios iniciales
    while (isspace(*cadena)) cadena++;

    char *fin;
    strtod(cadena, &fin);

    // Ignorar espacios finales
    while (isspace(*fin)) fin++;

    // Si llegamos al final, la cadena es numérica
    if(!*fin)
        return 1;
    return 0;
}

char* evaluarArbolComoCadena(struct nodoarbol* root,double y) 
{
    if (!root) 
        return strdup("");
    char* izq = evaluarArbolComoCadena(root->izq,y);
    char* der = evaluarArbolComoCadena(root->der,y);
    char* resultado = NULL;

    if(root->izq && root->der)
    {
        if (esNumerico(izq) && esNumerico(der)) 
        {
            double val = aplicaroperacion(root->valor, izq, der);
            if (isinf(val)) 
            {
                printf("Excediste el rango de pow, imposible valuar\n");
                return NULL;
            }
            resultado = malloc(64);
            snprintf(resultado, 64, "%g", val);
        }
        else 
        {
            size_t len = strlen(izq) + strlen(root->valor) + strlen(der) + 6;
            resultado = malloc(len);
            snprintf(resultado, len, "(%s %s %s)", izq, root->valor, der);
        }
    }
    if(strcmp(root->valor, "sen") == 0 || strcmp(root->valor, "cos") == 0 || strcmp(root->valor, "ln") == 0)
    {
        if (esNumerico(izq)) 
        {
            double val = aplicarfuncion(root->valor, izq);
            if (isnan(val)) 
                printf("La Función '%s' de '%s' dio NaN\n", root->valor, izq);
            resultado = malloc(64);
            snprintf(resultado, 64, "%g", val);
        } 
        else 
        {
            size_t len = strlen(root->valor) + strlen(izq) + 4;
            resultado = malloc(len);
            snprintf(resultado, len, "%s(%s)", root->valor, izq);
        }
    }
    if (!root->izq && !root->der) 
    { // Nodo hoja
        if (strcmp(root->valor, "x") == 0) 
        {
            resultado = malloc(32);
            snprintf(resultado, 32, "%g", y);
        }
        else 
            resultado = strdup(root->valor);
    }
    free(izq);
    free(der);
    return resultado;
}
