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
#include "fur_elise_display.h"
#include "hourglass.h"
#include "display_utils.h"
#include "buzzer.h"

const ab_hourglass hourglass = {ab_hourglass_get_bounds, ab_hourglass_check, {12, 17}, 3};
const ab_hourglass hourglass_mini = {ab_hourglass_get_bounds, ab_hourglass_check, {10, 15}, 0};

AbRectOutline fieldOutline2 = {	/* playing field */
  abRectOutlineGetBounds, abRectOutlineCheck,   
  {screenWidth/2 - 5, screenHeight/2 - 5}
};

Layer fieldLayer_2 = {
  (AbShape *)&fieldOutline2,
  {(screenWidth/2), (screenHeight/2)}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_BLACK,
  0
};

Layer layer_hourglass_2 = {
  (AbShape *)&hourglass,
  {(screenWidth/2) -30, (screenHeight/2)-30}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_WHITE,
  &fieldLayer_2
};

Layer layer_hourglass_1 = {
  (AbShape *)&hourglass,
  {(screenWidth/2)+30, (screenHeight/2)+30}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_WHITE,
  &layer_hourglass_2
};

Layer layer_mini_hourglass_2 = {
  (AbShape *)&hourglass_mini,
  {(screenWidth/2)-30, (screenHeight/2)-30}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_YELLOW,
  &layer_hourglass_1
};

Layer layer_mini_hourglass_1 = {
  (AbShape *)&hourglass_mini,
  {(screenWidth/2)+30, (screenHeight/2)+30}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_RED,
  &layer_mini_hourglass_2
};

MovLayer ml_hg_2 = {&layer_hourglass_2, {0,1}, 0};
MovLayer ml_hg_1 = {&layer_hourglass_1, {0,1}, &ml_hg_2};
MovLayer ml_mini_hg_2 = {&layer_mini_hourglass_2, {1,0}, &ml_hg_1};
MovLayer ml_mini_hg_1 = {&layer_mini_hourglass_1, {1,0}, &ml_mini_hg_2};

void display_new_find_frequency(){
  //fill_rectangle(0,0,screenWidth,screenHeight,COLOR_GREEN);
  bgColor = COLOR_GREEN;
  layerInit(&layer_mini_hourglass_1);
  layerDraw(&layer_mini_hourglass_1);
  layerGetBounds(&fieldLayer_2, &fieldFence);
 }

void change_color() {
  static u_char color_pattern = 1;
  
  layer_mini_hourglass_1.color = (color_pattern) ? COLOR_ORANGE : COLOR_RED;
  layer_mini_hourglass_2.color = (color_pattern) ? COLOR_ORANGE : COLOR_YELLOW;
  layer_hourglass_1.color = layer_hourglass_2.color = (color_pattern) ? COLOR_BLACK : COLOR_WHITE;
  color_pattern = (color_pattern) ? 0 : 1;
  (color_pattern) ? buzzer_set_period(NOTE_A) : buzzer_set_period(NOTE_B);
}

void change_motion() {
  static u_char motion = 0; 
  ml_mini_hg_1.velocity.axes[0] = motion;
  ml_mini_hg_2.velocity.axes[0] = motion;
  ml_hg_1.velocity.axes[1] = motion;
  ml_hg_2.velocity.axes[1] = motion;
  motion = (motion) ? 0 : 1;
  (motion) ? buzzer_set_period(NOTE_C) : buzzer_set_period(NOTE_D);
}

