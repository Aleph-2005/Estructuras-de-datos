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
int isEmpty(struct nodo* tope);
void push(int l,struct nodo** tope);
int pop(struct nodo** tope);
void imprimirpila(struct nodo* tope);

