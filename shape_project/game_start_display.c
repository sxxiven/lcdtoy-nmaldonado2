#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>
#include "game_start_display.h"

u_char game_num = 0;

void load_start_game(){
  fillRectangle(0,0,screenWidth, screenHeight, COLOR_RED);
}

void update_start_game(u_char btns_pressed,Layer *layer_person_body, Layer *fieldLayer, Region *fieldFence){
  
  switch(btns_pressed & 15) {

    //btn1 pressed
  case 14:
    game_num = 1;
    bgColor = COLOR_BLUE;
    layerInit(layer_person_body);
    layerDraw(layer_person_body);
    layerGetBounds(fieldLayer, fieldFence);
  }
}
