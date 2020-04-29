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
#include "lcddraw.h"
#include "shape.h"
#include "move_layer.h"
#include "state_machine_interrupt_handlers.h"
#include "fur_elise_display.h"
#include "find_frequency_display.h"
#include "catch_red_display.h"

void display_welcome() {
  fillRectangle(0,0,screenWidth, screenHeight, COLOR_YELLOW);
  //layerGetBounds(&fieldLayer_2, &fieldFence);
  drawString11x16(40,65,"FIN", COLOR_BLACK, COLOR_YELLOW);
  drawString5x7(1,140, "press btn3 to restart", COLOR_BLACK, COLOR_YELLOW);
}

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
  case 0:
    display_welcome();
    }
 game_changed = 0;
}

void advance_draw() {
  switch(game_num) {
  case 1:
    movLayerDraw(&ml_key_1, &key_1);
    break;
  case 2:
    movLayerDraw(&ml_hg_1, &layer_hourglass_1);
    break;
  case 3:
    movLayerDraw(&ml_ball_1, &layer_ball_1);
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
  //display_welcome();
  //game_num = 0;
  display_new_piano();
  //display_welcome();
  // game_num = 0;
  enableWDTInterrupts();
  //  game_num = 1;
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
