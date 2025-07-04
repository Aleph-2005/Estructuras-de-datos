struct nodo 
{
    void* valor;
    struct nodo *siguiente;
};

struct pila
{
    struct nodo* tope;
};

void init (struct pila*p);
int isEmpty(struct pila *p);
void push(void* l,struct pila* p);
void* pop(struct pila*p);
