#include "lcdutils.h"

void drawRightTriangle(u_char row_start, u_char col_start, u_char side);
void drawUpsideDownRightTriangle(u_char x, u_char y, u_char height, u_int bgr);
void drawHalfDiamond(u_char min_col, u_char max_row, u_char width, u_int bgr);
void drawHalfDiamondDown(u_char x, u_char y, u_char width, u_int bgr);
void drawRightTriangleLeft(u_char x_corner, u_char y_corner, u_char width, u_int bgr);

void drawHourGlass(u_char x, u_char y, u_char height);
void drawHourGlassFilled(u_char x, u_char y, u_char height);

void drawHourGlassOnSide(u_char x, u_char y, u_char width);

void drawHourGlassOnSideFilled(u_char x, u_char y, u_char width);

void drawTrapezoid(u_char min_col, u_char max_row, u_char base_width, u_char height);

void equiTriToRight(u_char min_col, u_char min_row, u_char width);

void rightTriDownLeft(u_char min_col, u_char min_row, u_char width);

void rightTriDownLeftOutline(u_char x, u_char y, u_char height);

void rightTriUpperLeftTipToBase(u_char x, u_char y, u_char width);

void rightTriUpperLeftTipToBaseOutline(u_char x, u_char y, u_char width);
