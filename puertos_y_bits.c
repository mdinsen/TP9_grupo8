#include <stdio.h>
#include <stdint.h>
#include "puertos_y_bits.h"

static puertoD_t puertoLeds = {0,0};           //ambos puertos, A y B, se inicializan con 0s.

static uint8_t* puertos_ptr[3] = {(uint8_t*)&puertoLeds, (uint8_t*)&puertoLeds+1, (uint8_t*)&puertoLeds
};
void bitset(int puerto, int bit){
    *puertos_ptr[puerto] |= (1 << (bit));
}

void bitclear(int puerto, int bit){
    *puertos_ptr[puerto] &= ~(1 << (bit));
}

int bitget(int puerto, int bit){
    return (*puertos_ptr[puerto] >> (bit) & 0x1);
}

void masktoggle(int puerto, int msk){
    *puertos_ptr[puerto] ^= msk;
}

void maskoff(int puerto, int msk){
    *puertos_ptr[puerto] &= ~msk;
}

void maskon(int puerto, int msk){
    *puertos_ptr[puerto] |= msk;
}

void print_bits(int puerto){
    for (int i = 7; i >= 0; i--) {       //Imprimimos los 8 bits del puerto A: del 0 al 7
        printf("%d", bitget(puerto, i));  
    }
    printf("\n");
}

