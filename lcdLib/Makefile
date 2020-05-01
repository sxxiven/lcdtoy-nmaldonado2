all: libLcd.a lcddemo.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h 
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib 
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h
diamond.o: diamond.c diamond.h lcddraw.h lcdutils.h
triangle.o: triangle.c triangle.h lcddraw.h lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf

lcddemo.elf: lcddemo.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

lcdx.elf: lcdx.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

load: lcddemo.elf
	msp430loader.sh $^

loadx: lcdx.elf
	msp430loader.sh $^

houseShape.elf: houseShape.o libLcd.a diamond.h triangle.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer


loadHouse: houseShape.elf
	msp430loader.sh $^

lcdRectangle.elf: lcdRectangle.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer


loadRectangle: lcdRectangle.elf
	msp430loader.sh $^


xshape.elf: xshape.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

loadX: xshape.elf
	msp430loader.sh $^

crossShape.elf: crossShape.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

loadCross: crossShape.elf
	msp430loader.sh $^

diamondShape.elf: diamondShape.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

loadDiamond: diamondShape.elf
	msp430loader.sh $^

squareShape.elf: squareShape.o libLcd.a 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

loadSquare: squareShape.elf
	msp430loader.sh $^

triangleShape.elf: shapeTriangle.o libLcd.a triangle.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

loadTriangle: triangleShape.elf
	msp430loader.sh $^

bracketShape.elf: bracketShape.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

loadBracket: bracketShape.elf
	msp430loader.sh $^

curveShape.elf: curveShape.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer 

loadCurve: curveShape.elf
	msp430loader.sh $^
