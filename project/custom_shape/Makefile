# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../../h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: hourglass

clean:
	rm -f *.o

hourglass: hourglass.c hourglass.h ../../shapeLib/shape.h
	${CC} ${CFLAGS} -c -I../../shapeLib hourglass.c
