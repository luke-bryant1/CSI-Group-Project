#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int NUM_ROW = 500;
const int NUM_COL = 400;

const int NUM_TILES = 4;
const int TILE_SIZE = 20;

const int SPEED = 150; //This controls the speed that the block falls (the higher the number the slower)

const color RED   = color(220, 20, 20);
const color ORANGE   = color(255, 165, 0);
const color YELLOW   = color(220, 250, 0);
const color GREEN   = color(20, 220, 20);
const color BLUE   = color(20, 20, 220);
const color BLACK = color(0, 0, 0);
const color BACKGROUND = color(255, 255, 255);

enum blockType {bar, square, l_shape, t_shape, z_shape};
enum direction {north, east, south, west};


#endif // CONSTANTS_H_INCLUDED
