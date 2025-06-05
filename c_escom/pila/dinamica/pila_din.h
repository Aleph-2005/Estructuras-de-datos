struct nodo 
{
    int valor;
    struct nodo *siguiente;
};

struct pila
{
    struct nodo* tope;
};

void init (struct pila*p);
int isEmpty(struct pila *p);
void push(int l,struct pila* p);
int pop(struct pila*p);
void imprimirpila(struct pila* p);

