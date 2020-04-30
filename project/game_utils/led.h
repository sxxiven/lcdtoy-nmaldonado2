// Nichole Maldonado and Previous Commits
// This file is the header file for led.c
// that contains functions to initialize the
// leds and turn the red light on
// or off.
// NOTE: My green led is missing its pin,
//       so setting the green LED on messes
//       with the screen display. However,
//       later versions could incorporate a
//       green led, if the proper connections
//       are available so the green led is left
//       out of this lab :(

#ifndef led_included
#define led_included

#define LED_RED BIT6               // P1.6
#define LEDS BIT6

extern unsigned char red_on;

// Initialize the red and green lights.
void led_init();

// Turn the lights on, based on the flags
// red_on and green_on.
void led_change();

// Turns on the red light.
void turn_on_red();

// Turns off the red light.
void turn_off_red();

#endif // included
