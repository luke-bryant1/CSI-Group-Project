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
                        cout << "You're trash" << endl;
                        game.endGame(g);
                        g.update();
                    }
                }
            }
        }
    }
}


