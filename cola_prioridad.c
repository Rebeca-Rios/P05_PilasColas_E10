#include "cola_prioridad.h"
#include <stdio.h>
#include <stdlib.h>

nodo* crear_nodo(INFO info, int prioridad){
    nodo* t = (nodo*)malloc(sizeof(nodo));
	t->sig = NULL;
	t->ant = NULL;
	t->info = info;
	t->prioridad = prioridad;
	return t;
}

void eliminar_nodo(nodo *n){
    if(n->sig == NULL  &&  n->ant == NULL){
		free(n);
		n = NULL;
	}
}

BICOLA *crear_bicola(){
    BICOLA* dl = (BICOLA*)malloc(sizeof(BICOLA));
	dl->head = dl->tail = NULL;
	dl->num = 0;
	return dl;
}

bool insetar_inicio(BICOLA *l, INFO info, int prioridad){
	nodo *nuevo = crear_nodo(info, prioridad);
	if(l->head == NULL  &&  l->tail == NULL){
		l->head = l->tail = nuevo;
		l->num++;
	} else{
		nuevo->sig = l->head;
		l->head->ant = nuevo;
		l->head = nuevo;
		l->num++;
	}
	return true;
}

bool insetar_final(BICOLA *l, INFO info, int prioridad){
	nodo *nuevo = crear_nodo(info, prioridad);
	if(l->head == NULL  &&  l->tail == NULL){
		l->head = l->tail = nuevo;
		l->num++;
	} else{
		l->tail->sig = nuevo;
		nuevo->ant = l->tail;
		l->tail = nuevo;
		l->num++;
	}
	return true;
}

bool insertar(BICOLA* l, INFO info, int prioridad){
    if(prioridad == 1) return insetar_final(l, info, prioridad);
    if(prioridad == 3) return insetar_inicio(l, info, prioridad);
    if(prioridad == 2){
        if(l->head->prioridad != 3) return insetar_inicio(l, info, prioridad);
        else{
            nodo* temporal;
            nodo* nuevo = crear_nodo(info, prioridad);
            for(temporal = l->head; temporal->prioridad == 3; temporal = temporal->sig);
            nuevo->sig = temporal;
            nuevo->ant = temporal->ant;
            nuevo->ant->sig = nuevo;
            nuevo->sig->ant = nuevo;
            l->num++;
            return true;
        }
    }
    return false;
}

void eliminar_inicio(BICOLA *l){
	l->head = l->head->sig;
	l->head->ant->sig = NULL;
	free(l->head->ant);
	l->head->ant = NULL;
	l->num--;
}

void eliminar_final(BICOLA *l){
	l->tail = l->tail->ant;
	l->tail->sig->ant = NULL;
	free(l->tail->sig);
	l->tail->sig = NULL;
	l->num--;
}

void eliminar(BICOLA *l, char pos){
	if(pos == 'I') return eliminar_inicio(l);
	else if(pos == 'F') return eliminar_final(l);
}

bool es_vacia(BICOLA *l){
    if(l->head == NULL && l->tail ==NULL) return true;
    return false;
}

bool vaciar(BICOLA *l){
    if(es_vacia(l)) return false;
    nodo* temporal = l->head;
    while(temporal !=NULL){
        l->head = temporal->sig;
        free(temporal);
        temporal = l->head;
    }
    l->head = l->tail = NULL;
    l->num = 0;
    return true;
} 

void imprimir_bicola(BICOLA *l){
	printf("\n\t");
    for(nodo* t = l->head;t != NULL; t = t->sig){
        printf("%d -> ", t->info);
    }
    printf("\n");
}
