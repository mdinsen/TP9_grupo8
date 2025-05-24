#include <stdio.h>
#include <stdint.h>
#include "puertos_y_bits.h"

static puertos_t puertoLeds = {.puertoD = 0};           //ambos puertos, A y B, se inicializan con 0s.

static uint8_t* puertos_ptr[] = {(uint8_t*)&puertoLeds.PuertosAB_t.a, (uint8_t*)&puertoLeds.PuertosAB_t.b}; //tenemos un arreglo con punteros a cada puerto(A y B), donde A es el índice 0 y B el índice 1

void bitset(int puerto, int bit){                       //se enciende (se pone en 1) el bit que ingresa el usuario del puerto deseado
    if(puerto != D){
        *puertos_ptr[puerto] |= (1 << (bit));           //en caso de que necesitemos modificar A o B, accedemos a los puertos mediante los punteros a los campos de la union, se repite esta misma lógica en cada función. 
    }else{
        puertoLeds.puertoD |= (1 << (bit));             //en caso de que se quiera modificar el puerto D que abarca ambos puertos, se modifica toda la union, se repite esta misma lógica en cada función.
    }
}

void bitclear(int puerto, int bit){                     //se apaga (se pone en 0) el bit que ingresa el usuario del puerto deseado
    if(puerto != D){
        *puertos_ptr[puerto] &= ~(1 << (bit));
    }else{
        puertoLeds.puertoD |= (1 << (bit));
    }
}

int bitget(int puerto, int bit){                        //se obtiene el estado actual de un bit del puerto deseado
    if(puerto != D){
        return (*puertos_ptr[puerto] >> (bit) & 0x1);
    }else{
        return (puertoLeds.puertoD >> ((bit) & 0x1));
    }
    
}

void masktoggle(int puerto, int msk){                   //cambian los bits al estado opuesto (0 a 1 y viceversa) del puerto deseado en los lugares en los que la mascara msk tiene 1s
    if(puerto != D){
        *puertos_ptr[puerto] ^= msk;
    }else{
        puertoLeds.puertoD ^= msk;
    }
}

void maskoff(int puerto, int msk){                      //se apagan los bits (se ponen en 0) del puerto deseado en los lugares en los que la mascara msk tiene 1s
    if(puerto != D){
        *puertos_ptr[puerto] &= ~msk;
    }else{
        puertoLeds.puertoD &= ~msk;
    }
}

void maskon(int puerto, int msk){                       //se encienden los bits (se ponen en 1) del puerto deseado en los lugares en los que la mascara msk tiene 1s
    if(puerto != D){
        *puertos_ptr[puerto] |= msk;
    }else{
        puertoLeds.puertoD |= msk;
    }
}



