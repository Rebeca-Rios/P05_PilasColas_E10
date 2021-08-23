#include "cola_prioridad.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    BICOLA *l;
    l = crear_bicola();
    
    printf("\n\tEJERCICIO 03 - COLA DE PRIORIDAD\n");
	
	printf("\n\tInsertar 88 con prioridad 3");
    insertar(l, 88, 3);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 66 con prioridad 1");
    insertar(l, 66, 1);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 3 con prioridad 3");
    insertar(l, 3, 3);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 42 con prioridad 2");
    insertar(l, 42, 2);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 12 con prioridad 1");
    insertar(l, 12, 1);
    imprimir_bicola(l);

    vaciar(l);
    
    imprimir_bicola(l);
    vaciar(l);
}
