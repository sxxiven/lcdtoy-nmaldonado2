# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

#all:shapemotion.elf

#additional rules for files
shapemotion.elf: ${COMMON_OBJECTS} shapemotion.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lShape -lCircle -lp2sw

load: shapemotion.elf
	msp430loader.sh $^

loadTrial: shape_motion_trial.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

shape_motion_trial.elf: ${COMMON_OBJECTS} shape_motion_trial.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lShape -lCircle -lp2sw
