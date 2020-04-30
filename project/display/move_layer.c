// Provided by the Instructor.
// File that contains methods to
// move the shapes and advance them.

#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"
#include "move_layer.h"

u_int bg_color = COLOR_GREEN;
u_char redraw_screen = 1;
Region field_ence;

// Playing field
AbRectOutline field_outline = {
abRectOutlineGetBounds, abRectOutlineCheck,   
{screenWidth/2 - 5, screenHeight/2 - 5}
};

Layer field_layer = {
  (AbShape *)&field_outline,
  {(screenWidth/2), (screenHeight/2)},
  {0,0}, {0,0},				   
  COLOR_BLACK,
  0
};

/*
 * Function that draws the shape movement.
 * Input: the movLayers to move and their
 *        corresponding layers.
 * Output: None.
 */
void mov_layer_sraw(MovLayer *mov_layers, Layer *layers)
{
  int row, col;
  MovLayer *mov_layer;

  and_sr(~8);			/**< disable interrupts (GIE off) */
  for (mov_layer = mov_layers; mov_layer; mov_layer = mov_layer->next) { /* for each moving layer */
    Layer *l = mov_layer->layer;
    l->posLast = l->pos;
    l->pos = l->posNext;
  }
  or_sr(8);		 
  for (mov_layer = mov_layers; mov_layer; mov_layer = mov_layer->next) { /* for each moving layer */
    Region bounds;
    layerGetBounds(mov_layer->layer, &bounds);
    lcd_setArea(bounds.topLeft.axes[0], bounds.topLeft.axes[1], 
		bounds.botRight.axes[0], bounds.botRight.axes[1]);
    for (row = bounds.topLeft.axes[1]; row <= bounds.botRight.axes[1]; row++) {
      for (col = bounds.topLeft.axes[0]; col <= bounds.botRight.axes[0]; col++) {
	Vec2 pixel_pos = {col, row};
	u_int color = bgColor;
	Layer *probe_layer;
	for (probe_layer = layers; probe_layer; 
	     probe_layer = probe_layer->next) { /* probe all layers, in order */
	  if (abShapeCheck(probe_layer->abShape, &probe_layer->pos, &pixel_pos)) {
	    color = probe_layer->color;
	    break; 
	  } /* if probe check */
	} // for checking all layers at col, row
	lcd_writeColor(color); 
      } // for col
    } // for row
  } // for moving layer being updated
}	  

/** Advances a moving shape within a fence
 *  
 *  \param ml The moving shape to be advanced
 *  \param fence The region which will serve as a boundary for ml
 */
void ml_advance(MovLayer *ml, Region *fence)
{
  Vec2 new_pos;
  u_char axis;
  Region shape_boundary;
  for (; ml; ml = ml->next) {
    vec2Add(&new_pos, &ml->layer->posNext, &ml->velocity);
    abShapeGetBounds(ml->layer->abShape, &new_pos, &shape_boundary);
    for (axis = 0; axis < 2; axis ++) {
      if ((shape_boundary.topLeft.axes[axis] < fence->topLeft.axes[axis]) ||
	  (shape_boundary.botRight.axes[axis] > fence->botRight.axes[axis]) || shape_boundary.topLeft.axes[axis] < 5) {
	int velocity = ml->velocity.axes[axis] = -ml->velocity.axes[axis];
	new_pos.axes[axis] += (2*velocity);
      }	/**< if outside of fence */
     
    } /**< for axis */
    ml->layer->posNext = new_pos;
  } /**< for ml */
}
