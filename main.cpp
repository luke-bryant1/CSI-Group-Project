#include <iostream>
#include "tetris.h"

using namespace std;

int main(int argc, char ** argv){
    SDL_Plotter g(NUM_ROW,NUM_COL);
    Tetris game;
    point p;

    letter chr;
    Font text;

//    chr.init("font\\A.txt");
//    text.display('H', cout);

    chr.display(cout);

    p.x = 300;
    p.y = 100;

    text.setLoc(p);
    text.setSize(2);

    text.draw('S', g);
    p.x += 25;
    text.setLoc(p);
    text.draw('C', g);
    p.x += 25;
    text.setLoc(p);
    text.draw('O', g);
    p.x += 25;
    text.setLoc(p);
    text.draw('R', g);
    p.x += 25;
    text.setLoc(p);
    text.draw('E', g);
    p.x += 25;
    text.setLoc(p);


    game.setBoard(g);
    game.runTetris(g);

}

