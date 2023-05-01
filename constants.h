#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int COL = 10; //these are the number of cells for our board
const int ROW = 25;

const int NUM_TILES     = 4;
const int TILE_SIZE     = 25;
const int NUM_ROW = TILE_SIZE * ROW;
const int NUM_COL = TILE_SIZE * COL * 2;

const int STARTING_X    = TILE_SIZE * 4;
const int STARTING_Y    = TILE_SIZE - 100;

const point START_POINT(STARTING_X, STARTING_Y);

const int SPEED = 150; //This controls the speed that the block falls (the higher the number the slower)

const color RED        = color(255, 0, 0);
const color ORANGE     = color(255, 165, 0);
const color YELLOW     = color(255, 255, 0);
const color GREEN      = color(0, 255, 0);
const color CYAN       = color(0, 255, 255);
const color BLUE       = color(0, 0, 255);
const color PURPLE     = color(128, 0, 128);
const color BLACK      = color(0, 0, 0);
const color LIGHTGRAY  = color(170, 170, 170);
const color BACKGROUND = color(127, 127, 127);
const color ERASE      = color(255, 255, 255);
const color NAVY       = color(32,42,68);

const int MAX_FONT_SIZE = 25;

enum blockType {bar, square, l_shape, l_shape_opp, t_shape, z_shape, z_shape_opp};
enum direction {north, east, south, west};



#endif // CONSTANTS_H_INCLUDED
