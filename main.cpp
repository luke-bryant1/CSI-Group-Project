#include <iostream>
#include "tetris.h"

using namespace std;

int init = SDL_Init(SDL_INIT_EVERYTHING);
int init2 = Mix_Init(0);

int main(int argc, char ** argv){
    char key;
    srand(time(0));

    SDL_Plotter g(NUM_ROW,NUM_COL);
    Tetris game;

    while(!g.getQuit()){
        game.startScreen(g);
        g.update();
        if(g.kbhit()){
            key = g.getKey();
            if(key == ' '){
                game.eraseStartScreen(g);
                game.setBoard(g);
                game.drawRightBoard(g);
                if(game.runTetris(g)){
                   cout << "You're trash" << endl;
                }
            }
        }
    }
}


