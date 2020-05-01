#include "lcdutils.h"
#include "lcddraw.h"
#include "triangle.h"

void drawRightTriangle(u_char row_start, u_char col_start, u_char side){
  for(u_char i = row_start; i < row_start + side; i++){
    fillRectangle(col_start, i, i - row_start+ 1, 1, COLOR_BLUE);
  }
}

void drawUpsideDownRightTriangle(u_char x, u_char y, u_char height, u_int bgr){
  for(u_char col_pointer = x; height > 0; height--) {
    fillRectangle(col_pointer, y, 1, height, bgr);
    col_pointer++;
    
  }
}

void drawHalfDiamond(u_char min_col, u_char max_row, u_char width, u_int bgr) {
  u_char col_track = 0;
  for(; width > 0; width -= 2){
    fillRectangle(min_col + col_track, max_row, width, 1, bgr);
    max_row--;
    col_track++;
  }
}

void drawHalfDiamondDown(u_char x, u_char y, u_char height, u_int bgr) {
  u_char row_offset = 0;
  for (;row_offset < height; row_offset++) {
    u_char row_end = y + height - row_offset - 1;
    for (u_char i = y; i <= row_end; i++) {
      drawPixel(y + row_offset, i, bgr);
      if (row_offset != 0) {
	drawPixel(y - row_offset, i, bgr);
      }
    }
  }
}

void drawRightTriangleLeft(u_char x_corner, u_char y_corner, u_char width, u_int bgr){

  u_char row_start = x_corner - width + 1;
  for (; row_start <= x_corner; row_start++) {
    for (u_char i = row_start; i <= x_corner; i++) {
      drawPixel(y_corner, i, bgr);
    }
    y_corner--;
  }
}


void drawHourGlass(u_char x, u_char y, u_char height) {
  for (u_char i = 0; i <= height/2; i++) {
    drawPixel(x - i, y - i, COLOR_RED);
    drawPixel(x + i, y - i, COLOR_RED);
    drawPixel(x - i, y + i, COLOR_RED);
    drawPixel(x + i, y + i, COLOR_RED);
    //Top
    drawPixel(x - i, y - (height / 2), COLOR_RED);
    drawPixel(x + i, y - (height/2), COLOR_RED);
    //Bottom
    drawPixel(x - i, y + (height / 2), COLOR_RED);
    drawPixel(x + i, y + (height / 2), COLOR_RED);
  }
}


void drawHourGlassFilled(u_char x, u_char y, u_char height) {
  for (u_char i = 0; i <= (height/2); i++) {
    for (u_char j = x - i; j <= x + i; j++) {
      drawPixel(j, y + i, COLOR_RED);
      drawPixel(j, y - i, COLOR_RED);
    }
  }
}

void drawHourGlassOnSideFilled(u_char x, u_char y, u_char width) {
  for (u_char i = 0; i <= (width/2); i++) {
    for (u_char j = 0; j <= i; j++) {
      drawPixel(x + i, y + j, COLOR_RED);
      drawPixel(x + i, y - j, COLOR_RED);
      drawPixel(x - i, y + j, COLOR_RED);
      drawPixel(x - i, y - j, COLOR_RED);
    }
  }
}

void drawHourGlassOnSide(u_char x, u_char y, u_char width) {
  for (u_char i = 0; i <= (width / 2); i++) {
    drawPixel(x + i, y - i, COLOR_RED);
    drawPixel(x + i, y + i, COLOR_RED);

    drawPixel(x - i, y - i, COLOR_RED);
    drawPixel(x - i, y + i, COLOR_RED);

    //LeftSide
    drawPixel(x - (width/2), y + i, COLOR_RED);
    drawPixel(x - (width/2), y - i, COLOR_RED);

    //RightSide
    drawPixel(x + (width/2), y - i, COLOR_RED);
    drawPixel(x + (width/2), y + i, COLOR_RED);
  }
}

void drawTrapezoid(u_char min_col, u_char max_row, u_char base_width, u_char height) {
  for (u_char i = 0; i < height; i++) {
    u_char start_col = min_col + i;
    for (u_char j = 0; j < base_width; j++) {
      drawPixel(start_col + j, max_row - i, COLOR_RED);
    }
    base_width -= 2;
  }
}

void equiTriToRight(u_char min_col, u_char min_row, u_char width){
  u_char row_offset = 0;
  for (u_char i = min_col; i <= min_col + width; i++) {
 
    for (u_char j = min_row + row_offset; j <= min_row + (2 * width) - row_offset; j++) {
      drawPixel(i, j, COLOR_RED);
    }
    row_offset += 1;
  }
}

void rightTriDownLeft(u_char x, u_char y, u_char height) {
  u_char offset = 0;
  for (u_char i = x; i >= x - height; i--) {
    for (u_char j = y; j <= y + height - offset; j++) {
      drawPixel(i, j, COLOR_RED);
    }
    offset++;
  }
}

void rightTriDownLeftOutline(u_char x, u_char y, u_char height) {
  for (u_char i = y; i <= y + height; i++) {
    drawPixel(x, i, COLOR_RED);
  }
  u_char offset = 0;
  for (u_char i = x - 1; i >= x - height; i--) {
    drawPixel(i, y, COLOR_RED);
    drawPixel(i, y + height - offset, COLOR_RED);
    offset++;
  }
}

void rightTriUpLeftTipToBase(u_char x, u_char y, u_char width) {
  u_char offset = 0;
  for (u_char i = x; i <= i + width; i++) {
    for (u_char j = y; j >= y - width + offset; j--) {
      drawPixel(i, j, COLOR_RED);
    }
    offset--;
  }
}

void rightTriUpLeftTipToBaseOutline(u_char x, u_char y, u_char width) {
  u_char offset = 0;
  for (u_char i = x; i <= x + width; i++) {
    drawPixel(i, y, COLOR_RED);
    drawPixel(i, y - offset, COLOR_RED);
    offset++;
  }
  for (u_char i = y - 1; i >= y - width + 1; i--) {
    drawPixel(x + width, i, COLOR_RED);
  }
}

