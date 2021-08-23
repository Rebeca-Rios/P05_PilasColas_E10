#include "ejercicio01.h"
#include <stdio.h>
#include <stdlib.h>

nodo* crear_nodo(INFO info, int p){
    nodo* t = (nodo*)malloc(sizeof(nodo));
    t->sig = NULL;
    t->info = info;
    t->p = p;
    return t;
}

void eliminar_nodo(nodo *n){
    if(n->sig == NULL){
        free(n);
        n = NULL;
    }
}

bool push(PILA *l, INFO info){
	if(info != ')'){
		nodo* nuevo = crear_nodo(info, prioridad(info));
	    if(l->top == NULL && l->bottom == NULL){
	        l->top = l->bottom = nuevo; // l->head = nuevo; l->tail = nuevo;
	        l->num++;
	        return true;
	    }else{
	        nuevo->sig = l->top;
	        l->top = nuevo;
	        l->num++;
	        return true;
	    }
	}
    return false;
}

bool push_clasificar(PILA *auxiliar, PILA *salida, INFO info){
    nodo* nuevo = crear_nodo(info, prioridad(info));
    if(auxiliar->top == NULL && auxiliar->bottom == NULL) //si auxiliar está vacía, agregarlo a pila auxiliar
		push(auxiliar, info);
    else{
    	if(nuevo->p != 0  && nuevo->p != -1){ //si el operador es diferente a '(' y diferente a ')'
    		while(!es_vacia(auxiliar)  &&  nuevo->p <= auxiliar->top->p) //si la prioridad del operador <= prioridad de la cima
    			pop(auxiliar, salida, info); //sacar la cima
    		push(auxiliar, info); //de otro modo agregar a auxiliar (prioridad operador > cima)
	    } else{ //si es '(' o ')'
	    	if(nuevo->p == 0) //si es '('
	    		push(auxiliar, info); //agregar a auxiliar
	    	if(nuevo->p == -1){ //si es ')'	    	
	    		while(auxiliar->top->p != 0)//si la cima NO es '('
	    			pop(auxiliar, salida, info); //sacar la cima
	    		pop(auxiliar, salida, info);
	    		push(auxiliar, info); //de otro modo agregar a auxiliar
	    	}
	    }
    }
    return false;
}

void pop(PILA *auxiliar, PILA *salida, INFO info){
    if(es_vacia(auxiliar)) return;
    
    push(salida, auxiliar->top->info); //agrega la info de top a la pila de salida antes de borrar top
	
	//borra cima
	if(auxiliar->num > 1){
		nodo *temporal = auxiliar->top;
	    auxiliar->top = auxiliar->top->sig;
	    temporal->sig = NULL;
	    eliminar_nodo(temporal);
	    auxiliar->num--;  
	} else
		vaciar(auxiliar);	
}

PILA *crear_pila(){
    PILA* l = (PILA*) malloc(sizeof(PILA));
    l->top = l->bottom = NULL;
    l->num = 0;
    return l;
}

bool es_vacia(PILA *l){
    if(l->top == NULL && l->bottom ==NULL) return true;
    return false;
}

bool vaciar(PILA *l){
    if(es_vacia(l)) return false;
    nodo* temporal = l->top;
    while(temporal != NULL){
        l->top = temporal->sig;
        free(temporal);
        temporal = l->top;
    }
    
    l->top = l->bottom = NULL;
    l->num = 0;
	
    return true;
} 

bool trasvasar(PILA *auxiliar, PILA *salida){
	if(es_vacia(auxiliar)) return false;
    nodo* temporal = auxiliar->top;
    while(temporal != NULL){
    	push(salida, temporal->info); //agrega la info de temporal a la pila de salida
	    temporal = temporal->sig;
    }
    return true;
}

void imprimir_pila(PILA *l){
	for(nodo* t = l->top;t != NULL; t = t->sig){
	    if(t->p != 0  &&  t->p != -1)
	       	printf("%c", t->info);
	}
	printf("\n");
}

void clasificar(char info, PILA *auxiliar, PILA *salida){
	if(info != '+'  &&  info != '-'  &&  info != '*'  &&  info != '/'  &&  info != '^'  &&  info != '('  &&  info != ')'){
		//si info NO es un operador agregar a la pila de salida
		push(salida, info);
	} else{
		//de otra manera, agregar a la pila auxiliar
		push_clasificar(auxiliar, salida, info);
	}
}

int prioridad(INFO info){ //asigna un valor numérico dependiendo de la prioridad del caracter
	int p;
    if (info == '^') p = 3;
    else if (info == '*') p = 2;
    else if (info == '/') p = 2;
    else if (info == '+') p = 1;
    else if (info == '-') p = 1;
    else if (info == '(') p = 0;
    else if (info == ')') p = -1; 
    else p = 4;
    return p;
}
