#include <stdio.h>
#include "input_numeros.h"

int esNumero(char caracter) {
    if (caracter >= '0' && caracter <= '7'){					//Si el caracter esta entre los valores de ASCII de '0' y '9', se 
        return 1;												//trata de un numero.
    }
    else{
        return 0;												//Caso contrario no es un numero, no queremos utilizar ese dato
        														//(habiendo descartado 'q' y 'Enter').
    }
}

	
int ingresarNumero(char caracterLeido) {							//Funcion que nos ayuda a traducir los datos que nos pasa el usuario
    int numeroLeido;
    numeroLeido = caracterLeido - '0';							
   
    return numeroLeido;
}