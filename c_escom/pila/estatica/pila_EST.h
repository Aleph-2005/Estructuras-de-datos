#define MAX 1000

struct pila
{
    char ele[MAX];
    int tope;
};

void inicilizar (struct pila *p);
int isEmpty(struct pila* p);

