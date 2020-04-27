/** \file shapemotion.c
 *  \brief This is a simple shape motion demo.
 *  This demo creates two layers containing shapes.
 *  One layer contains a rectangle and the other a circle.
 *  While the CPU is running the green LED is on, and
 *  when the screen does not need to be redrawn the CPU
 *  is turned off along with the green LED.
 */  
#include <msp430.h>
#include "libTimer.h"
#include <lcdutils.h>
#include "shape.h"
#include <abCircle.h>
#include "move_layer.h"
#include "fur_elise_display.h"
#include "lcddraw.h"
#include "find_frequency_display.h"
#include "catch_red_ml.h"
#include "buzzer.h"
#include "display_utils.h"

AbRect key = {abRectGetBounds, abRectCheck, {(screenWidth/2) - 20, 20}};
/*
static void drawPianoBlackKey(u_char x, u_char y, u_char width, u_char height, u_char tip_width){
  u_char rounded = 0;
  for(u_char offset = 0; offset <= width/2; offset++) {
    fill_rectangle(x, y + offset, height - rounded, 1, COLOR_BLACK);

    if (offset > 0) {
      fill_rectangle(x, y - offset, height - rounded, 1, COLOR_BLACK);
    }

    if (offset >= tip_width) {
      rounded++;
    }
  }
}

void topKey(u_char x, u_char y, u_char min_width, u_char width, u_char small_height, u_char large_height, u_char start_descent, u_int bgr) {
  u_char offset = 1;
  for (u_char i = x; i <= x + width; i++) {
    if (i < min_width - start_descent) {
      fill_rectangle(i, y, 1, small_height, bgr);
    }
    else if (i < min_width) {
      fill_rectangle(i, y, 1, small_height + offset, bgr);
      offset++;
    }
    else {
      fill_rectangle(i, y, 1, large_height, bgr);
    }
  }
}

void bottomKey(u_char x, u_char y, u_char min_width, u_char width, u_char small_height, u_char large_height, u_char start_descent, u_int bgr) {
  u_char offset = 1;
  for (u_char i = x; i <= x + width; i++) {
    if (i < min_width - start_descent) {
      fill_rectangle(i, y - small_height, 1, small_height, bgr);
    }
    else if (i < min_width) {
      fill_rectangle(i, y - small_height - offset, 1, small_height + offset, bgr);
      offset++;
    }
    else {
      fill_rectangle(i, y-large_height, 1, large_height, bgr);
    }
  }
}

// where x and y are center of the key
void middleKey(u_char x, u_char y, u_char min_width, u_char width, u_char small_height, u_char large_height, u_char start_descent, u_int bgr) {
  u_char offset = 1;
  for (u_char i = x; i <= x + width; i++) {
    if (i < min_width - start_descent) {
      fill_rectangle(i, y - (small_height/2)-1, 1, small_height, bgr);
    }
    else if (i < min_width) {
      fill_rectangle(i, y - (small_height/2) - offset - 1, 1, small_height + (2 *offset), bgr);
      offset++;
    }
    else{
      fill_rectangle(i, y - (large_height/2)-1, 1, large_height, bgr);
    }
  }

  }*/
/*
key top_key = {
  &topKey,
  0, 0,
  65, screenWidth,
  20, 35,
  7, COLOR_WHITE,
  0
};

key middle_key = {
  &middleKey,
  0, 59,
  65, screenWidth,
  15, 40,
  7, COLOR_WHITE,
  0
};

key bottom_key = {
  &middleKey,
  0, 103,
  65, screenWidth,
  15, 40,
  7, COLOR_WHITE,
  0
};
*/
/*
static void add_key(key *node) {
  if (!keys_to_change) {
    keys_to_change = node;
    return;
  }
  node->next = keys_to_change->next;
  keys_to_change->next = node;
}
*/
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
  /*
  fill_rectangle(0,0,screenWidth,screenHeight, COLOR_GRAY);
 topKey(0,0,65,screenWidth,20,35,7,COLOR_WHITE);
  drawPianoBlackKey(0,35,30,65, 10);
  middleKey(0,59,65,screenWidth,15,40,7,COLOR_WHITE);
  drawPianoBlackKey(0,80,30,65, 10);
  middleKey(0,103,65,screenWidth,15,40,7,COLOR_WHITE);
  drawPianoBlackKey(0,125,30,65, 10);
  bottomKey(0,screenHeight,65,screenWidth,20,35,7,COLOR_WHITE);
  */
}
/*
void display_piano() {
  and_sr(~8);
  or_sr(8);
  //keys_to_change = &bottom_key;
  //u_char offset = 20;

  while (keys_to_change) {
    
    keys_to_change->print_key(keys_to_change->x, keys_to_change->y, keys_to_change->min_width, keys_to_change->width, keys_to_change->min_height, keys_to_change->height, keys_to_change->start_descent, keys_to_change->bgr);
    key *prev = keys_to_change;
    keys_to_change = keys_to_change->next;
    prev->next = 0;
  }
}
*/

/*
void fur_elise_display(u_char btn_pressed) {
  // fourth btn pressed
  
  if ((btn_pressed>>4) & 8) {
    if (!(btn_pressed & 8)) {
      key_1.color = COLOR_BLUE;
    }
    else {
      key_1.color = COLOR_WHITE;
    }
  }

  if ((btn_pressed>>4) & 4) {
    if (!(btn_pressed & 4)) {
      key_2.color = COLOR_RED;
    }
    else {
      key_2.color = COLOR_WHITE;
    }
  }
  if ((btn_pressed>>4) & 2) {
    if (!(btn_pressed & 2)) {
      key_3.color = COLOR_YELLOW;
    }
    else {
      key_3.color = COLOR_WHITE;
    }
   
  }
  mlAdvance(&ml_key_1, &fieldFence);
}
*/
