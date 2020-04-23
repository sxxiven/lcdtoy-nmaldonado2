// Nichole Maldonado
// This file contains the main function
// that has 250 interrupts/sec and calls the
// corresponding game function based on the
// game_num.

#include <msp430.h>
#include "state_machine_interrupt_handlers.h"
#include "simon.h"
#include "catch_red.h"
#include "find_frequency.h"
#include "fur_elise.h"

#include "buttons.h"
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"
#include "move_layer.h"
#include "wdt_interrupt_handler.h"
#include "fur_elise_display.h"
#include "find_frequency_display.h"

/** Watchdog timer interrupt handler. 15 interrupts/sec */

void wdt_c_handler()
{
  P1DIR |= BIT6;
  static short count = 0;
  //P1OUT |= GREEN_LED;		      /**< Green LED on when cpu on */
  count ++;
  if (count == 15) {
    mlAdvance(&ml0_2,  &fieldFence);
    char btn_pressed = buttons_read();
    if (btn_pressed){
      switch(game_num) {
      case 1:
	fur_elise_display(btn_pressed);
	break;
      case 2:
	find_frequency_display(btn_pressed);
	break;
      case 3:
	//
	break;
      default:
	//
	break;
      }
      redrawScreen = 1;
    }
    count = 0;
  }

  // Plays game based on game_num/state.
  switch(game_num) {
  case 1:
    
    fur_elise_sound();
    break;
  case 2:
    find_frequency();
    break;
  case 3:
    catch_red();
    break;
  default:
    simon();
    break;
  }
    
  // P1OUT &= ~GREEN_LED;		    /**< Green LED off when cpu off */
}

/*
void __interrupt_vec(WDT_VECTOR) WDT()
{
  // Plays game based on game_num/state.
  switch(game_num) {
  case 1:
    fur_elise_sound();
    break;
  case 2:
    find_frequency();
    break;
  case 3:
    catch_red();
    break;
  default:
    simon();
    break;
  }
}
*/

/*
 * Function that moves based on the clock
 * and has 250 interrupts/sec. Based on the
 * game_num, the corresponding state/game
 * is played.
 * Input: None.
 * Output: None.
 */
