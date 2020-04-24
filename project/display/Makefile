# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: fur_elise_display find_frequency_display

clean:
	rm -f *.o

fur_elise_display: fur_elise_display.c fur_elise_display.h ../move_layer.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../circleLib/abCircle.h ../../lcdLib/lcddraw.h find_frequency_display.h ../../timerLib/libTimer.h ../game_utils/buzzer.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../circleLib -I../../timerLib -I../ -I../game_utils -I../../lcdLib fur_elise_display.c

find_frequency_display: find_frequency_display.c find_frequency_display.h ../move_layer.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../circleLib/abCircle.h ../../lcdLib/lcddraw.h ../custom_shape/hourglass.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../circleLib -I../ -I../../lcdLib -I../custom_shape find_frequency_display.c
