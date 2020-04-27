# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all:
	(cd ../timerLib && make install)
	(cd game_utils && make)
	(cd states_and_interrupts && make)
	(cd display && make)
	(cd custom_shape && make)
	(cd ../shapeLib && make libShape.a)
	(cd ../circleLib && make libCircle.a)
	(cd ../lcdLib && make libLcd.a)

#additional rules for files
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} states_and_interrupts/state_machine_interrupt_handlers.o game_utils/led.o game_utils/buzzer.o states_and_interrupts/p2_interrupt_handler.o states_and_interrupts/wdt_interrupt_handler.o display/move_layer.o ../lib/libTimer.a states_and_interrupts/games_two_three_interrupt_handlers.o states_and_interrupts/wdt_handler.o ../lcdLib/lcdutils.o display/fur_elise_display.o display/find_frequency_display.o display/catch_red_display.o blinky_buzzy_toy.o ../shapeLib/libShape.a ../circleLib/libCircle.a custom_shape/hourglass.o display/display_utils.o ../lcdLib/libLcd.a game_utils/buttons.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	(cd ../timerLib && make clean)
	(cd game_utils && make clean)
	(cd states_and_interrupts && make clean)
	(cd display && make clean)
	(cd custom_shape && make clean)
	rm -f *.o *.elf
	rm -rf ../lib ../h

blinky_buzzy_toy.o: ../timerLib/libTimer.h game_utils/led.h game_utils/buzzer.h game_utils/buttons.h display/move_layer.h ../lcdLib/lcdutils.h ../shapeLib/shape.h display/fur_elise_display.h blinky_buzzy_toy.c display/find_frequency_display.h display/catch_red_display.h display/catch_red_ml.h states_and_interrupts/state_machine_interrupt_handlers.h display/simon_display.h
	${CC} ${CFLAGS} -c -I../timerLib -Igame_utils -I../lcdLib -I../shapeLib -Idisplay -Istates_and_interrupts blinky_buzzy_toy.c
