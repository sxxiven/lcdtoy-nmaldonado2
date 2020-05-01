/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawBracket(u_char mid_x, u_char mid_y, u_char height, u_int bgr){
  for (u_char pointer = 0; pointer <= (height / 2); pointer++) {
    drawPixel(mid_x, mid_y - pointer, bgr);
    if (pointer != mid_y) {
      drawPixel(mid_x, mid_y + pointer, bgr);
    }mid_x++;
  }
}


static void fill_rectangle(u_char min_col, u_char min_row, u_char width, u_char height, u_int bgr) {
  for (u_char i = min_col; i < min_col + width; i++) {
    for (u_char j = min_row; j < min_row + height; j++) {
      drawPixel(i,j,bgr);
    }
  }
}

static void drawPianoBlackKey(u_char x, u_char y, u_char width, u_char height, u_char tip_width){
  u_char rounded = 0;
  for(u_char offset = 0; offset <= width/2; offset++) {
    fill_rectangle(x, y + offset, height - rounded, 1, COLOR_BLACK);

    if (offset > 0) {
      fill_rectangle(x, y - offset, height - rounded, 1, COLOR_BLACK);
    }

    if (offset >= tip_width) {
      rounded++;
    }
  }
}

void topKey(u_char x, u_char y, u_char min_width, u_char width, u_char small_height, u_char large_height, u_char start_descent, u_int bgr) {
  u_char offset = 1;
  for (u_char i = x; i <= x + width; i++) {
    if (i < min_width - start_descent) {
      fill_rectangle(i, y, 1, small_height, bgr);
    }
    else if (i < min_width) {
      fill_rectangle(i, y, 1, small_height + offset, bgr);
      offset++;
    }
    else {
      fill_rectangle(i, y, 1, large_height, bgr);
    }
  }
}

void bottomKey(u_char x, u_char y, u_char min_width, u_char width, u_char small_height, u_char large_height, u_char start_descent, u_int bgr) {
  u_char offset = 1;
  for (u_char i = x; i <= x + width; i++) {
    if (i < min_width - start_descent) {
      fill_rectangle(i, y - small_height, 1, small_height, bgr);
    }
    else if (i < min_width) {
      fill_rectangle(i, y - small_height - offset, 1, small_height + offset, bgr);
      offset++;
    }
    else {
      fill_rectangle(i, y-large_height, 1, large_height, bgr);
    }
  }
}

// where x and y are center of the key
void middleKey(u_char x, u_char y, u_char min_width, u_char width, u_char small_height, u_char large_height, u_char start_descent, u_int bgr) {
  u_char offset = 1;
  for (u_char i = x; i <= x + width; i++) {
    if (i < min_width - start_descent) {
      fill_rectangle(i, y - (small_height/2)-1, 1, small_height, bgr);
    }
    else if (i < min_width) {
      fill_rectangle(i, y - (small_height/2) - offset - 1, 1, small_height + (2 *offset), bgr);
      offset++;
    }
    else{
      fill_rectangle(i, y - (large_height/2)-1, 1, large_height, bgr);
    }
  }

}

void drawTriangle() {
  u_char size = 15;
  for(u_char r = 0; r <= size; r+= 3) {
    u_char colLeft = size - r;
    u_char colRight = size;
    for(u_char c = colLeft; c <= colRight; c+= 3) {
      //drawPixel(20 + c, r + 20, COLOR_RED);
      //drawPixel(20 -  c, r + 20, COLOR_RED);
      drawPixel(20 - c, 20 - r, COLOR_RED);
    }
  }
}


void drawTriangle2() {
  u_char size = 15;
  for (u_char col = 0; col < 15; col++) {
    u_char row = col;
    u_char row_end = 15;
    for (u_char c = row; c <= row_end; c++) {
      drawPixel(20 - col, 40 - c, COLOR_RED);
      //drawPixel(20 + col, 40 - c, COLOR_RED);
    }
  }
}


void drawTriangle3() {
  u_char size = 15;
  for (u_char col = 0; col < 15; col++) {
    u_char row_start = 0;
    u_char row_end = col;
    for (u_char r = row_start; r <= row_end; r++) {
      drawPixel(20 + col, 20 - r, COLOR_RED);
      drawPixel(20 - col, 20 - r, COLOR_RED);
    }
  }
}

void drawThis4() {
  u_char fc = 15;
  u_char fr = 15;
  u_char size = 15;
  for (u_char c = 0; c <= size; c++) {
    u_char row_start = 0;
    u_char row_end = c;
    for (u_char r = row_start; r <= row_end; r++) {
      drawPixel(fc + c, fr+r, COLOR_RED);
      drawPixel(fc-c, fr+r, COLOR_RED);
    }
  }
}

void drawThis5() {
  u_char fc = 15;
  u_char fr = 15;
  u_char size = 15;
  for (u_char c = 0; c < size; c++) {
    u_char row_start = size;
    u_char row_end = size - c;
    for (u_char r = row_start; r >= row_end; r--) {
      drawPixel(fc + c, fr+r, COLOR_RED);
      drawPixel(fc + c,fr - r + size + size, COLOR_RED);
    }
  }
}

int main() {
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  fillRectangle(0,0,width,height, COLOR_GRAY);
  drawTriangle2();

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
  //drawHouse(20, 130, 60, 60);
  //drawString8x12(20,20, "hello, My name is NICHOLE", COLOR_BLUE, COLOR_WHITE);
  //drawTriangle();
  /*
  topKey(0,0,65,screenWidth,20,35,7,COLOR_WHITE);
  drawPianoBlackKey(0,35,30,65, 10);
  middleKey(0,59,65,screenWidth,15,40,7,COLOR_WHITE);
  drawPianoBlackKey(0,80,30,65, 10);
  middleKey(0,103,65,screenWidth,15,40,7,COLOR_WHITE);
  drawPianoBlackKey(0,125,30,65, 10);
  bottomKey(0,screenHeight,65,screenWidth,20,35,7,COLOR_WHITE);
  */
  //fill_rectangle(0,0,30,30,COLOR_BLUE);
  // drawString8x12(22,55, "Hello", COLOR_RED, COLOR_BLUE);

}
