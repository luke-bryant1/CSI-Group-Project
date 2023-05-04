/*
This file holds all of the constants that are used throughout the project.
It holds the dimensions of the Tetris board, the dimensions of the plotter
window, the dimension of each tile, the starting location of each block,
and the different colors used throughout the project.
*/

#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int COL = 10; //this is the number of columns on the Tetris board
const int ROW = 25; //this is the number of rows on the Tetris board

//this is the number of tiles per block
const int NUM_TILES     = 4;

//this is the length of each tile
const int TILE_SIZE     = 25;

//this is the size of the display screen
const int NUM_ROW = TILE_SIZE * ROW;
const int NUM_COL = TILE_SIZE * COL * 2;

//this is the starting location of every tile
const int STARTING_X    = TILE_SIZE * 4;
const int STARTING_Y    = -2 * TILE_SIZE;
const point START_POINT(STARTING_X, STARTING_Y);

//this controls the refresh rate of the plotter
const int SPEED = 0; //(it is set to zero to maximize the refresh rate)

//this is where the color constants are set
const color RED        = color(255, 0, 0);
const color ORANGE     = color(255, 165, 0);
const color YELLOW     = color(255, 255, 0);
const color GREEN      = color(0, 255, 0);
const color CYAN       = color(0, 255, 255);
const color BLUE       = color(0, 0, 255);
const color PURPLE     = color(154,28,145);
const color BLACK      = color(0, 0, 0);
const color LIGHTGRAY  = color(170, 170, 170);
const color BACKGROUND = color(127, 127, 127);
const color ERASE      = color(255, 255, 255);
const color NAVY       = color(32,42,68);

//this is in place to make sure the size of the font doesn't get too big
const int MAX_FONT_SIZE = 25;

//these are all of the different types of blocks that are used
enum blockType {bar, square, l_shape, l_shape_opp, t_shape, z_shape, z_shape_opp};

//these are all of the different orientations the blocks can have when rotating
enum direction {north, east, south, west};



#endif // CONSTANTS_H_INCLUDED
