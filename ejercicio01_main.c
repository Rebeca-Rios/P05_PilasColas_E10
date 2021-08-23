#include "ejercicio01.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
	int i, num;
	char entrada[100];
    PILA *auxiliar, *salida;
    auxiliar = crear_pila();
    salida = crear_pila();
    
    printf("\n\n\tIngresa la cadena:\t");
	scanf("%s", &entrada);
	num = strlen(entrada);
	
	for(i = 0; i < num; i++)
		clasificar(entrada[i], auxiliar, salida);
	
	trasvasar(auxiliar, salida);
	
	printf("\n\n\tLa cadena de salida queda como:\t");
    imprimir_pila(salida);
	
    vaciar(auxiliar);
    vaciar(salida);
    
    free(auxiliar);
    free(salida);
    
    printf("\n");
}
