/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawCurveDown(u_char start_x, u_char end_x, u_char shift_vertex_horizontal, u_char shift_vertex_vertical){
  // if vertex at 0, when we do y - prev_y,
  // then we need to set prev_y to a negative one
  // or 255 unsigned. If we shift the vertex up,
  // we add to the -1, or 255 in this case.
  //u_char prev_y = 255 + shift_vertex_vertical;

  u_char prev_y = 0;
  
  for (u_char x = start_x; x <= end_x; x++) {
    u_char y = (u_char)(pow(x - shift_vertex_horizontal, 2)) + shift_vertex_vertical;
    if (x == start_x) {
      prev_y = y;
    }

    drawPixel(x, y, COLOR_BLUE);
    if (x < shift_vertex_horizontal && x != 0 && prev_y - y > 1) {
      fillRectangle(x - 1, y + 1, 1, prev_y - y - 1, COLOR_BLUE);
    }
    else if (x > shift_vertex_horizontal && y - prev_y > 1) {
      fillRectangle(x, prev_y + 1, 1, y - prev_y - 1, COLOR_BLUE);
    }
    
    prev_y = y;
  }
}


int main() {
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  fillRectangle(0,0,width,height, COLOR_GREEN);
  //drawXWithThickness(0, 0, 20, 5);
  //drawDiamondCoordinates(9, 5, 41);
  //drawDiamond(20, 5, 10);
  //drawRectWithLines(20, 20, 40, 50);
  drawCurveDown(40, 56, 40, 10);
  //drawRightTriangle(20,40,40);
  //drawDiamondNarrow(60, 70, 40, 1, COLOR_RED);
  //drawDiamondMult(60,70,50,1,3, COLOR_RED);
  //diamondOutline(60, 60, 91, COLOR_RED);
  //rectangleOutline(30,40,40,60, COLOR_RED);
  //drawBracket(30, 40, 40, COLOR_BLUE);
  //drawHalfDiamond(30, 50, 30, COLOR_RED);
  //drawHouse(20, 130, 60, 60);
}
