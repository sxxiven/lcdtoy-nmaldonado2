#include "display_utils.h"
#include "lcddraw.h"
void fill_rectangle(u_char min_col, u_char min_row, u_char width, u_char height, u_int bgr) {
  for (u_char i = min_col; i < min_col + width; i++) {
    for (u_char j = min_row; j < min_row + height; j++) {
      drawPixel(i,j,bgr);
    }
  }
}
