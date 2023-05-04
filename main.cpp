#include <iostream>
#include "tetris.h"

using namespace std;

int main(int argc, char ** argv){
    char key;
    srand(time(0));

    SDL_Plotter g(NUM_ROW,NUM_COL);
    Tetris game;

    game.startScreen(g);
    g.update();
    while(!g.getQuit()){
        game.startScreen(g);
        g.update();
        while(!g.getQuit()){

            if(g.kbhit()){
                key = g.getKey();
                if(key == ' '){
                    game.eraseStartScreen(g);
                    game.setBoard(g);
                    game.drawRightBoard(g);
                    if(game.runTetris(g)){
                        game.endGame(g);
                        g.update();
                        game.setNewScore(0);
                        game.setNewLineTotal(0);
                    }
                }
            }

        }
    }
}


