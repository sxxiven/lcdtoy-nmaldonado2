// Nichole Maldonado
// This file contains the interrupt handlers called
// that advance the state if the designated button
// is pressed or performs a game/ state specific
// functionality otherwise.

#include <msp430.h>
#include "led.h"
#include "buttons.h"
//#include "simon.h"
#include "buzzer.h"
#include "shape.h"
#include "catch_red_display.h"
//#include "fur_elise_display.h"
#include "catch_red_ml.h"

char game_num = 1;
char game_changed = 0;
/*
 * Interrupt handler for Simon that moves to 
 * the next state if BTN3 is pressed or
 * identifies if the user is currently entering
 * the correct pattern. If not, the game is
 * restarted.
 * Input: None
 * Output: None
 */
/*
void game_four_interrupt_handler()
{

if ((P2IN & BUTTONS) == (~BTN2 & BUTTONS)) {
    green_on = 0;
    game_num = 4;
    game_changed = 1;
  }
 else {
turn_on_red();
}
}
*/
 // Handler for catch red which
 // makes the lights toggle faster
 // if the red light and BTN4 are pressed
 // simultaneously.
 
void game_three_interrupt_handler()
{

  // If BTN2 pressed, go to next state.
  if ((P2IN & BUTTONS) == (~BTN2 & BUTTONS)) {
    green_on = 0;
    game_num = 1;
    game_changed = 1;
  }
  
  if ((P2IN & BUTTONS) == (~BTN4 & BUTTONS)) {
    change_ball_color();
buzzer_set_period(NOTE_C);
turn_on_red();
  }
  else {
turn_off_red();
buzzer_set_period(0);
}
}

/*
 * Interrupt handler for Fur Elise
 * that transitions to the next state
 * if the first button is pressed.
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
  if (P2IN & BTN4) {
    key_1.color = COLOR_WHITE;
  }
  else {
    buzzer_set_period(NOTE_E);
    key_1.color = COLOR_BLUE;
  }
  if (P2IN & BTN3) {
    key_2.color = COLOR_WHITE;
  }
  else {
    buzzer_set_period(NOTE_E_FLAT);
    key_2.color = COLOR_RED;
  }
  if (P2IN & BTN2) {
    key_3.color = COLOR_WHITE;
  }
  else {
    buzzer_set_period(NOTE_B);
    key_3.color = COLOR_YELLOW;
  }
if ((P2IN & BUTTONS) == 15) {
    buzzer_set_period(0);
turn_off_red();
}
 else {
turn_on_red();
}
}

// DEPRECATED. The following code can be
// found in the assembly file
// games_two_three_interrupt_handlers.s

// Handler for game 2 which determines if
// user selected the correct button that
// maps to the random frequency.
/*
void game_two_interrupt_handler()
{
  switch (P2IN & BUTTONS) {
  case (~BTN4 & BUTTONS):
    game_num = 3;
    break;
  

  // If no buttons are pressed, turn off all leds.
  case BUTTONS:
    turn_off_green_red();
    break;
  default:

    // NOTE: If, else used since frequency_btn
    // is not a constant value and cannot be a case.
    // If the frequency_btn matches the button
    // pressed turn on green and set frequency_btn
    // to -1.

    if ((P2IN & BUTTONS) == frequency_btn) {
      turn_on_green();
      frequency_btn = -1;
    }

    // Otherwise, turn on red.
    else {
      turn_on_red.
    }
  }    
}
*/

 // DEPRECATED: The following code is implemented
 // in the assembly file
 // games_two_three_interrupt_handlers.s

 // Handler for catch red which
 // makes the lights toggle faster
 // if the red light and BTN4 are pressed
 // simultaneously.
 /*
void game_three_interrupt_handler()
{

  // If BTN2 pressed, go to next state.
  if ((P2IN & BUTTONS) == (~BTN2 & BUTTONS)) {
    game_num = 4;
  }
  
  if ((P2IN & BUTTONS) == (~BTN4 & BUTTONS)) {

    // If red is on, go faster.
    if (red_on) {
      light_speed -= 5;
    }

    // Reset light_speed if light_speed is too
    // fast or red is not on.
    if (!red_on || light_speed <= 15) {
      light_speed = 150;
    }
  }
}

*/
