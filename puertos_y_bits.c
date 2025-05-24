#include <stdio.h>
#include <stdint.h>
#include "puertos_y_bits.h"

static puertoD puertoLeds = {.puertoD = 0};           //ambos puertos, A y B, se inicializan con 0s.

static uint8_t* puertos_ptr[] = {(uint8_t*)&puertoLeds.PuertosAB_t.a, (uint8_t*)&puertoLeds.PuertosAB_t.b};

void bitset(int puerto, int bit){
    if(puerto != D){
        *puertos_ptr[puerto] |= (1 << (bit));
    }else{
        puertoLeds.puertoD |= (1 << (bit));
    }
}

void bitclear(int puerto, int bit){
    if(puerto != D){
        *puertos_ptr[puerto] &= ~(1 << (bit));
    }else{
        puertoLeds.puertoD |= (1 << (bit));
    }
}

int bitget(int puerto, int bit){
    if(puerto != D){
        return (*puertos_ptr[puerto] >> (bit) & 0x1);
    }else{
        return (puertoLeds.puertoD >> ((bit) & 0x1));
    }
    
}

void masktoggle(int puerto, int msk){
    if(puerto != D){
        *puertos_ptr[puerto] ^= msk;
    }else{
        puertoLeds.puertoD ^= msk;
    }
}

void maskoff(int puerto, int msk){
    if(puerto != D){
        *puertos_ptr[puerto] &= ~msk;
    }else{
        puertoLeds.puertoD &= ~msk;
    }
}

void maskon(int puerto, int msk){
    if(puerto != D){
        *puertos_ptr[puerto] |= msk;
    }else{
        puertoLeds.puertoD |= msk;
    }
}

void print_bits(int puerto){
    for (int i = 7; i >= 0; i--) {       //Imprimimos los 8 bits del puerto A: del 0 al 7
        printf("%d", bitget(puerto, i));  
    }
    printf("\n");
}

