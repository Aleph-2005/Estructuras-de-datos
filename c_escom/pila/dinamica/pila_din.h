struct nodo_pila 
{
    void* valor;
    struct nodo_pila *siguiente;
};

struct pila
{
    struct nodo_pila* tope;
};

void init_pila(struct pila*p);
int isEmpty_pila(struct pila *p);
void push(void* l,struct pila* p);
void *pop(struct pila*p);
void printstack(struct pila* p,void (print_tp)(void *));
void destroy(struct pila *p);


