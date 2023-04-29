#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"
#include "tile.h"
#include "block.h"


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

};




#endif // TETRIS_H_INCLUDED
