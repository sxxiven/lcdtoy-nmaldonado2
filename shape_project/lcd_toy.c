/** \file shapemotion.c
 *  \brief This is a simple shape motion demo.
 *  This demo creates two layers containing shapes.
 *  One layer contains a rectangle and the other a circle.
 *  While the CPU is running the green LED is on, and
 *  when the screen does not need to be redrawn the CPU
 *  is turned off along with the green LED.
 */  
#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>

#define GREEN_LED BIT6


AbRect ship_1_layer_1 = {abRectGetBounds, abRectCheck, {6,6}};
AbRect ship_2_layer_1 = {abRectGetBounds, abRectCheck, {6,6}};
AbRect ship_3_layer_1 = {abRectGetBounds, abRectCheck, {6,6}};
AbRect ship_4_layer_1 = {abRectGetBounds, abRectCheck, {6,6}};
AbRect ship_5_layer_1 = {abRectGetBounds, abRectCheck, {6,6}};
AbRect person_body = {abRectGetBounds, abRectCheck, {6,3}};
AbRArrow rightArrow = {abRArrowGetBounds, abRArrowCheck, 30};

AbRectOutline fieldOutline = {	/* playing field */
  abRectOutlineGetBounds, abRectOutlineCheck,   
  {screenWidth/2 -2, screenHeight/2 - 2}
};



/*
Layer layer4 = {
  (AbShape *)&rightArrow,
  {(screenWidth/2)+10, (screenHeight/2)+5}, //< bit below & right of center 
  {0,0}, {0,0},				    //last & next pos 
  COLOR_PINK,
  0
};
  

Layer layer3 = {		///< Layer with an orange circle 
  (AbShape *)&circle8,
  {(screenWidth/2)+10, (screenHeight/2)+5}, //< bit below & right of center 
  {0,0}, {0,0},				    // last & next pos 
  COLOR_VIOLET,
  &layer4,
};


Layer fieldLayer = {		// playing field as a layer 
  (AbShape *) &fieldOutline,
  {screenWidth/2, screenHeight/2},//< center 
  {0,0}, {0,0},				    // last & next pos 
  COLOR_BLACK,
  &layer3
};

Layer layer1 = {		//< Layer with a red square 
  (AbShape *)&rect10,
  {screenWidth/2, screenHeight/2}, //< center 
{0,0}, {0,0},				    //last & next pos 
  COLOR_RED,
  &fieldLayer,
};

Layer layer0 = {		//< Layer with an orange circle 
  (AbShape *)&circle14,
  {(screenWidth/2)+10, (screenHeight/2)+5}, //< bit below & right of center 
  {0,0}, {0,0},				    // last & next pos 
  COLOR_ORANGE,
  &layer1,
};
*/

Layer fieldLayer = {		// playing field as a layer 
  (AbShape *) &fieldOutline,
  {screenWidth/2, screenHeight/2},//< center 
  {0,0}, {0,0},				    // last & next pos 
  COLOR_BLACK,
  0
};

Layer layer1_ship3 = {		//< Layer with a red square 
  (AbShape *)&ship_3_layer_1,
  {screenWidth, screenHeight/2}, //< center 
  {0,0}, {0,0},				    //last & next pos 
  COLOR_RED,
  &fieldLayer
};

Layer layer1_ship2 = {		//< Layer with a red square 
  (AbShape *)&ship_2_layer_1,
  {screenWidth + 30, screenHeight/2}, //< center 
  {0,0}, {0,0},				    //last & next pos 
  COLOR_RED,
  &layer1_ship3
};
Layer layer1_ship1 = {		//< Layer with a red square 
  (AbShape *)&ship_1_layer_1,
  {(screenWidth/2) - 30, screenHeight/2}, //< center 
  {0,0}, {0,0},				    //last & next pos 
  COLOR_RED,
  &layer1_ship2
};

Layer layer_person_body = {
  (AbShape *)&person_body,
  {screenWidth/2, screenHeight - 8},
  {0,0},{0,0},
  COLOR_GREEN,
  &layer1_ship1
};

/** Moving Layer
 *  Linked list of layer references
 *  Velocity represents one iteration of change (direction & magnitude)
 */
typedef struct MovLayer_s {
  Layer *layer;
  Vec2 velocity;
  struct MovLayer_s *next;
} MovLayer;

