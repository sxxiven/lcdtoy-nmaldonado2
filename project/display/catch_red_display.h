// Nichole Maldonado
// Header for the catch red display that
// displays balls that can change foreground
// and background colors.

#include "move_layer.h"
#include "shape.h"

extern MovLayer ml_ball_1;
extern Layer layer_ball_1;

// Advances the current layer.
void catch_red_display(char btn_pressed);

// Displays a new instance of the game.
void display_new_catch_red();

// Alternate ball colors between red and green.
void change_ball_color();

