#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include "SDL_plotter.h"

const int NUM_ROWS = 800;
const int NUM_COL = 500;

const int NUM_TILES = 4;

const color RED   = color(220, 20, 20);
const color BLACK = color(0, 0, 0);
const color BACKGROUND = color(255, 255, 255);

enum blockType {bar, square, l_shape, t_shape, z_shape};
enum direction {north, east, south, west};



#endif // CONSTANTS_H_INCLUDED
//test
