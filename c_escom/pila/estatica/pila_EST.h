#define MAX 1000

struct pila
{
    int ele[MAX];
    int tope;
};

void inicializar (struct pila *p);
int isEmpty(struct pila* p);
int isfull(struct pila *p);
void push(struct pila *p,int z);
int pop(struct pila *p);
void imprimirpila(struct pila *p);

