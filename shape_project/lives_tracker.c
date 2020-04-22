#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>
#include "game_start_display.h"
#include "lives_tracker.h"

static u_char num_lives = 4;

void subtract_num_lives(){
  num_lives -= 1;
  if (num_lives == 0) {
    game_num = 2;
  }
}

void set_lives() {
  num_lives = 4;
}
