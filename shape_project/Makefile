# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h -I../lcdLib
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

#all:shapemotion.elf

#additional rules for files
lcd_toy.elf: ${COMMON_OBJECTS} lcd_toy.o wdt_handler.o game_start_display.o lives_tracker.o game_end_display.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lShape -lCircle -lp2sw -I../p2swLib -I../shape-motion-demo

wdt_handler.o: ../shape-motion-demo/wdt_handler.s
	${CC} ${CFLAGS} -c -I../shape-motion-demo ../shape-motion-demo/wdt_handler.s

load: lcd_toy.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

lcd_toy.o: lcd_toy.c game_start_display.h

game_start_display.o: game_start_display.c game_start_display.h

game_end_display.o: game_end_display.c game_end_display.h lives_tracker.h game_start_display.h

lives_tracker.o: lives_tracker.c lives_tracker.h
