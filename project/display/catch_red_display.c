/** \file shapemotion.c
 *  \brief This is a simple shape motion demo.
 *  This demo creates two layers containing shapes.
 *  One layer contains a rectangle and the other a circle.
 *  While the CPU is running the green LED is on, and
 *  when the screen does not need to be redrawn the CPU
 *  is turned off along with the green LED.
 */  
#include <msp430.h>
#include <lcdutils.h>
#include "shape.h"
#include <abCircle.h>
#include "move_layer.h"
#include "display_utils.h"
#include "find_frequency_display.h"

Layer layer_ball_4 = {		
  (AbShape *)&circle14,
  {20, (screenHeight/2) - 52},
  {0,0}, {0,0},				    
  COLOR_RED,
  &fieldLayer_2,
};

Layer layer_ball_3 = {		
  (AbShape *)&circle14,
  {(screenWidth/2)+30, (screenHeight/2)-18}, 
  {0,0}, {0,0},				    
  COLOR_GREEN,
  &layer_ball_4,
};

Layer layer_ball_2 = {		
  (AbShape *)&circle14,
  {20, (screenHeight/2) + 18},
  {0,0}, {0,0},				    
  COLOR_RED,
  &layer_ball_3,
};

Layer layer_ball_1 = {		
  (AbShape *)&circle14,
  {(screenWidth/2)+30, (screenHeight/2)+52}, 
  {0,0}, {0,0},				    
  COLOR_GREEN,
  &layer_ball_2,
};

MovLayer ml_ball_4 = {&layer_ball_4, {2,0}, 0};
MovLayer ml_ball_3 = {&layer_ball_3, {-2,0}, &ml_ball_4};
MovLayer ml_ball_2 = {&layer_ball_2, {2,0}, &ml_ball_3};
MovLayer ml_ball_1 = {&layer_ball_1, {-2,0}, &ml_ball_2};

void display_new_catch_red(){
  //fill_rectangle(0,0,screenWidth,screenHeight,COLOR_GREEN);
  //and_sr(~8);
  
  bgColor = COLOR_WHITE;
  layerInit(&layer_ball_1);
  //fill_rectangle(0,0,screenWidth,screenHeight, bgColor);
  layerDraw(&layer_ball_1);
  layerGetBounds(&fieldLayer_2, &fieldFence);
  //or_sr(8);
}

void change_ball_color() {
  static u_char color_pattern = 1;
  layer_ball_4.color = layer_ball_2.color = (color_pattern) ? COLOR_GREEN : COLOR_RED;
    layer_ball_3.color = layer_ball_1.color = (color_pattern) ? COLOR_RED : COLOR_GREEN;
  color_pattern = (color_pattern) ? 0 : 1; 
}

void catch_red_display(char btn_pressed) {
  if ((btn_pressed & 1) == 0) {
    bgColor = COLOR_BLACK;
  }
  else if ((btn_pressed & 4) == 0) {
    bgColor = COLOR_WHITE;
  }
  mlAdvance(&ml_ball_1, &fieldFence);
}
