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

fur_elise_display: fur_elise_display.c fur_elise_display.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../circleLib/abCircle.h ../../lcdLib/lcddraw.h find_frequency_display.h ../../timerLib/libTimer.h ../game_utils/buzzer.h display_utils.h move_layer.h catch_red_ml.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../circleLib -I../../timerLib -I../ -I../game_utils -I../../lcdLib -I../ fur_elise_display.c

find_frequency_display: find_frequency_display.c find_frequency_display.h move_layer.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../circleLib/abCircle.h ../../lcdLib/lcddraw.h ../custom_shape/hourglass.h ../game_utils/buzzer.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../circleLib -I../game_utils -I../ -I../../lcdLib -I../custom_shape find_frequency_display.c

catch_red_display: catch_red_display.c catch_red_display.h catch_red_ml.h move_layer.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../circleLib/abCircle.h ../../lcdLib/lcddraw.h 
	${CC} ${CFLAGS} -c -I../game_utils -I../../shapeLib -I../../lcdLib -I../../circleLib -I../ -I../../lcdLib catch_red_display.c

display_utils: display_utils.h display_utils.c ../../lcdLib/lcdutils.h ../../lcdLib/lcddraw.h
	${CC} ${CFLAGS} -c -I../../lcdLib display_utils.c


simon_display: simon_display.c simon_display.h move_layer.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../../lcdLib/lcddraw.h find_frequency_display.h ../../timerLib/libTimer.h display_utils.h move_layer_struct.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../timerLib -I../ -I../ simon_display.c


move_layer.o: move_layer.c move_layer.h ../../lcdLib/lcddraw.h ../../lcdLib/lcdutils.h ../../shapeLib/shape.h ../../timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../../shapeLib -I../../lcdLib -I../../timerLib  move_layer.c
