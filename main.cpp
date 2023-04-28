#include <iostream>
#include "tetris.h"

using namespace std;

int main(int argc, char ** argv){
    SDL_Plotter g(NUM_ROW,NUM_COL);
    Tetris game;

    game.setBoard();
    game.runTetris(g);
}

