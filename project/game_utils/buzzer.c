// Nichole Maldonado and Previous Commits
// This file provides functions to initialize
// the four buttons, and set the sound by
// adjusting the cycles.

#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

/*
 * Function that initializes the buzzer to
 * be used throughout the program.
 * Input: None
 * Output: None
 */
void buzzer_init()
{
    
  // Direct timer A output "TA0.1" to P2.6.  
  // According to table 21 from data sheet:
  // P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
  // P2SEL.6 must be 1
  // Also: P2.6 direction must be output
  // Used to drive speaker.
  timerAUpmode();
  
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7; 
  P2SEL |= BIT6;

  // Enable output to speaker.
  P2DIR = BIT6;
}

/*
 * Function that sets the buzzer period where
 * the buzzer clock is at 2MHz (period of 1k
 * results in 2kHz tone).
 * Input: The number of cycles and the mute
 *        which represents the number of bits
 *        the cycle is shifted.
 * Output: None.
 */
void buzzer_set_period(short cycles) 
{

  CCR0 = cycles; 
  CCR1 = cycles >> 1;
}
