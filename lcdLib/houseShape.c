/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "diamond.h"
#include "triangle.h"
void drawSlantedRect(u_char x, u_char y, u_char height, u_char width, u_int bgr) {
  u_char max_x = width + x - 1;
  while (x <= max_x) {
    fillRectangle(x, y, 1, height, bgr);
    x++;
    y--;
  }
}

void drawHouse(u_char x, u_char y, u_char front_house_width, u_char front_house_height) {
  fillRectangle(x, y - front_house_height + 1, front_house_width, front_house_height, COLOR_YELLOW);
  drawHalfDiamond(x, (y - front_house_height), front_house_width, COLOR_RED);
  drawSlantedRect(x + front_house_width, y - front_house_height + 1, front_house_height, front_house_width / 2, COLOR_GOLD);
  u_char is_even = (front_house_width % 2) ? 1 : 0;
  u_char slanted_width = ((front_house_width/2) + is_even / 2);
  drawDiamondMult(x + front_house_width - 1, y - front_house_height - slanted_width, front_house_width + is_even, 1, 1, COLOR_FIREBRICK);
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
  //drawCurveDown(40, 56, 40, 10);
  //drawRightTriangle(20,40,40);
  //drawDiamondNarrow(60, 70, 40, 1, COLOR_RED);
  //drawDiamondMult(60,70,50,1,3, COLOR_RED);
  //diamondOutline(60, 60, 91, COLOR_RED);
  //rectangleOutline(30,40,40,60, COLOR_RED);
  //drawBracket(30, 40, 40, COLOR_BLUE);
  //drawHalfDiamond(30, 50, 30, COLOR_RED);
  drawHouse(20, 130, 60, 60);
}
