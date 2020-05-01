/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);

  // draws a white horizontal line
  u_char j;
  for(j = 0; j < 50; j++){
    drawPixel(j, j, COLOR_WHITE);
  }

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
