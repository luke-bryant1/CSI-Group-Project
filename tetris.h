#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED


#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>

#include "SDL_Plotter.h"
#include "constants.h"
#include "tile.h"
#include "block.h"
#include "font.h"

using namespace std;

class Tetris{
    private:
        tile board[ROW][COL];
        Block currentBlock;

    public:

        void setBoard(SDL_Plotter& g);
        void runTetris(SDL_Plotter& g);

        void addBlockToBoard(Block);
        void updateBoard(SDL_Plotter& g);

        void checkForFullRow(SDL_Plotter& g);

        void displayStartScreen(SDL_Plotter& g);

};




#endif // TETRIS_H_INCLUDED
