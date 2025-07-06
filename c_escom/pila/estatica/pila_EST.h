#define MAX 1000

struct pila
{
    void* ele[MAX];
    int tope;
};

void inicializar (struct pila *p);
int isEmpty(struct pila* p);
int isfull(struct pila *p);
void push(struct pila *p,void* z);
void *pop(struct pila *p);
void imprimirpila(struct pila *p,void (print_tp)(void *));

