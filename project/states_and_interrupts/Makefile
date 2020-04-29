# makfile configuration
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as -mcpu=msp430 --traditional-format -mP

all: wdt_interrupt_handler state_machine_interrupt_handlers p2_interrupt_handler games_two_three_interrupt_handlers wdt_handler

clean:
	rm -f *.o

wdt_interrupt_handler: wdt_interrupt_handler.c ../game_utils/led.h state_machine_interrupt_handlers.h ../../lcdLib/lcdutils.h ../../lcdLib/lcddraw.h ../../shapeLib/shape.h ../display/move_layer.h wdt_interrupt_handler.h ../../timerLib/libTimer.h ../game_utils/buttons.h ../display/fur_elise_display.h ../display/find_frequency_display.h ../display/catch_red_display.h ../game_utils/led.h
	${CC} ${CFLAGS} -c -I../game_utils -I../../lcdLib -I../../shapeLib -I../display -I../../timerLib wdt_interrupt_handler.c

state_machine_interrupt_handlers: ../game_utils/led.h state_machine_interrupt_handlers.h state_machine_interrupt_handlers.c ../game_utils/buttons.h ../../lcdLib/lcdutils.h ../display/catch_red_display.h ../../shapeLib/shape.h
	${CC} ${CFLAGS} -c -I../game_utils -I../../lcdLib -I../display -I../../shapeLib -I../ state_machine_interrupt_handlers.c

p2_interrupt_handler: p2_interrupt_handler.c ../game_utils/buttons.h state_machine_interrupt_handlers.h games_two_three_interrupt_handlers.h
	${CC} ${CFLAGS} -c -I../game_utils p2_interrupt_handler.c

games_two_three_interrupt_handlers: games_two_three_interrupt_handlers.h games_two_three_interrupt_handlers.s state_machine_interrupt_handlers.h ../game_utils/led.h ../display/find_frequency_display.h
	${AS} ${CFLAGS} -I../game_utils -I../display games_two_three_interrupt_handlers.s -o games_two_three_interrupt_handlers.o

wdt_handler: wdt_handler.s
	${AS} ${CFLAGS} wdt_handler.s -o wdt_handler.o
