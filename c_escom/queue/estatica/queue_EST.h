#define MAX 1000
struct queue
{
  void* ele[MAX];
  int tope;
  int final;
};

void init(struct queue* p);
int isEmpty(struct queue* p);
void encolar(struct queue* p,void* z);
void* desencolar(struct queue* p);
void imprimircola(struct queue* p,void (print_tp)(void*));
