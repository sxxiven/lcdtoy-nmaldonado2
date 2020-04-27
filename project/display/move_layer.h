#include "move_layer_struct.h"

extern u_int bgColor;
extern u_char redrawScreen;
extern Region fieldFence;

/** Moving Layer
 *  Linked list of layer references
 *  Velocity represents one iteration of change (direction & magnitude)
 */
/*
typedef struct MovLayer_s {
  Layer *layer;
  Vec2 velocity;
  struct MovLayer_s *next;
} MovLayer;
*/

void movLayerDraw(MovLayer *movLayers, Layer *layers);

void mlAdvance(MovLayer *ml, Region *fence);
