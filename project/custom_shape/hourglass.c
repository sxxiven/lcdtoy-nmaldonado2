#include "shape.h"
#include "hourglass.h"

void ab_hourglass_get_bounds(const ab_hourglass *hourglass, const Vec2 *center_pos, Region *bounds)
{
  vec2Sub(&bounds->topLeft, center_pos, &hourglass->half_size);
  // add top of base.
  bounds->topLeft.axes[1] -= hourglass->base_offset;

  // add left side of base.
  bounds->topLeft.axes[0] -= hourglass->base_offset;
  
  vec2Add(&bounds->botRight, center_pos, &hourglass->half_size);

  // add bottom of base.
  bounds->botRight.axes[1] += hourglass->base_offset;

  // add right side of base.
  bounds->botRight.axes[0] += hourglass->base_offset; 
}

/*
char in_range(int num, int min_num, int max_num) {
  return num >= min_num && num <= max_num;
}

char in_rectangle(Vec2 *pixel, int min_row, int max_row, int min_col, int max_col) {
  return in_range(pixel.axes[1], min_row, max_row) &&
    in_range(pixle.axes[0], min_col, max_col);
}
*/
u_int abs_val(int x, int y){
  x -= y;
  x = (x < 0) ? -x : x;
  return x;
}

int ab_hourglass_check(const ab_hourglass *hourglass, const Vec2 *center_pos, const Vec2 *pixel){
  char is_even = (hourglass->half_size.axes[0] % 2 == 0) ? 1 : 0;
  int center_width = (hourglass->half_size.axes[0]) + is_even;
  int offset = ((2 * hourglass->half_size.axes[0]) - center_width) / 2;

  int abs_val_x = abs_val(pixel->axes[0], center_pos->axes[0]);
  int abs_val_y = abs_val(pixel->axes[1], center_pos->axes[1]);

  if (abs_val_x <= (hourglass->half_size.axes[0] + hourglass->base_offset) &&
      abs_val_y > hourglass->half_size.axes[1] &&
      abs_val_y <= (hourglass->half_size.axes[1] + hourglass->base_offset)) {
    return 1;
  }
  if (abs_val_x > hourglass->half_size.axes[0] ||
      abs_val_y > hourglass->half_size.axes[1]) {
    return 0;
  }
  if (abs_val_y <= offset) {
    
    return (abs_val_x - (center_width/2)) <= abs_val_y;
  }
  return 1;
}




/*
// true if pixel is in rect centerPosed at rectPos
int 
abRectCheck(const AbRect *rect, const Vec2 *centerPos, const Vec2 *pixel)
{
  Region bounds;
  abRectGetBounds(rect, centerPos, &bounds);
  int within = 1, axis;
  for (axis = 0; axis < 2; axis ++) {
    int p = pixel->axes[axis];
    if (p > bounds.botRight.axes[axis] || p < bounds.topLeft.axes[axis])
      within = 0;
  }
  return within;
}

// compute bounding box in screen coordinates for rect at centerPos




// true if pixel is in rect centerPosed at rectPos
int 
abRectOutlineCheck(const AbRectOutline *rect, const Vec2 *centerPos, const Vec2 *pixel)
{
  Region bounds;
  abRectOutlineGetBounds(rect, centerPos, &bounds);
  int col = pixel->axes[0], row = pixel->axes[1];
  return (
	  ((col == bounds.topLeft.axes[0] || col == bounds.botRight.axes[0])
	   && 
	   (row >= bounds.topLeft.axes[1] && row <= bounds.botRight.axes[1]))
	  ||
	  ((row == bounds.topLeft.axes[1] || row == bounds.botRight.axes[1])
	   &&
	   (col >= bounds.topLeft.axes[0] && col <= bounds.botRight.axes[0]))
	  );
}
 
// compute bounding box in screen coordinates for rect at centerPos
void abRectOutlineGetBounds(const AbRectOutline *rect, const Vec2 *centerPos, Region *bounds)
{
  vec2Sub(&bounds->topLeft, centerPos, &rect->halfSize);
  vec2Add(&bounds->botRight, centerPos, &rect->halfSize);
}
*/


