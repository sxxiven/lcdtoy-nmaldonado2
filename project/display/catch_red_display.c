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

static Region fieldFence_3;

AbRectOutline fieldOutline3 = {	/* playing field */
  abRectOutlineGetBounds, abRectOutlineCheck,   
  {screenWidth/2 - 5, screenHeight/2 - 5}
};

Layer fieldLayer_3 = {
  (AbShape *)&fieldOutline3,
  {(screenWidth/2), (screenHeight/2)}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_BLACK,
  0
};

Layer layer_ball_3 = {		/**< Layer with an orange circle */
  (AbShape *)&circle16,
  {(screenWidth/2)+10, (screenHeight/2)+5}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_VIOLET,
  &fieldLayer_3,
};

Layer layer_ball_2 = {		/**< Layer with an orange circle */
  (AbShape *)&circle16,
  {(screenWidth/2)+10, (screenHeight/2)+5}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_VIOLET,
  &layer_ball_3,
};

Layer layer_ball_1 = {		/**< Layer with an orange circle */
  (AbShape *)&circle16,
  {(screenWidth/2)+10, (screenHeight/2)+5}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_VIOLET,
  &layer_ball_2,
};


MovLayer ml_ball_3 = {&layer_ball_3, {2,2}, 0};
MovLayer ml_ball_2 = {&layer_ball_2, {2,2}, &ml_ball_3};
MovLayer ml_ball_1 = {&layer_ball_1, {2,2}, &ml_ball_2};

void display_new_catch_red(){
  //fill_rectangle(0,0,screenWidth,screenHeight,COLOR_GREEN);
  bgColor = COLOR_WHITE;
  layerInit(&layer_ball_1);
  layerDraw(&layer_ball_1);
  layerGetBounds(&fieldLayer_3, &fieldFence_3);
}

void change_ball_color() {
  static u_char color_pattern = 1;
  
  /*layer_mini_hourglass_1.color = (color_pattern) ? COLOR_ORANGE : COLOR_RED;
  layer_mini_hourglass_2.color = (color_pattern) ? COLOR_ORANGE : COLOR_YELLOW;
  layer_hourglass_1.color = layer_hourglass_2.color = (color_pattern) ? COLOR_BLACK : COLOR_WHITE;*/
  color_pattern = (color_pattern) ? 0 : 1; 
}

void catch_red_display(char btn_pressed) {
  mlAdvance(&ml_ball_1, &fieldFence_3);
}
