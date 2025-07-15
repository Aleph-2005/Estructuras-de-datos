struct Nodo
{
  void* dato;
  struct Nodo* siguiente;
};

struct queue
{
  struct Nodo*frente;
  struct Nodo*final;
};

void init(struct queue* p);
int isempty(struct queue* p);
void encolar(struct queue* p,void* z);
void* desencolar(struct queue* p);
void imprimircola(struct queue* p,void (print_tp)(void*));
int len(struct queue *p);
void vaciar(struct queue*p);