/* initial value of {0,0} will be overwritten */
//MovLayer ml3 = { &layer3, {1,0}, 0 }; /**< not all layers move */
//MovLayer ml1 = { &layer1, {1,0}, &ml3 };
MovLayer ml3 = {&layer1_ship3, {-2,0}, 0};
MovLayer ml2 = { &layer1_ship2, {-2,0}, &ml3};
MovLayer ml1 = { &layer1_ship1, {-2,0}, &ml2};
MovLayer mvl_person_body = { &layer_person_body, {0,0}, &ml1};

void movLayerDraw(MovLayer *movLayers, Layer *layers)
{
  int row, col;
  MovLayer *movLayer;

  and_sr(~8);			/**< disable interrupts (GIE off) */
  for (movLayer = movLayers; movLayer; movLayer = movLayer->next) { /* for each moving layer */
    Layer *l = movLayer->layer;
    l->posLast = l->pos;
    l->pos = l->posNext;
  }
  or_sr(8);			/**< disable interrupts (GIE on) */


  for (movLayer = movLayers; movLayer; movLayer = movLayer->next) { /* for each moving layer */
    Region bounds;
    layerGetBounds(movLayer->layer, &bounds);
    /*Region shape_boundary;
    abShapeGetBounds(movLayer->layer->abShape, &(movLayer->layer->posNext), &shape_boundary);
    */
    
    /* if ((bounds.botRight.axes[0] >= 0 && bounds.topLeft.axes[0] <= screenWidth) || (bounds.topLeft.axes[0] <= screenWidth && bounds.botRight.axes[0] >= 2)) {
      
    if (bounds.topLeft.axes[0] < 0) {
      bounds.topLeft.axes[0] = 0;
      }*/
   

      
      lcd_setArea(bounds.topLeft.axes[0], bounds.topLeft.axes[1], 
		bounds.botRight.axes[0], bounds.botRight.axes[1]);
      for (row = bounds.topLeft.axes[1]; row <= bounds.botRight.axes[1]; row++) {
	for (col = bounds.topLeft.axes[0]; col <= bounds.botRight.axes[0]; col++) {
	  Vec2 pixelPos = {col, row};
	  u_int color = bgColor;
	  Layer *probeLayer;
	  for (probeLayer = layers; probeLayer; 
	     probeLayer = probeLayer->next) { // probe all layers, in order 
	    if (abShapeCheck(probeLayer->abShape, &probeLayer->pos, &pixelPos)) {
	      color = probeLayer->color;
	      break; 
	    } // if probe check 
	  } // for checking all layers at col, row
	  lcd_writeColor(color); 
	} // for col
      } // for row
    } // for moving layer being updated
  // }
}

void check_person_out_of_bounds(MovLayer *ml, Region *shapeBoundary, Region *fence, Vec2 *newPos, u_char axis) {
  if (ml->velocity.axes[0] == 0 && ml->velocity.axes[1] == 0) {
    if (shapeBoundary->topLeft.axes[axis] < fence->topLeft.axes[axis]) {
	  newPos->axes[axis] = fence->topLeft.axes[axis] + 6;
    }
						     if (shapeBoundary->botRight.axes[axis] > fence->botRight.axes[axis]) {
      newPos->axes[axis] = fence->botRight.axes[axis] - 6;
						     }
  }  
}

void copy_regions(Region *dest_region, Region *src_region) {
  dest_region->topLeft.axes[0] = src_region->topLeft.axes[0];
  dest_region->topLeft.axes[1] = src_region->topLeft.axes[1];
  dest_region->botRight.axes[0] = src_region->botRight.axes[0];
  dest_region->botRight.axes[1] = src_region->botRight.axes[1];
}

void move_person_beginning() {
  layer_person_body.posNext.axes[0] = screenWidth/2;
  layer_person_body.posNext.axes[1] = screenHeight - 8;
}

u_char intersection_regions(Region *first_region, Region* second_region) {
  Region region_union;
  regionUnion(&region_union, first_region, second_region);
  u_char width= (first_region->botRight.axes[0] - first_region->topLeft.axes[0]);
  width += (second_region->botRight.axes[0] - second_region->topLeft.axes[0]);
  u_char height = (first_region->botRight.axes[1] - first_region->topLeft.axes[1]);
  height += (second_region->botRight.axes[1] - second_region->topLeft.axes[1]);

  u_char region_width = region_union.botRight.axes[0] - region_union.topLeft.axes[0];
  u_char region_height = region_union.botRight.axes[1] - region_union.topLeft.axes[1];
  
  // if region_union width is less than width 1 + 2, and region_union height is less than height 1 + 2,
  //return false
  if (region_width < width && region_height < height) {
    return 1;
  }
  return 0;
}


