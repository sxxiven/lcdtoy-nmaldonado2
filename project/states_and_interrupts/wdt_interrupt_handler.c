// Nichole Maldonado
// This file contains the main function
// that has 250 interrupts/sec and calls the
// corresponding game function based on the
// game_num.

#include <msp430.h>
#include "state_machine_interrupt_handlers.h"
//#include "fur_elise.h"

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
//#include "simon_display.h"
#include "catch_red_ml.h"
#include "led.h"

void display_game() {
  if(game_changed){
    redrawScreen = 1;
    return;
  }

  u_char btn_pressed = buttons_read();
  if ((btn_pressed & 240) || game_num != 1){
    switch(game_num) {
    case 1:
      mlAdvance(&ml_key_1, &fieldFence);
      break;
    case 2:
      mlAdvance(&ml_mini_hg_1, &fieldFence);
      break;
    case 3:
      catch_red_display(btn_pressed);
      break;
    default:
//  simon_display(btn_pressed);
      break;
    }
    redrawScreen = 1;
  }
}


/** Watchdog timer interrupt handler. 15 interrupts/sec */

void wdt_c_handler()
{
//led_change();
  static short count = 0;
  //P1OUT |= GREEN_LED;		      /**< Green LED on when cpu on */
  count ++;
  if (count == 15) {
    display_game();
    count = 0;
  }

  // Plays game based on game_num/state.
/*
switch(game_num) {
  case 1:
    
    fur_elise_sound();
    break;
  case 2:
//   find_frequency();
    break;
  case 3:
//catch_red();
break;
  case 4:
// simon();
    break;
  }
*/    
  // P1OUT &= ~GREEN_LED;		    /**< Green LED off when cpu off */
}
