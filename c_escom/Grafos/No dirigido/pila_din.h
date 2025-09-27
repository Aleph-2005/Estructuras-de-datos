#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

// Nodo exclusivo para pila
struct NodoPila {
    void* valor;
    struct NodoPila* siguiente;
};

// Estructura de pila
struct Pila {
    struct NodoPila* tope;
};

// Inicializa la pila
void pila_inicializar(struct Pila* pila);

// Verifica si la pila está vacía
int pila_esta_vacia(struct Pila* pila);

// Inserta un elemento en la pila
void pila_apilar(void* elemento, struct Pila* pila);

// Extrae el elemento del tope
void* pila_desapilar(struct Pila* pila);

// Imprime los elementos de la pila
void pila_mostrar(struct Pila* pila, void (*mostrar_dato)(void*));

// Libera toda la memoria de la pila
void pila_destruir(struct Pila* pila);

#endif

