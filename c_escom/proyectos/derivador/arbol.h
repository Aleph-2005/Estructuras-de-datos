struct nodoarbol
{
    char* valor;
    struct nodoarbol* izq;
    struct nodoarbol* der;
};

struct nodoarbol* crearnodoarbol(char*valor);
void liberararb(struct nodoarbol* raiz);
struct nodoarbol* construir_arbol_postfijo(char* tokens[]);
void imprimir_infijo(struct nodoarbol* raiz);