#include "bicola.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    BICOLA *l;
    l = crear_bicola();
    
    int I = 'I', F = 'F';
    
    printf("\n\tEJERCICIO 02 - BICOLA\n");
	
	printf("\n\tInsertar 3 al inicio");
    insetar(l, 3, I);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 2 al inicio");
    insetar(l, 2, I);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 7 al final");
    insetar(l, 7, F);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 11 al inicio");
    insetar(l, 11, I);
    imprimir_bicola(l);
    
    printf("\n\tInsertar 4 al final");
    insetar(l, 4, F);
    imprimir_bicola(l);
    
    printf("\n\tEliminar al inicio");
    eliminar(l, I);
    imprimir_bicola(l);
    
    printf("\n\tEliminar al final");
    eliminar(l, F);
    imprimir_bicola(l);

    vaciar(l);
    
    imprimir_bicola(l);
    vaciar(l);
}
