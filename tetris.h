#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"
#include "tile.h"
#include "block.h"


class Tetris{
    private:
        
        
        int line = 0;
        int score = 0;

    public:
        tile board[ROW][COL];
        Block currentBlock;
        void setBoard(SDL_Plotter& g);
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
