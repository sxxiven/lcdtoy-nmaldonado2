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
#include "catch_red_display.h"

void display_new_game() {
  switch(game_num) {
    case 1:
      display_new_piano();
      break;
    case 2:
      keys_to_change = 0;
      display_new_find_frequency();
      break;
    case 3:
      display_new_catch_red();
      break;
    default:
      //
      break;
    }
 game_changed = 0;
}

void advance_draw() {
  switch(game_num) {
  case 1:
    display_piano();
    break;
  case 2:
    movLayerDraw(&ml_mini_hg_1, &layer_mini_hourglass_1);
    break;
  case 3:
    movLayerDraw(&ml_ball_1, &layer_ball_1);
    break;
  default:
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

  // Sets led, buzzer, and buttons.
  led_init();

  lcd_init();
  
  buzzer_init();
  buttons_init();

  shapeInit();

  //layerInit(&layer0);
  //layerDraw(&layer0);

  display_new_piano();
  //layerGetBounds(&fieldLayer, &fieldFence);

  
  // Enables periodic intterupts.
  enableWDTInterrupts();

   for(;;) {
    while (!redrawScreen && !game_changed) { //< Pause CPU if screen doesn't need updating 
      //P1OUT &= ~GREEN_LED;    // Green led off witHo CPU 
  or_sr(0x10);	      // CPU OFF
    }
    // P1DIR |= BIT6;
    //P1OUT |= GREEN_LED;       // Green led on when CPU on 
    redrawScreen = 0;
    //movLayerDraw(&ml0_2, &layer1_2);
    //display_piano();
    if (game_changed == 0) {
      advance_draw();
    }
    else {
      //display_new_piano();
      display_new_game();
    }
  }
}
