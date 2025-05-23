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

typedef struct puertoDT{                            //Manejamos de esta manera los bits de los puertos, para poder acceder a cada bit por separado.
    uint16_t puertoA : 8;           //Mitad del puerto D son del AccA
    uint16_t puertoB : 8;           //La otra mitad son del AccB
}puertoD_t;

extern puertoD_t puertoLeds;                        //Necesitamos traer puertoLeds al .h para poder utilizar las macros de BITSET_A, BITCLEAR_A, BITGET_A, etc.

#define BITSET(BF, N) (BF |= (0x1 << (N)))          //"Encendemos" el bit deseado, su valor pasa a ser 1
#define BITCLEAR(BF, N) (BF &= ~(0x1 << N))         //"Apagamos" el bit indicado, su valor pasa a ser 0
#define BITGET(BF, N) ((BF >> N) & 0x1)             //Nos dice el estado del bit que le indiquemos
#define BITTOGGLE(BF, N) ((BF) ^= (0x1 << (N)))     //Pasa el bit al estado contrario
#define MASKON(BF, MSK) (BF |= MSK)                 //Pone en 1 los bits en los que hay 1s en la máscara
#define MASKOFF(BF, MSK) (BF &= ~MSK)               //Pone en 0 los bits en los que hay 1s en la máscara
#define MASKTOGGLE(BF, MSK) (BF ^= MSK)             //Cambia el bit al estado contrario en los bits en los que hay 1s en la máscara

#define BITSET_A(N)     (puertoLeds.puertoA |= (1 << (N)))  //se enciende (se pone en 1) en bit N del puerto A que controla los leds
#define BITCLEAR_A(N)   (puertoLeds.puertoA &= ~(1 << (N))) //se apaga (se pone en 0) en bit N del puerto A que controla los leds
#define BITGET_A(N)     ((puertoLeds.puertoA >> (N)) & 0x1) //obtenemos el estado del bit N del puerto A que es el del puerto de leds
#define MASKTOGGLE_A(MSK) (puertoLeds.puertoA ^= MSK)       //misma funcion que MASKTOGGLE, pero para el puerto A
#define MASKOFF_A(MSK)  (puertoLeds.puertoA &= ~MSK)        //misma funcion que MASKOFF pero solo para el puerto A
#define MASKON_A(MSK)   (puertoLeds.puertoA |= MSK)         //misma funcion que MASKON pero para el puerto A


void print_bits();                      //Función que sirve para imprimir el estado de todos los bits con los que está trabajando el usuario en el momento

#endif

