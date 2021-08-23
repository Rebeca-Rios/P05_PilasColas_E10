#ifndef EJERCICIO01_H
#define EJERCICIO01_H

#include <stdbool.h>

typedef struct _nodo nodo;
typedef char INFO;

struct _nodo{
    INFO info;
    nodo *sig;
    int p; //prioridad del caracter
};


typedef struct _lista PILA;

struct _lista{
    nodo *top;
    nodo *bottom;
    int num;
};


nodo* crear_nodo(INFO info, int p);
void eliminar_nodo(nodo *n);
PILA *crear_pila();
bool es_vacia(PILA *l);
bool vaciar(PILA *l);
bool trasvasar(PILA *auxiliar, PILA *salida);
bool push(PILA *l, INFO info);
bool push_clasificar(PILA *auxiliar, PILA *salida, INFO info);
void pop(PILA *auxiliar, PILA *salida, INFO info);
void imprimir_pila(PILA *l);
void clasificar(char info, PILA *entrada, PILA *salida);
int prioridad(INFO info);

#endif
