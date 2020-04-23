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
#include "shape_trial.h"

//#include <p2switches.h>



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

  layerInit(&layer0);
  layerDraw(&layer0);


  layerGetBounds(&fieldLayer, &fieldFence);

  
  // Enables periodic intterupts.
  enableWDTInterrupts();

   for(;;) {
    while (!redrawScreen) { /**< Pause CPU if screen doesn't need updating */
      //P1OUT &= ~GREEN_LED;    /**< Green led off witHo CPU */
      or_sr(0x10);	      /**< CPU OFF */
    }
   
    //P1OUT |= GREEN_LED;       /**< Green led on when CPU on */
    redrawScreen = 0;
    movLayerDraw(&ml0, &layer0);
   
  }
}


