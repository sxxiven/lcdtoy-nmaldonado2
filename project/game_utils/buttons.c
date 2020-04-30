// Nichole Maldonado and Previous commits
// This file includes functions to set
// the buttons by using the pull up_resitors.
// If a button is pressed, the IES is set to
// sense an up transition, and vice versa.
// Also tracks which buttons have changed
// and the current state of the buttons

#include <msp430.h>
#include "buttons.h"

static unsigned char buttons_last_reported;
static unsigned char buttons_current;


/*
 * This function sets the IES to sense a
 * transition from high to low, if the previous
 * transition was from low to high, and vice
 * versa.
 * Input: None
 * Output: None
 */
void buttons_update_interrupt_sense()
{
  buttons_current = P2IN & BUTTONS;
  
  // Button is up if bit == 1
  // So if button is up, set P2IES to 1, to
  // prepare for a high to low transition.
  // (when button is pressed).
  P2IES |= (P2IN & BUTTONS);

  // Button is down if bit == 0
  // So if button is down, set P2IES to 0, to
  // prepare for a low to high transition.
  // (when button is released).
  P2IES &= (P2IN | ~BUTTONS); 
}

void buttons_init()
{
  P2OUT |= BUTTONS;
  
  // Enable resistors for buttons
  P2REN |= BUTTONS;

  // Enable interrupts from buttons.
  P2IE = BUTTONS;

  // Close P1DIR transmission gate for buttons.
  P2DIR &= ~BUTTONS;
  
  buttons_update_interrupt_sense();
}

/*
 * Returns the buttons changed in the
 * high bit and the current state of the
 * buttons in the low bit. Modified from
 * Dr.Freudenthal's p2_sw_read.
 * Input: None.
 * Output: The high bit denoting whether the
 *         bits have changed and the low bit
 *         representing the current state
 *         of the buttons.
 */
unsigned char buttons_read() {
  unsigned char btns_changed = buttons_current ^ buttons_last_reported;
  buttons_last_reported = buttons_current;
  return buttons_current | (btns_changed << 4);
}
