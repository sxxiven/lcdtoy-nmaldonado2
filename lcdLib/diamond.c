#include "lcdutils.h"
#include "lcddraw.h"
#include "diamond.h"

void drawDiamondNarrow(u_char x, u_char y, u_char height, u_char steps, u_int color_bgr){
  u_char top = y - (height/2) + ((height %2 == 0) ? 1 : 0);
  u_char bottom = height + top - 1;
  u_char col_offset = 0;

  while(top <= bottom) {
    fillRectangle(x - col_offset, top, 1, bottom - top + 1, color_bgr);
    if (col_offset != 0) {
      fillRectangle(x + col_offset, top, 1, bottom - top + 1, color_bgr);
    }
    col_offset++;
    top += steps;
    bottom -= steps;
  }
}

void drawDiamondWide(u_char x, u_char y, u_char width, u_char steps, u_int color_bgr){
  u_char left = x - (width / 2) + ((width % 22 == 0)? 1 : 0);
  u_char right = left + width - 1;
  u_char row_offset = 0;

  while(left <= right){
    fillRectangle(left, y - row_offset, right - left + 1, 1, color_bgr);
    if(row_offset != 0){
      fillRectangle(left, y + row_offset, right - left + 1, 1, color_bgr);
    }
    row_offset++;
    left += steps;
    right -= steps;
  }  
}

void drawDiamondMult(u_char x, u_char y, u_char width, u_char steps_horizontal, u_char steps_vertical, u_int color_bgr){
  u_char top = y - (steps_vertical / 2) - ((steps_vertical %2 == 0) ? 1 : 0);
  u_char bottom = top;
  u_char left = x - (width / 2) + ((width % 2 == 0)? 1 : 0);
  u_char right = left + width - 1;
  
  while(left <= right) {
    fillRectangle(left, top, right - left + 1, steps_vertical, color_bgr);
  
    if(top != bottom) {
      fillRectangle(left, bottom, right - left + 1, steps_vertical, color_bgr);
    }

    top -= steps_vertical;
    bottom += steps_vertical;
    left += steps_horizontal;
    right -= steps_horizontal;
  }
}

// Center of diamond at (x, y)
void diamondOutline(u_char x, u_char y, u_char height, u_int bgr){
  u_char col_offset = 0;
  u_char is_even = (height % 2) ? 1 : 0;
  u_char top = y - (height / 2) + is_even;

  for(;top <= y; top++){
    if (col_offset == 0) {
      drawPixel(x, top, bgr);
      drawPixel(x, y + (y - top) + is_even, bgr);
    }
    else if (is_even == 0 && top == y) {
      drawPixel(x - col_offset, y, bgr);
      drawPixel(x + col_offset, y, bgr);
    }
    else {
      drawPixel(x - col_offset, top, bgr);
      drawPixel(x + col_offset, top, bgr);
      drawPixel(x - col_offset, y + (y - top) + is_even, bgr);
      drawPixel(x + col_offset, y + (y -top) + is_even, bgr);
    }
    col_offset++;
    top++;
  }
}
