struct nodo_RN
{
    void* dato;
    struct nodo_RN* izq;
    struct nodo_RN* der;
    struct nodo_RN* pad;
    int color;
};
struct nodo_RN* crearnodo(void* val,int color);
struct nodo_RN* crearnodoapuntado(void* val,struct nodo_RN* izq,struct nodo_RN* der,struct nodo_RN* pad,int color);
void fix_insert_RN(struct nodo_RN** root,struct nodo_RN* nuevo);
struct nodo_RN* insert_nodo(struct nodo_RN* root, void* dato, int (*cmp)(void*, void*));
void exportar_dot(struct nodo_RN* raiz, FILE* f) ;
void ExportaGraphizint(struct nodo_RN* raiz);