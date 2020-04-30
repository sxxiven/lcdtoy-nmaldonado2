// Nichole Maldonado
// Code implementation for an abstract
// shape representation of an hourglass.

#include "shape.h"
#include "hourglass.h"

static u_int abs_val(int x, int y);

/*
 * Function that determines the bounds of
 * the hourglass by constructing a rectangle
 * around it based on its halfsize and
 * base offset.
 * Input: The hourglass, center position for the 
 * hourglass, and bounds to be set.
 * Output: None
 */
void ab_hourglass_get_bounds(const ab_hourglass *hourglass, const Vec2 *center_pos, Region *bounds)
{
  // Set topLeft to the top of hourglass.
  vec2Sub(&bounds->topLeft, center_pos, &hourglass->half_size);
  
  // add top of base.
  bounds->topLeft.axes[1] -= hourglass->base_offset;

  // add left side of base (litte ledge).
  bounds->topLeft.axes[0] -= hourglass->base_offset;

  // Set botRight to the bottom of the hourglass.
  vec2Add(&bounds->botRight, center_pos, &hourglass->half_size);

  // add bottom of base.
  bounds->botRight.axes[1] += hourglass->base_offset;

  // add right side of base.
  bounds->botRight.axes[0] += hourglass->base_offset; 
}

/*
 * Gets the absolute value of two integers
 * subtracted.
 * Input:the two integers to be subtracted.
 * Output: None.
 */
static u_int abs_val(int x, int y){
  x -= y;
  x = (x < 0) ? -x : x;
  return x;
}

/*
 * Function that returns true if pixel
 * is in the hourglass or false otherwise.
 * Input: the hourglass, its center position,
 * and the pixel to be evaluated.
 * Output: 1 if pixel is in the hourglass, 0 otherwise.
 */
int ab_hourglass_check(const ab_hourglass *hourglass, const Vec2 *center_pos, const Vec2 *pixel){

  char is_even = (hourglass->half_size.axes[0] % 2 == 0) ? 1 : 0;
  
  // Calculates center width.
  int center_width = (hourglass->half_size.axes[0]) + is_even;

  // Calculates width that doesn't include center.
  int offset = ((2 * hourglass->half_size.axes[0]) - center_width) / 2;
  int abs_val_x = abs_val(pixel->axes[0], center_pos->axes[0]);
  int abs_val_y = abs_val(pixel->axes[1], center_pos->axes[1]);

  //If within the two -------
  //                  |     | return true
  if (abs_val_x <= (hourglass->half_size.axes[0] + hourglass->base_offset) &&
      abs_val_y > hourglass->half_size.axes[1] &&
      abs_val_y <= (hourglass->half_size.axes[1] + hourglass->base_offset)) {
    return 1;
  }

  // If outside of the two rectangles above,
  // return false.
  if (abs_val_x > hourglass->half_size.axes[0] ||
      abs_val_y > hourglass->half_size.axes[1]) {
    return 0;
  }

  // If y is within the offset, return true
  // if it fits in |/ triangle side of hourglass.
  if (abs_val_y <= offset) {
    return (abs_val_x - (center_width/2)) <= abs_val_y;
  }
  return 1;
}
