# Lab 3: Graphical-LCD-Toy

## Location
The main file for the program is found in blinky_buzzy_toy.c in the current
directory. The project is further subdivided into three directories:
1. display - source and header files for the three game displays that
represent three states (The end state is located in blinky_buzzy_toy.c).
2. game_utils - source and header files for the buzzer, buttons, and led.
3. states_and_interrupts - source and header files for the state transitions
and interrupt handlers. Also includes the .s file for the state transitions
and interrupt handling for games/states two and three.

## Button Mapping

In the instructions listed below, it is important to note that BTN1, BTN2,
BTN3, and BTN4 correspond to the S1, S2, S3, and S4 buttons on the msp430 accordingly.

## Instructions
To run the game, please follow the instructions lisited below:
1. In the current directory (project) type 'make'to build and install all the
libraries and compile object files. The timerLib will consequently be made.
2. In the current directory (project) type 'make load' to load and run the
program on the msp430.
3. The first state, representing the first game display, is three rectangles
representing keys that can change colors and sounds by pressing BTNS 2, 3,
and 4. To continue to the next state, press BTN1.
4. The second state, representing the second game display, demonstrates my own
implementation of an abstract shape, hourglass which can change colors and
stop/start. To
move to the next state, press BTN4.
5. The third state, representing the third game display, is the visual display
for catch red. The balls can change foreground and background colors. To move to the next state press BTN2.
6. The fourth state, representing the fourth display is an ending screen. Due
to a lack of memory, I could only display a simple screen, but was able to use
the 11 x 16 font. To go back to
state 1, press BTN3.

NOTE: type 'make clean' to remove all *.o, *.elf files, lib, and h.

## Project Description
Due to memory capacity, I could only create the new displays and not merge the
existing code from lab 2. Additionally, my msp430 was missing a cap, so the
green led was affecting the display, so all green led code was omitted.

### State 1 - Game Display for Fur Elise
The three keys represent piano keys. Press BTNS 2, 3, 4, to color a specific
key. When the button is released the key will return to its white color. Each
key is also mapped to a different note. Each key press also turns on the red led.

To exit, press BTN1.

### State 2 - Game Display for Find the Frequency
This display demonstrates my custom abstract shape, an hourglass. Two
hourglasses move accross the screen. If BTN3 is pressed, the shapes stop, if
BTN3 is pressed game, the shapes will continue to move. You can also toggle
the color of the hourglasses by pressing BTN1. The font sizes used on this
display are 8x12 and 11x16. The red led will be dimmed throughout the state.

To exit, press BTN4.

### State 3 - Game Display for Catch Red
This display has three moving balls. You can press BTN4 to change the ball
colors. A sound will play and the red led will turn on. You can also change
the background trail to black by pressing BTN1 and change it back to white by
pressing BTN3.

To exit, press BTN2.

### State 4 - End Game Display
Sadly, I was unable to create afourth moving display due to the lack of
memory. This is a simple restart screen that uses the 11x16 font and 5x7
font. The red led remains on as long as you are in this states.

To exit, press BTN3.
