CC := gcc
FLAGS := -g -Wall
OBJS := leds.o input_numeros.o puertos_y_bits.o
emulacion_puerto: ${OBJS}
	${CC} ${OBJS} -o emulacion_puerto
leds.o: leds.c puertos_y_bits.h input_numeros.h
	${CC} leds.c -c ${FLAGS}
input_numeros.o: input_numeros.c input_numeros.h
	${CC} input_numeros.c -c ${FLAGS}
puertos_y_bits.o: puertos_y_bits.c puertos_y_bits.h
	${CC} puertos_y_bits.c -c ${FLAGS}
clean:
	rm *.o