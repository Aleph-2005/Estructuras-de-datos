struct nodo{
        char* nombre;
        char* primerap;
        char* segapell;
        char* matricula;
        struct nodo* siguiente;
        struct nodo* anterior;
          
};

struct lista{
    struct nodo* frente;
    struct nodo* final;
};

void init(struct lista* p);
int isempty(struct lista*p);
struct nodo* crearnodo(char*nombre,char*primerap,char* segapell,char* matricula);
void insertinicio(struct lista*p, char*nombre,char*primerap,char* segapell,char* matricula);
void insertfinal(struct lista*p, char*nombre,char*primerap,char* segapell,char* matricula);
void insertn(struct lista*p,char*nombre,char*primerap,char* segapell,char* matricula,int n);
void imprimirlista1(struct lista*p);
void imprimirlista2(struct lista*p);
char* eliminarfrente(struct lista*p);
char* eliminarFinal(struct lista*p);
char* eliminarPosicion(struct lista *p,int n);
int busqueda(struct lista* p,char* matricula);




