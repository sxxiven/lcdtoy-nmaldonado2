// Nichole Maldonado
// This file contains the interrupt handlers called
// that advance the state if the designated button
// is pressed or performs a game/ state specific
// functionality otherwise.

#include <msp430.h>
#include "led.h"
#include "buttons.h"
#include "buzzer.h"
#include "shape.h"
#include "catch_red_display.h"

char game_num = 1;
char game_changed = 0;

/* Handler for catch red which
 * makes the switches the ball
 * colors if btn4 is pressed and
 * turns on the red led and buzzer.
 * Input: None.
 * Output: None.
 */
void game_three_interrupt_handler()
{
  switch((P2IN & BUTTONS)) {
  case (~BTN2 & BUTTONS):
    game_num = 0;
    game_changed = 1;
    break;
  case (~BTN4 & BUTTONS):
    change_ball_color();
    buzzer_set_period(NOTE_C);
    turn_on_red();
    break;
  default:
    turn_off_red();
    buzzer_set_period(0);
  }
}

/*
 * Interrupt handler for Fur Elise
 * that transitions to the next state
 * if the first button is pressed and
 * turns on the led if a button is pressed.
 * Input: None
 * Output: None
 */
void game_one_interrupt_handler()
{
  if ((P2IN & BIT0) == 0) {
    game_num = 2;
    game_changed = 1;
    turn_off_red();
    return;
  }

  // Turn off led if no buttons are pressed
  if ((P2IN & BUTTONS) == BUTTONS) {

    turn_off_red();
  }
  // Turn on led if buttons are pressed.
  else {
    turn_on_red();
  }
}

/*
 * Interrupt handler for the end screen
 * that turns on the led and transitions
 * to fur elise display if BTN2 is pressed.
 * Input: None
 * Output: None
 */
void end_interrupt_handler(){
  turn_on_red();
  if ((P2IN & BIT2) == 0) {
    game_num = 1;
    game_changed = 1;
    turn_off_red();
  }
}
