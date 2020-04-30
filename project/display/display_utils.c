// Nichole Maldonado
// Function that fills a rectange of a
// given height and width.

#include "display_utils.h"
#include "lcddraw.h"

/*
 * Draw a rectangle starting at min_col
 * and min_row and taking up height and
 * width.
 * Input: The minimum column and row to draw the
 * rectangle. The height, width and color of the rectangle.
 * Output: None
 */
void fill_rectangle(u_char min_col, u_char min_row, u_char width, u_char height, u_int bgr) {
  for (u_char i = min_col; i < min_col + width; i++) {
    for (u_char j = min_row; j < min_row + height; j++) {
      drawPixel(i,j,bgr);
    }
  }
}
