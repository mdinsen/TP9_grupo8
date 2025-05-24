#include <stdio.h>
#include "puertos_y_bits.h"
#include "input_numeros.h"
void print_bits(int puerto);                      //Función auxiliar para este main que sirve para imprimir el estado de todos los bits con los que está trabajando el usuario en el momento


int main(void){
    print_bits(A);
    printf("Ingrese el numero de LED que desee modificar,\n't' para cambiar de estado los LEDs al estado opuesto,\n'c' para apagar todos,\n's' para encender todos,\n y 'q' para salir.\n");
    char c = getchar();
    int n = -1;
    


    while(c != 'q'){                          //Al presionar 'q' se sale del programa
        
        char siguiente = getchar();
        if (siguiente != '\n') {
            printf("Entrada no valida. Ingrese solo UN caracter.\n");
            while (siguiente != '\n' && siguiente != EOF){
                siguiente = getchar();
            }
        }

        if(esNumero(c)){
            n = ingresarNumero(c);
            bitset(A, n);                  //Encendemos el bit "n" del puerto A que ingresó el usuario, en caso de que haya ingresado un numero valido: del 0 al 7
        }else{
            switch(c){
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

        c = getchar();
    }
    return 0;
}

void print_bits(int puerto){
    for (int i = 7; i >= 0; i--) {       //Imprimimos los 8 bits del puerto A: del 0 al 7
        printf("%d", bitget(puerto, i));  
    }
    printf("\n");
}

