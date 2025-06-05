struct nodo{
        int dato;
        struct nodo* siguiente;
        struct nodo* anterior;
          
};

struct lista{
    struct nodo* frente;
    struct nodo* final;
};

void init(struct lista* p);
int isempty(struct lista*p);
struct nodo* crearnodo(int dato);
void insertinicio(struct lista*p, int dato);
void insertfinal(struct lista*p, int dato);
void insertn(struct lista*p, int dato, int n);
void imprimirlista(struct lista*p);
int eliminarfrente(struct lista*p);
int eliminarFinal(struct lista*p);
int eliminarPosicion(struct lista *p,int n);




