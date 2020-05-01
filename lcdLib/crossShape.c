/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawCross(u_char min_col, u_char min_row, u_char height, u_int bgr) {
  
  u_char vertical_line = min_col + (height / 2);
  u_char horizontal_line = min_row + (height / 2);
  fillRectangle(vertical_line, min_row, 1, height, bgr);
  fillRectangle(min_col, horizontal_line, height, 1, bgr);
}

void drawCrossThick(u_char min_col, u_char min_row, u_char height, u_char thickness, u_int bgr) {
  
  u_char vertical_line = min_col + (height / 2) - (thickness / 2);
  u_char horizontal_line = min_row + (height / 2) - (thickness / 2);
  fillRectangle(vertical_line, min_row, thickness, height, bgr);
  fillRectangle(min_col, horizontal_line, height, thickness, bgr);
}


/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  // draws a white horizontal line
  drawCross(40,30,20, COLOR_WHITE);
  drawCrossThick(30,60,60,10,COLOR_RED);
  // hw: how to draw other shapes,
  // draw x, draw +, draw diamond,
  // draw square
  // Figure this out before we meet on
  // Monday.
  // draw in different areas of the screen,
  // in left coroner, right corner, middle,
  // make methods where you can just give it corrdinates and will draw the x based on those coordinates.
  // draw triangles. draw different orientations.
  // make different files like lcdTriangle.c, lcdPlusSign.c
}
