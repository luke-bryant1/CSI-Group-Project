#include <iostream>
#include "tetris.h"

using namespace std;

int init = SDL_Init(SDL_INIT_EVERYTHING);
int init2 = Mix_Init(0);

int main(int argc, char ** argv){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music * music = Mix_LoadMUS("font\\Tetris.mp3");

    Mix_PlayMusic(music, -1);
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


