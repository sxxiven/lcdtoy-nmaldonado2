/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawRectWithLines(u_char start_row, u_char start_col, u_char height, u_char width, u_int bgr){

  fillRectangle(start_col, start_row, width, 1, bgr);
  fillRectangle(start_col, start_row + height - 1, width, 1, bgr);

  u_char j = start_col;
  for (; j < start_col + width; j+=2) {
    fillRectangle(j, start_row + 1, 1, height - 2, bgr);
  }
  if(j == start_row + width){
    fillRectangle(j - 1, start_row+1, 1, height - 2, bgr);
  }
}

void rectangleOutline(u_char col_min, u_char row_min, u_char height, u_char width, u_int bgr) {
  // Vertical bars
  fillRectangle(col_min, row_min, 1, height, bgr);
  fillRectangle(col_min + width - 1, row_min, 1, height, bgr);
  //horizontal bars
  fillRectangle(col_min + 1, row_min, width - 2, 1, bgr);
  fillRectangle(col_min + 1, row_min + height - 1, width - 2, 1, bgr);
}

int main() {
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  fillRectangle(0,0,width,height, COLOR_GREEN);
  //drawXWithThickness(0, 0, 20, 5);
  //drawDiamondCoordinates(9, 5, 41);
  //drawDiamond(20, 5, 10);
drawRectWithLines(20, 20, 40, 50, COLOR_BLUE);
  //drawCurveDown(40, 56, 40, 10);
  //drawRightTriangle(20,40,40);
  //drawDiamondNarrow(60, 70, 40, 1, COLOR_RED);
  //drawDiamondMult(60,70,50,1,3, COLOR_RED);
  //diamondOutline(60, 60, 91, COLOR_RED);
  rectangleOutline(30,100,40,60, COLOR_RED);
  //drawBracket(30, 40, 40, COLOR_BLUE);
  //drawHalfDiamond(30, 50, 30, COLOR_RED);
  //drawHouse(20, 130, 60, 60);
}
