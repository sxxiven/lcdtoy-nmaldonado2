// Nichole Maldonado
// This file contains the main function
// that has 250 interrupts/sec and calls the
// corresponding game display function based on the
// game_num.

#include <msp430.h>
#include "state_machine_interrupt_handlers.h"
#include "buttons.h"
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"
#include "move_layer.h"
#include "wdt_interrupt_handler.h"
#include "fur_elise_display.h"
#include "find_frequency_display.h"
#include "catch_red_display.h"
#include "led.h"

/*
 * Advances the current game display.
 * Sets for a new display to be drawn
 * if the game number changes.
 * Input: None.
 * Output: None.
 */
void display_game() {
  if(game_changed){
    redraw_screen = 1;
    return;
  }

  u_char btn_pressed = buttons_read();
  
  // All game displays except for game one
  // have displays that constantly move.
  if ((btn_pressed & 240) || game_num != 1){
    switch(game_num) {
    case 1:
      fur_elise_display(btn_pressed);
      break;
    case 2:
      ml_advance(&ml_hg_1, &field_fence);
      break;
    case 3:
      catch_red_display(btn_pressed);
      break;
    }
    redraw_screen = 1;
  }
}


/*
 * Watchdog handler that advances the
 * game display every 15 counts.
 * Input: None.
 * Output: None.
 */
void wdt_c_handler()
{
  static short count = 0;
  count ++;
  if (count == 15) {
    display_game();
    count = 0;
  }
  // Dim led for game 2.
  if (game_num == 2) {
    turn_on_red();
    turn_off_red();
  }
}
