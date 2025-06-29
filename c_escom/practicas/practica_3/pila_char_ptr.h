struct nodo 
{
    char* valor;
    struct nodo *siguiente;
};

struct pila
{
    struct nodo* tope;
};

void init (struct pila*p);
int isEmpty(struct pila *p);
void push(char* l,struct pila* p);
char* pop(struct pila*p);
void imprimirpila(struct pila* p);
void destroy(struct pila* p);