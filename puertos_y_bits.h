#ifndef PUERTOS_Y_BITS_H
#define PUERTOS_Y_BITS_H

#include <stdint.h>             //librería que define tipos enteros con anchuras específicas, para poder trabajar más cómodamente con los bits


#define A     0
#define B     1
#define D     2

typedef union{                            //Manejamos de esta manera los bits de los puertos, para poder acceder a cada bit por separado.
    uint16_t puertoD;
    struct PuertosAB{ 
        uint8_t  a;
        uint8_t  b; 
    }PuertosAB_t;
}puertoD;


void bitset(int puerto, int bit);
void bitclear(int puerto, int bit);
int bitget(int puerto, int bit);
void masktoggle(int puerto, int msk);
void maskoff(int puerto, int msk);
void maskon(int puerto, int msk);



void print_bits(int puerto);                      //Función que sirve para imprimir el estado de todos los bits con los que está trabajando el usuario en el momento

#endif

