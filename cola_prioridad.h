#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H

#include <stdbool.h>

typedef struct _dnodo nodo;
typedef int INFO;

struct _dnodo{
	INFO info;
	nodo *sig;
	nodo *ant;
	int prioridad;
};

typedef struct _dlista BICOLA;

struct _dlista{
	nodo *head;
	nodo *tail;
	int num;
};


nodo* crear_nodo(INFO info, int prioridad);
void eliminar_nodo(nodo *n);
BICOLA *crear_bicola();
bool es_vacia(BICOLA *l);
bool vaciar(BICOLA *l);

bool insetar_inicio(BICOLA *l, INFO info, int prioridad);
bool insetar_final(BICOLA *l, INFO info, int prioridad);
bool insertar(BICOLA* l, INFO info, int prioridad);

void eliminar_inicio(BICOLA *l);
void eliminar_final(BICOLA *l);
void eliminar(BICOLA *l, char pos);

void imprimir_bicola(BICOLA *l);

#endif
