struct Nodo
{
  int dato;
  struct Nodo* siguiente;
};

struct queue
{
  struct Nodo*frente;
  struct Nodo*final;
};

void init(struct queue* p);
int isempty(struct queue* p);
void encolar(struct queue* p,int z);
int desencolar(struct queue* p);
void imprimircola(struct queue* p);
