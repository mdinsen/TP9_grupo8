#include <stdio.h>
#include <stdint.h>
#include "puertos_y_bits.h"

puertoD_t puertoLeds = {0,0};           //ambos puertos, A y B, se inicializan con 0s.


void print_bits(void){
    for (int i = 7; i >= 0; i--) {       //Imprimimos los 8 bits del puerto A: del 0 al 7
        printf("%d", BITGET_A(i));  
    }
    printf("\n");
}

