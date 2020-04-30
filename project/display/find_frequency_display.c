// Nichole Maldonado
// Displays the custom shape hourglass
// that can move and change colors.
// Also displays the 11x16 and 8x12 font.

#include <msp430.h>
#include <lcdutils.h>
#include "lcddraw.h"
#include "shape.h"
#include "move_layer.h"
#include "find_frequency_display.h"
#include "hourglass.h"
#include "buzzer.h"

ab_hourglass hourglass = {ab_hourglass_get_bounds, ab_hourglass_check, {12, 17}, 3};

// Hourglass layers.
Layer layer_hourglass_2 = {
  (AbShape *)&hourglass,
  {(screenWidth/2) -30, (screenHeight/2)-30},
  {0,0}, {0,0},				  
  COLOR_WHITE,
  &field_layer
};

Layer layer_hourglass_1 = {
  (AbShape *)&hourglass,
  {(screenWidth/2)+30, (screenHeight/2)+30},
  {0,0}, {0,0},				  
  COLOR_WHITE,
  &layer_hourglass_2
};

MovLayer ml_hg_2 = {&layer_hourglass_2, {0,1}, 0};
MovLayer ml_hg_1 = {&layer_hourglass_1, {0,1}, &ml_hg_2};

/*
 * Function that displays the start of the 
 * display.
 * Input: None.
 * Output: None.
 */
void display_new_find_frequency(){
  bgColor = COLOR_YELLOW;
  layerInit(&layer_hourglass_1);
  layerDraw(&layer_hourglass_1);
  drawString11x16(60,20,"Time", COLOR_BLACK, COLOR_YELLOW);
  drawString8x12(20,100, "is of",COLOR_BLACK, COLOR_YELLOW);
  drawString8x12(20,120, "the",COLOR_BLACK, COLOR_YELLOW);
  drawString8x12(20,140, "essence", COLOR_BLACK, COLOR_YELLOW);
}

/*
 * Function that alternates the hourglass
 * colors between white and black.
 * Input: None.
 * Output: None.
 */
void change_color() {
  static u_char color_pattern = 1;
  layer_hourglass_1.color = layer_hourglass_2.color = (color_pattern) ? COLOR_BLACK : COLOR_WHITE;

  color_pattern = (color_pattern) ? 0 : 1;
  (color_pattern) ? buzzer_set_period(NOTE_A) : buzzer_set_period(NOTE_B);
}

/*
 * Function that alternates the hourglasses
 * between moving and not moving.
 * Input: None.
 * Output: None.
 */
void change_motion() {
  static u_char motion = 0; 
  ml_hg_1.velocity.axes[1] = motion;
  ml_hg_2.velocity.axes[1] = motion;
  motion = (motion) ? 0 : 1;
  (motion) ? buzzer_set_period(NOTE_C) : buzzer_set_period(NOTE_D);
}
