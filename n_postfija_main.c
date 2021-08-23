#include "n_postfija.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int num, cont = 0, s = -1;
    char* cadena1; //cadena de entrada
    char* cadena2; //cadena de salida
    char dato[100]; //auxiliar
    cadena1 = (char)malloc(sizeof(char));
    cadena2 = (char)malloc(sizeof(char));

    printf("\n\n\tIngresa la cadena:\t");
    scanf("%s", &dato);
    num = strlen(dato); //sacamos el número de caracteres de la cadena
    strcpy(cadena1, dato); //destino, origen //pasamos de auxiliar a cadena entrada
    strcpy(dato, ""); //borramos dato

    printf("\n\t->%d\n", num);

    for(int i = 0; i < num; i++){
        if(cadena1[i] != '+'  &&  cadena1[i] != '-'  &&  cadena1[i] != '*'  &&  cadena1[i] != '/'){
        	//si caracter[i] es diferente a un operando, pasamos a la cadena de salilda
            s++; //s lleva el conteo de cuántos caracteres van en la salida
            cadena2[s] = cadena1[i];
            //return true;
        }else{ //si ES un operando
            insertar(l, cadena1[i], s, cadenaSALIDA);
        }
    }


}
