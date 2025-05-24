#include <stdio.h>
#include "puertos_y_bits.h"
#include "input_numeros.h"


int main(void){
    print_bits(A);
    printf("Ingrese el numero de LED que desee modificar,\n't' para cambiar de estado los LEDs al estado opuesto,\n'c' para apagar todos,\n's' para encender todos,\n y 'q' para salir.\n");
    char c = getchar(), anterior = ' ';
    int n = -1;
    
    while(c != 'q'){                          //Al presionar 'q' se sale del programa
        if(c == '\n'){
            if(esNumero(anterior)){
                n = ingresarNumero(anterior);
                bitset(A, n);                  //Encendemos el bit "n" del puerto A que ingresó el usuario, en caso de que haya ingresado un numero valido: del 0 al 7
            }else{
                switch(anterior){
                    case 't':
                        masktoggle(A, 0xFF);   //Con 't' cambiamos el estado de todos los bits del puerto A: si eran 0s pasan a ser 1s y viceversa
                        break;
                    case 'c':
                        maskoff(A, 0xFF);      //Con 'c' se "apagan" todos los bits: pasan a ser todos 0
                        break;
                    case 's':
                        maskon(A, 0xFF);       //Con 's' se "encienden" todos los bits: pasan a ser todos 1
                        break;
                    default:
                        printf("Por favor ingrese una opcion valida\n");     //en caso de ingresar alguna opcion que no sea valida, se imprime el estado anterior de los bits y se le pide nuevamente al usuario que ingrese otra opcion
                        break;
                }
            }
            print_bits(A);
        }
        anterior = c;
        c = getchar();
    }
    return 0;
}


