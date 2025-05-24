#ifndef PUERTOS_Y_BITS_H
#define PUERTOS_Y_BITS_H

#include <stdint.h>             //librería que define tipos enteros con anchuras específicas, para poder trabajar más cómodamente con los bits


#define A     0                 //defino A como 0 para acceder al arreglo con el puntero al puertoA que corresponde a ese índice
#define B     1                 //defino B como 1 para acceder al arreglo con el puntero al puertoB que corresponde a ese índice
#define D     2                 

typedef union{                            //Manejamos de esta manera los bits de los puertos, para poder acceder a cada bit por separado.
    uint16_t puertoD;
    struct PuertosAB{ 
        uint8_t  a;
        uint8_t  b; 
    }PuertosAB_t;
}puertos_t;


void bitset(int puerto, int bit);
void bitclear(int puerto, int bit);
int bitget(int puerto, int bit);
void masktoggle(int puerto, int msk);
void maskoff(int puerto, int msk);
void maskon(int puerto, int msk);




#endif

