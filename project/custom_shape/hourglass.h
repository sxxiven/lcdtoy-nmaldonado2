typedef struct ab_hourglass_s {
  void (*getBounds)(const struct ab_hourglass_s *hourglass, const Vec2 *centerPos, Region *bounds);
  int (*check)(const struct ab_hourglass_s *shape, const Vec2 *centerPos, const Vec2 *pixel);
  const Vec2 half_size;
  const u_char base_offset;
} ab_hourglass;



void ab_hourglass_get_bounds(const ab_hourglass *hourglass, const Vec2 *center_pos, Region *bounds);
int ab_hourglass_check(const ab_hourglass *hourglass, const Vec2 *center_pos, const Vec2 *pixel);
