struct nodoarbol
{
    char* valor;
    struct nodoarbol* izq;
    struct nodoarbol* der;
};

void liberararb(struct nodoarbol* raiz);
struct nodoarbol* crearnodoarbol(char*valor);
struct nodoarbol* construir_arbol_postfijo(char* tokens[]);
void imprimir_infijo(struct nodoarbol* raiz);
struct nodoarbol* crearnodoarbolbinario(char*valor,struct nodoarbol* izq,struct nodoarbol* der);
struct nodoarbol* derivada(struct nodoarbol* raiz);
struct nodoarbol* copiar_subarbol(struct nodoarbol* raiz);
struct nodoarbol* simplificar(struct nodoarbol* raiz);
void imprimir_infijolatex(struct nodoarbol* raiz);
double aplicarfuncion(char*l,char* arg);
double aplicaroperacion(char*l,char*izq,char*der);
int esNumerico(const char *cadena);
char* evaluarArbolComoCadena(struct nodoarbol* root,double y);