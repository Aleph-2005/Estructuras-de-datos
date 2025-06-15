struct nodo{
        int dato;
        char* nombre;
        struct nodo* siguiente;
        struct nodo* anterior;
          
};

struct lista{
    struct nodo* frente;
    struct nodo* final;
};

void init(struct lista* p);
int isempty(struct lista*p);
struct nodo* crearnodo(int dato, char* val);
void insertinicio(struct lista*p, int dato,char* r);
void insertfinal(struct lista*p, int dato,char* r);
void insertn(struct lista*p, int dato, int n,char *r);
void imprimirlista1(struct lista*p);
void imprimirlista2(struct lista*p);
int eliminarfrente(struct lista*p);
int eliminarFinal(struct lista*p);
int eliminarPosicion(struct lista *p,int n);




