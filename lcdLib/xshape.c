/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawX(u_char min_col, u_char min_row, u_char height, u_int bgr) {
  
  for(u_char height_offset = 0; height_offset <= height; height_offset++) {
    drawPixel(min_col, min_row, bgr);
    if ((height % 2) == 0 || (height % 2) != 0 && height_offset != (height / 2) + 1) {
      drawPixel(min_col + height - 2 *height_offset, min_row, bgr);
    }
    min_col++;
    min_row++;
  }

}

void drawXThick(u_char min_col, u_char min_row, u_char height, u_char thickness, u_int bgr) {
  
  for(u_char height_offset = 0; height_offset <= height; height_offset++) {
    fillRectangle(min_col, min_row, thickness, 1, bgr);
    if ((height % 2) == 0 || (height % 2) != 0 && height_offset != (height / 2) + 1) {
      fillRectangle(min_col + height - 2 *height_offset, min_row, thickness, 1, bgr);
    }
    min_col++;
    min_row++;
  }

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
  drawX(40,30,20, COLOR_WHITE);
  drawXThick(30,60,61,10,COLOR_RED);
}