//Region fence = {{10,30}, {SHORT_EDGE_PIXELS-10, LONG_EDGE_PIXELS-10}}; /**< Create a fence region */

/** Advances a moving shape within a fence
 *  
 *  \param ml The moving shape to be advanced
 *  \param fence The region which will serve as a boundary for ml
 */
void mlAdvance(MovLayer *ml, Region *fence)
{
  static char tick = 0;
  static char tick2 = 5;
  Vec2 newPos;
  u_char axis;
  Region shapeBoundary;
  tick = (tick + 2) % 10;

  Region person_boundary;
  u_char found_person = 0;
  
  for (; ml; ml = ml->next) {

    // Adds velocity to next pos.
    //newPos axis[0] = posNext->axis[0] + velocity->axis[0]
    //newPos axis[1] = posNext->axis[1] +vel->axis[1]
    vec2Add(&newPos, &ml->layer->posNext, &ml->velocity);
    
    abShapeGetBounds(ml->layer->abShape, &newPos, &shapeBoundary);
    if (found_person == 0) {
      copy_regions(&person_boundary, &shapeBoundary);
      found_person = 1;
    }
    else {
      if (intersection_regions(&person_boundary, &shapeBoundary)) {
	move_person_beginning();
      }
    }
    tick2 = (tick2 + 2) % 10;
    for (axis = 0; axis < 2; axis ++) {

      // check out of bounds.
      check_person_out_of_bounds(ml, &shapeBoundary, fence, &newPos, axis);
      
      if (ml->velocity.axes[axis] == -2 && shapeBoundary.botRight.axes[axis] < 0) {
	if (tick == 4 || tick == 9) {
	  newPos.axes[axis] -= (tick + tick2);
	}
       
      }
      if (ml->velocity.axes[axis] == -2 && shapeBoundary.botRight.axes[axis] <= -100) {
	newPos.axes[axis] = screenWidth - 10;
      }
      
      /**< if outside of fence */

    } /**< for axis */
 
    ml->layer->posNext = newPos;
  } /**< for ml */
}


u_int bgColor = COLOR_BLUE;     /**< The background color */
int redrawScreen = 1;           /**< Boolean for whether screen needs to be redrawn */

Region fieldFence;		/**< fence around playing field  */


/** Initializes everything, enables interrupts and green LED, 
 *  and handles the rendering for the screen
 */
void main()
{
  //P1DIR |= GREEN_LED;		/**< Green led on when CPU on */		
  //P1OUT |= GREEN_LED;

  configureClocks();
  lcd_init();
  shapeInit();
  p2sw_init(15);

  shapeInit();
  layerInit(&layer_person_body);
  layerDraw(&layer_person_body);


  layerGetBounds(&fieldLayer, &fieldFence);


  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */

  
  for(;;) { 
    while (!redrawScreen) { //< Pause CPU if screen doesn't need updating 
      //P1OUT &= ~GREEN_LED;    //< Green led off witHo CPU 
      or_sr(0x10);	      //< CPU OFF 
    }
    // P1OUT |= GREEN_LED;       //< Green led on when CPU on 
    redrawScreen = 0;
    movLayerDraw(&mvl_person_body, &layer_person_body);
  }
}

/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  static short count = 0;
  //P1OUT |= GREEN_LED;		      /**< Green LED on when cpu on */
  count ++;
  if (count >= 16) {
    
    char btns_pressed = p2sw_read();

    
    switch (btns_pressed & 15) {
      //Go up
    case 14:
      P2DIR |= GREEN_LED;
      mvl_person_body.layer->posNext.axes[1] -= 2;
      break;

      //Go down, btn4 pressed
    case 7:
      mvl_person_body.layer->posNext.axes[1] += 2;
      break;

      // Go left, btn3
    case 13:
      mvl_person_body.layer->posNext.axes[0] -= 2;
      break;

      // Go right
    case 11:
      mvl_person_body.layer->posNext.axes[0] += 2;
      break;
    }
    
    mlAdvance(&mvl_person_body, &fieldFence);
    
    if (p2sw_read())
      redrawScreen = 1;
    count = 0;
  } 
  // P1OUT &= ~GREEN_LED;		    /**< Green LED off when cpu off */
}
