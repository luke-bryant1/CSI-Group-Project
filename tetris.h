#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"
#include "tile.h"
#include "block.h"
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>

#include "font.h"
using namespace std;


class Tetris{
    private:
        tile blankTile;
        int line = 0;
        int score = 0;

    public:
        tile board[ROW][COL];
        tile rightBoard[ROW][COL];
        tile fullScreen[ROW][COL*2];
        Block currentBlock;

        void startScreen(SDL_Plotter& g);
        void eraseStartScreen(SDL_Plotter& g);


        void setBoard(SDL_Plotter& g);
        void grid(SDL_Plotter& g);

        void drawRightBoard(SDL_Plotter& g);
        void runTetris(SDL_Plotter& g);

        void addBlockToBoard(Block);
        void updateBoard(SDL_Plotter& g);

        void checkForFullRow(SDL_Plotter& g);

        void setLine(int);
        int getLine();

        void setScore(int);
        int getScore();

};




#endif // TETRIS_H_INCLUDED
