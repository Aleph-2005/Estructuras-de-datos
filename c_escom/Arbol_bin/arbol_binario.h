struct nodo_arbol
{
    void * dato;
    struct nodo_arbol* izq;
    struct nodo_arbol* der;
};

struct nodo_arbol* crearnodo(void* val);
struct nodo_arbol* crearnodoapuntado(void* val,struct nodo_arbol* izq,struct nodo_arbol* der);
void inorderDFS(struct nodo_arbol* raiz,void (print_type)(void *));
void preorderDFS(struct nodo_arbol* raiz,void (print_type)(void *));
void postorderDFS(struct nodo_arbol* raiz,void (print_type)(void *));