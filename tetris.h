#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"
#include "tile.h"
#include "block.h"
#include "font.h"
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class Tetris{
    private:
        tile blankTile;
        int line = 0;
        int score = 0;

    public:
        int level = 1;
        tile board[ROW][COL];
        tile rightBoard[ROW][COL];
        tile fullScreen[ROW][COL*2];
        Block currentBlock;

        void startScreen(SDL_Plotter& g);
        void eraseStartScreen(SDL_Plotter& g);

        void setBoard(SDL_Plotter& g);
        void grid(SDL_Plotter& g);

        void drawRightBoard(SDL_Plotter& g);
        bool runTetris(SDL_Plotter& g);

        void addBlockToBoard(Block);
        void updateBoard(SDL_Plotter& g);

        void checkForFullRow(SDL_Plotter& g);

        void setLine(int);
        int getLine();

        void setScore(int);
        int getScore();
        void endGame(SDL_Plotter& g);

        void drawScore(point p, SDL_Plotter& g, int, int size);
        void eraseScore(point p, SDL_Plotter& g);

        void setNewScore(int n);
        void setNewLineTotal(int n);
        void resetLevel();
};




#endif // TETRIS_H_INCLUDED
