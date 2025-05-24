#ifndef PUERTOS_Y_BITS_H
#define PUERTOS_Y_BITS_H

#include <stdint.h>             //librería que define tipos enteros con anchuras específicas, para poder trabajar más cómodamente con los bits

#define LED_0 0x01
#define LED_1 0x02
#define LED_2 0x04
#define LED_3 0x08                                  //Mascaras para el LED que corresponde a cada bit
#define LED_4 0x10                                  //por ejemplo: bit 4 = 0x10 = 0001 0000
#define LED_5 0x20
#define LED_6 0x40
#define LED_7 0x80

#define A     0
#define B     1
#define D     2

typedef struct puertoDT{                            //Manejamos de esta manera los bits de los puertos, para poder acceder a cada bit por separado.
    uint16_t puertoA : 8;           //Mitad del puerto D son del AccA
    uint16_t puertoB : 8;           //La otra mitad son del AccB
}puertoD_t;


void bitset(int puerto, int bit);
void bitclear(int puerto, int bit);
int bitget(int puerto, int bit);
void masktoggle(int puerto, int msk);
void maskoff(int puerto, int msk);
void maskon(int puerto, int msk);



void print_bits(int puerto);                      //Función que sirve para imprimir el estado de todos los bits con los que está trabajando el usuario en el momento

#endif

