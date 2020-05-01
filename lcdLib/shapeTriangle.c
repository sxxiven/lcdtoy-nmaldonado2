/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "triangle.h"

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
  // drawUpsideDownRightTriangle(20,80,40, COLOR_WHITE);
  //drawHalfDiamond(30, 50, 30, COLOR_RED);
  //drawHalfDiamondDown(30, 50, 30, COLOR_RED);
  //drawRightTriangleLeft(80,90,30, COLOR_ORANGE);
  //drawHourGlassOnSide(60,70,40);
  //drawTrapezoid(30, 60, 30, 10);
  //equiTriToRight(30,30,50);
  //rightTriDownLeft(80, 50, 40);
  rightTriUpLeftTipToBaseOutline(60, 80, 50);
}
