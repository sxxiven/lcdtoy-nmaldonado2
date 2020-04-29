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
#include "fur_elise_display.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "display_utils.h"

AbRect key = {abRectGetBounds, abRectCheck, {(screenWidth/2) - 20, 20}};

Layer key_3 = {		
  (AbShape *)&key,
  {(screenWidth/2), (screenHeight/2)-50}, 
  {0,0}, {0,0},				    
  COLOR_WHITE,
  &fieldLayer_2
};

Layer key_2 = {		
  (AbShape *)&key,
  {(screenWidth/2), (screenHeight/2)}, 
  {0,0}, {0,0},				    
  COLOR_WHITE,
  &key_3
};

Layer key_1 = {		
  (AbShape *)&key,
  {(screenWidth/2), (screenHeight/2)+50}, 
  {0,0}, {0,0},				    
  COLOR_WHITE,
  &key_2
};

MovLayer ml_key_3 = {&key_3, {-1,0}, 0};
MovLayer ml_key_2 = {&key_2, {1,0}, &ml_key_3};
MovLayer ml_key_1 = {&key_1, {-1,0}, &ml_key_2};

void display_new_piano(){
  buzzer_set_period(0);
  bgColor = COLOR_BLACK;
  layerInit(&key_1);
  layerDraw(&key_1);
  layerGetBounds(&fieldLayer_2, &fieldFence);
}

void fur_elise_display(u_char btn_pressed) {
  // fourth btn pressed
  
  if ((btn_pressed>>4) & 8) {
    if (!(btn_pressed & 8)) {
      buzzer_set_period(NOTE_E);
      key_1.color = COLOR_BLUE;
    }
    else {
      key_1.color = COLOR_WHITE;
    }
  }

  if ((btn_pressed>>4) & 4) {
    if (!(btn_pressed & 4)) {
      buzzer_set_period(NOTE_E_FLAT);
      key_2.color = COLOR_RED;
    }
    else {
      key_2.color = COLOR_WHITE;
    }
  }
  if ((btn_pressed>>4) & 2) {
    if (!(btn_pressed & 2)) {
      buzzer_set_period(NOTE_B);
      key_3.color = COLOR_YELLOW;
    }
    else {
      key_3.color = COLOR_WHITE;
    }
   
  }
  if ((P2IN & 15) == 15) {
    buzzer_set_period(0);
  }
  
  mlAdvance(&ml_key_1, &fieldFence);
}
