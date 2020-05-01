// Nichole Maldonado
// This file holds the main function of the
// program that sets the clocks and game utils.
// The WDTInterrupts are then enabled.
// It also includes methods to display the new
// game or advance the current game.

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

static void display_end();
static void display_new_game();
static void advance_draw();
/*
 * Function that displays the end screen.
 * Input: None.
 * Output: None.
 */
static void display_end() {
  fillRectangle(0,0,screenWidth, screenHeight, COLOR_YELLOW);
  drawString11x16(40,65,"FIN", COLOR_BLACK, COLOR_YELLOW);
  drawString5x7(1,140, "press btn3 to restart", COLOR_BLACK, COLOR_YELLOW);
}

/*
 * Displays new game based on the game num.
 * Input: None
 * Output: None
 */
static void display_new_game() {
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
    display_end();
  }

  // New game has been loaded.
  game_changed = 0;
}

/*
 * Advances the current game's display
 * Input: None.
 * Output: None.
 */
static void advance_draw() {
  switch(game_num) {
  case 1:
    mov_layer_draw(&ml_key_1, &key_1);
    break;
  case 2:
    mov_layer_draw(&ml_hg_1, &layer_hourglass_1);
    break;
  case 3:
    mov_layer_draw(&ml_ball_1, &layer_ball_1);
    break;
  }
}

/*
 * Main function that sets clocks, game
 * utils, and enables periodic interrupts
 * Also controls whether to display a new game
 * or advance the current game display.
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
    while (!redraw_screen && !game_changed) {  
  or_sr(0x10);	   
    }
    redraw_screen = 0;

    // Advance current display if
    // game did not change.
    if (game_changed == 0) {
      advance_draw();
    }

    // Otherwise advance to new game display
    else {
      display_new_game();
    }
  }
}
