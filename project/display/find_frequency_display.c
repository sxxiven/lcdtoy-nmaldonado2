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

const ab_hourglass hourglass = {ab_hourglass_get_bounds, ab_hourglass_check, {12, 15}, 3};

AbRect rect11 = {abRectGetBounds, abRectCheck, {10,10}}; /**< 10x10 rectangle */
AbRArrow rightArrow2 = {abRArrowGetBounds, abRArrowCheck, 30};

AbRectOutline fieldOutline2 = {	/* playing field */
  abRectOutlineGetBounds, abRectOutlineCheck,   
  {screenWidth/2 - 10, screenHeight/2 - 10}
};

Layer fieldLayer_2 = {
  (AbShape *)&fieldOutline2,
  {(screenWidth/2), (screenHeight/2)}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_GREEN,
  0
};

Layer layer3_2 = {
  (AbShape *)&hourglass,
  {(screenWidth/2)+10, (screenHeight/2)+5}, /**< bit below & right of center */
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_PINK,
  &fieldLayer_2
};

MovLayer ml0_2 = {&layer3_2, {1,0}, 0};

void display_new_find_frequency(){
  layerInit(&layer3_2);
  layerDraw(&layer3_2);
  layerGetBounds(&fieldLayer_2, &fieldFence);
}

void find_frequency_display(char btn_pressed) {
  switch(btn_pressed & 15) {
  case 14:
    bgColor = COLOR_RED;
    display_new_find_frequency();
    break;
  default:
    break;//mlAdvance(&ml0_2, &fieldFence);
  }
}
