struct nodo
{
    void* dato;
    struct nodo* siguiente;  
};

struct lista{
    struct nodo* frente;
};

void init(struct lista* p);
int isempty(struct lista*p);
struct nodo* crearnodo(void* dato);
void insertinicio(struct lista*p, void* dato);
void insertfinal(struct lista*p, void* dato);
void insertn(struct lista*p, void* dato, int n);
void imprimirlista(struct lista*p,void(print_tp)(void*));
void* eliminarfrente(struct lista*p);
void* eliminarFinal(struct lista*p);
void* eliminarPosicion(struct lista *p,int n);




