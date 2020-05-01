#include "lcdutils.h"

void drawDiamondNarrow(u_char x, u_char y, u_char height, u_char steps, u_int color_bgr);

void drawDiamondWide(u_char x, u_char y, u_char width, u_char steps, u_int color_bgr);

void drawDiamondMult(u_char x, u_char y, u_char width, u_char steps_horizontal, u_char steps_vertical, u_int color_bgr);

// Center of diamond at (x, y)
void diamondOutline(u_char x, u_char y, u_char height, u_int bgr);
