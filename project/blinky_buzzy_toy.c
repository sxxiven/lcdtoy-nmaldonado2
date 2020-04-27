// Nichole Maldonado
// This file holds the main function of the
// program that sets the clocks and game utils.
// The WDTInterrupts are then enabled.

#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "buttons.h"
#include "lcdutils.h"
#include "shape.h"
#include "move_layer.h"
#include "state_machine_interrupt_handlers.h"
#include "fur_elise_display.h"
#include "find_frequency_display.h"
#include "catch_red_ml.h"
#include "catch_red_display.h"
//#include "simon_display.h"
void display_new_game() {
  switch(game_num) {
    case 1:
      display_new_piano();
      break;
    case 2:
      
      display_new_find_frequency();
      break;
    case 3:
      display_new_catch_red();
      break;
    default:
      //    display_new_simon();
      break;
    }
 game_changed = 0;
}

void advance_draw() {
  switch(game_num) {
  case 1:
    movLayerDraw(&ml_key_1, &key_1);
    break;
  case 2:
    movLayerDraw(&ml_mini_hg_1, &layer_mini_hourglass_1);
    break;
  case 3:
    movLayerDraw(&ml_ball_1, &layer_ball_1);
    break;
  default:
    //movLayerDraw(&ml_red_arrow, &layer_red_arrow);
    break;
  }
}

/*
 * Main function that sets clocks, game
 * utils, and enables periodic interrupts
 * Input: None
 * Output: None
 */
int main(void) {

  // Sets the master oscillator, CPU, and clocks.
  configureClocks();

  led_init();

  lcd_init();
  
  buzzer_init();
  buttons_init();

  display_new_piano();
  enableWDTInterrupts();

   for(;;) {
    while (!redrawScreen && !game_changed) {  
  or_sr(0x10);	      // CPU OFF
    }
    redrawScreen = 0;
    if (game_changed == 0) {
      advance_draw();
    }
    else {
      display_new_game();
    }
  }
}
