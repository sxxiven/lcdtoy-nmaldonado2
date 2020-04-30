// Nichole Maldonado
// Header file for hourglass.c which
// defines my own rendition of an abstract shape
// represented as a hourglass.

// _______
// ------- <----- halfsize (from bottom of base to center)
//  |   |
//  \   /
//   ---   <---- center
//  /   \
//  |   |
// -------
// ------- <-----base_offset (height of hourglass rin.)

typedef struct ab_hourglass_s {
  void (*getBounds)(const struct ab_hourglass_s *hourglass, const Vec2 *centerPos, Region *bounds);
  int (*check)(const struct ab_hourglass_s *shape, const Vec2 *centerPos, const Vec2 *pixel);
  const Vec2 half_size;
  const u_char base_offset;
} ab_hourglass;

// Gets bounds of hourglass.
void ab_hourglass_get_bounds(const ab_hourglass *hourglass, const Vec2 *center_pos, Region *bounds);

// Checks if pixel is in or outside of the hourglass.
int ab_hourglass_check(const ab_hourglass *hourglass, const Vec2 *center_pos, const Vec2 *pixel);
