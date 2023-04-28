#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int COL = 10; //these are the number of cells for our board
const int ROW = 15;

const int NUM_TILES     = 4;
const int TILE_SIZE     = 40;
const int NUM_ROW = TILE_SIZE * ROW;
const int NUM_COL = TILE_SIZE * COL;

const int STARTING_X    = TILE_SIZE * 4;
const int STARTING_Y    = TILE_SIZE * 2;

const point START_POINT(STARTING_X, STARTING_Y);

const int SPEED = 750; //This controls the speed that the block falls (the higher the number the slower)

const color RED        = color(220, 20, 20);
const color ORANGE     = color(255, 165, 0);
const color YELLOW     = color(220, 250, 0);
const color GREEN      = color(20, 220, 20);
const color BLUE       = color(20, 20, 220);
const color BLACK      = color(0, 0, 0);
const color BACKGROUND = color(255, 255, 255);

enum blockType {bar, square, l_shape, t_shape, z_shape};
enum direction {north, east, south, west};



#endif // CONSTANTS_H_INCLUDED
