#include <iostream>
#include "tetris.h"

using namespace std;

int main(int argc, char ** argv){
    SDL_Plotter g(NUM_ROW,NUM_COL);
    Tetris game;

    while(!g.getQuit()){
        game.startScreen(g);
        g.update();

        if(g.kbhit()){
            game.eraseStartScreen(g);

            game.setBoard(g);

            game.drawRightBoard(g);

            game.runTetris(g);
        }
    }
}


