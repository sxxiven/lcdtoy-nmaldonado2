// Nichole Maldonado
// Draws the catch red display with
// circles that can change color and
// background colors.

#include <msp430.h>
#include <lcdutils.h>
#include "shape.h"
#include <abCircle.h>
#include "move_layer.h"
#include "catch_red_display.h"

// Ball layers
Layer layer_ball_3 = {		
  (AbShape *)&circle16,
  {(screenWidth/2)+35, (screenHeight/2)- 45}, 
  {0,0}, {0,0},				    
  COLOR_GREEN,
  &field_layer
};

Layer layer_ball_2 = {		
  (AbShape *)&circle16,
  {22, (screenHeight/2)},
  {0,0}, {0,0},				    
  COLOR_RED,
  &layer_ball_3
};

Layer layer_ball_1 = {		
  (AbShape *)&circle16,
  {(screenWidth/2)+35, (screenHeight/2)+45}, 
  {0,0}, {0,0},				    
  COLOR_GREEN,
  &layer_ball_2
};

MovLayer ml_ball_3 = {&layer_ball_3, {-2,0}, 0};
MovLayer ml_ball_2 = {&layer_ball_2, {2,0}, &ml_ball_3};
MovLayer ml_ball_1 = {&layer_ball_1, {-2,0}, &ml_ball_2};

/*
 * Draws the new display for the game.
 * Input: None.
 * Output: None.
 */
void display_new_catch_red(){
  bg_color = COLOR_WHITE;
  layerInit(&layer_ball_1);
  layerDraw(&layer_ball_1);
}

/*
 * Alternates the ball colors 
 * between red and green.
 * Input: None.
 * Output: None.
 */
void change_ball_color() {
  static u_char color_pattern = 1;
  layer_ball_2.color = (color_pattern) ? COLOR_GREEN : COLOR_RED;
    layer_ball_3.color = layer_ball_1.color = (color_pattern) ? COLOR_RED : COLOR_GREEN;
  color_pattern = (color_pattern) ? 0 : 1; 
}

/*
 * Function that advances the current layer
 * and adjusts the background color based
 * on the button pressed.
 * Input: the buttons pressed, with the
 *        buttons changed as the high bit
 *        and buttons pressed as the low bit.
 * Output: None. 
 */
void catch_red_display(char btn_pressed) {
  if ((btn_pressed & 1) == 0) {
    bg_color = COLOR_BLACK;
  }
  else if ((btn_pressed & 4) == 0) {
    bg_color = COLOR_WHITE;
  }
  ml_advance(&ml_ball_1, &field_fence);
}

