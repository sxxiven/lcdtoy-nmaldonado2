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
#include "move_layer.h"
#include "display_utils.h"
#include "simon_display.h"
#include "find_frequency_display.h"

AbRArrow right_arrow = {abRArrowGetBounds, abRArrowCheck, 30};
/*
Layer layer_green_arrow = {		
  (AbShape *)&right_arrow,
  {20, (screenHeight/2) +20},
  {0,0}, {0,0},				    
  COLOR_RED,
  &fieldLayer_2
};
*/
Layer layer_red_arrow = {		
  (AbShape *)&right_arrow,
  {(screenWidth/2)+35, (screenHeight/2)+20}, 
  {0,0}, {0,0},				    
  COLOR_GREEN,
  &fieldLayer_2
};

//MovLayer ml_ball_4 = {&layer_ball_4, {2,0}, 0};
//MovLayer ml_ball_3 = {&layer_ball_3, {-2,0}, &ml_ball_4};
//MovLayer ml_green_arrow = {&layer_green_arrow, {2,0}, 0};
MovLayer ml_red_arrow = {&layer_red_arrow, {-2,0}, &ml_red_arrow};

void display_new_simon(){
  //fill_rectangle(0,0,screenWidth,screenHeight,COLOR_GREEN);
  //and_sr(~8);
  
  bgColor = COLOR_WHITE;
  layerInit(&layer_red_arrow);
  //fill_rectangle(0,0,screenWidth,screenHeight, bgColor);
  layerDraw(&layer_red_arrow);
  layerGetBounds(&fieldLayer_2, &fieldFence);
  //or_sr(8);
}
/*
void change_() {
  static u_char color_pattern = 1;
  layer_ball_4.color = layer_ball_2.color = (color_pattern) ? COLOR_GREEN : COLOR_RED;
    layer_ball_3.color = layer_ball_1.color = (color_pattern) ? COLOR_RED : COLOR_GREEN;
  color_pattern = (color_pattern) ? 0 : 1; 
}
*/
void simon_display(u_char btn_pressed) {
  /*if ((btn_pressed & 1) == 0) {
    bgColor = COLOR_BLACK;
  }
  else if ((btn_pressed & 4) == 0) {
    bgColor = COLOR_WHITE;
  }*/
  mlAdvance(&ml_red_arrow, &fieldFence);
}
