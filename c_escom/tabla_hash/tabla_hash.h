
struct lista
{
    int identificador;
    struct nodo* frente;
    struct lista* siguiente;
};

struct tabla_hash
{
 struct lista* frente_1;
};

struct nodo
{
    int dato;
    struct nodo* siguiente;
};

void init(struct tabla_hash*p);

