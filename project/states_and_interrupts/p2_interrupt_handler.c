// Nichole Maldonado
// This file determines which functions to
// to call to handle the interrupt based
// on the game number.

#include <msp430.h>
#include "buttons.h"
#include "state_machine_interrupt_handlers.h"
#include "game_two_interrupt_handler.h"

/*
 * Function that calls the corresponding
 * interrupt handler based on the game_num.
 * Input: None.
 * Outpu: None.
 */
void __interrupt_vec(PORT2_VECTOR) Port_2()
{

  // Handle interrupt based on button.
  if (P2IFG & BUTTONS) {
    // Clear P2IFG for next interrupt interpretation.
    P2IFG &= ~BUTTONS;
    
    switch(game_num) {
    // End game interrupt handler.
    case 0:
      end_interrupt_handler();
      break;

    // Fur Elise interrupt handler.
    case 1:
      game_one_interrupt_handler();
      break;

    // Find frequency interrupt handler.
    case 2:
      game_two_interrupt_handler();
      break;

    // Catch red interrupt handler.
    case 3:
      game_three_interrupt_handler();
      break;
    }
    // Update IES.
    buttons_update_interrupt_sense();
  }
}

