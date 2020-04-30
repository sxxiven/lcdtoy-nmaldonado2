// Provided by the instructor.
// Shape move functions provided by
// the instructor.

#ifndef MOVE_LAYER_STRUCT
#define MOVE_LAYER_STRUCT

extern u_int bg_color;
extern u_char redraw_screen;
extern Region field_fence;
extern Layer field_layer;

/** Moving Layer
 *  Linked list of layer references
 *  Velocity represents one iteration of change (direction & magnitude)
 */
typedef struct MovLayer_s {
  Layer *layer;
  Vec2 velocity;
  struct MovLayer_s *next;
} MovLayer;


void mov_layer_draw(MovLayer *movLayers, Layer *layers);

void ml_advance(MovLayer *ml, Region *fence);
#endif
