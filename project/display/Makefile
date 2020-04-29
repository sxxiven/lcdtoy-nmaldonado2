# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: fur_elise_display find_frequency_display display_utils catch_red_display move_layer.o

clean:
	rm -f *.o

fur_elise_display: fur_elise_display.c fur_elise_display.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../lcdLib/lcdutils.h find_frequency_display.h ../game_utils/buzzer.h display_utils.h move_layer.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../game_utils fur_elise_display.c

find_frequency_display: find_frequency_display.c find_frequency_display.h move_layer.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../lcdLib/lcdutils.h ../custom_shape/hourglass.h ../game_utils/buzzer.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../game_utils -I../custom_shape find_frequency_display.c

catch_red_display: catch_red_display.c catch_red_display.h move_layer.h ../../shapeLib/shape.h ../../circleLib/abCircle.h ../../lcdLib/lcdutils.h 
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../circleLib catch_red_display.c

display_utils: display_utils.h display_utils.c ../../lcdLib/lcdutils.h ../../lcdLib/lcddraw.h
	${CC} ${CFLAGS} -c -I../../lcdLib display_utils.c

move_layer.o: move_layer.c move_layer.h ../../lcdLib/lcddraw.h ../../lcdLib/lcdutils.h ../../shapeLib/shape.h ../../timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../timerLib  move_layer.c
