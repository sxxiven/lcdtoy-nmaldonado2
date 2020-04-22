# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all:
	(cd ../timerLib && make install)
	(cd game_utils && make)
	(cd games && make)
	(cd states_and_interrupts && make)
	(cd ../shapeLib && make libShape.a)
	(cd ../circleLib && make libCircle.a)

#additional rules for files
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} states_and_interrupts/state_machine_interrupt_handlers.o game_utils/led.o games/catch_red.o game_utils/buzzer.o game_utils/buttons.o states_and_interrupts/p2_interrupt_handler.o states_and_interrupts/wdt_interrupt_handler.o games/simon.o games/find_frequency.o games/fur_elise.o move_layer.o ../lib/libTimer.a states_and_interrupts/games_two_three_interrupt_handlers.o states_and_interrupts/wdt_handler.o ../lcdLib/lcdutils.o shape_trial.o blinky_buzzy_toy.o ../shapeLib/libShape.a ../circleLib/libCircle.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	(cd ../timerLib && make clean)
	(cd games && make clean)
	(cd game_utils && make clean)
	(cd states_and_interrupts && make clean)
	rm -f *.o *.elf
	rm -rf ../lib ../h

blinky_buzzy_toy.o: ../timerLib/libTimer.h game_utils/led.h game_utils/buzzer.h game_utils/buttons.h move_layer.h ../lcdLib/lcdutils.h ../shapeLib/shape.h shape_trial.h
	${CC} ${CFLAGS} -c -I../timerLib -Igame_utils -I../lcdLib -I../shapeLib blinky_buzzy_toy.c

move_layer.o: move_layer.c move_layer.h ../lcdLib/lcddraw.h ../lcdLib/lcdutils.h ../shapeLib/shape.h ../timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../shapeLib -I../lcdLib -I../timerLib move_layer.c


shape_trial.o: shape_trial.c shape_trial.h move_layer.h ../lcdLib/lcddraw.h ../shapeLib/shape.h ../circleLib/abCircle.h
	${CC} ${CFLAGS} -c -I../shapeLib -I../lcdLib -I../circleLib shape_trial.c
