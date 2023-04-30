#include <iostream>
#include "tetris.h"

using namespace std;

int main(){
    SDL_Plotter g(NUM_ROW,NUM_COL);
    Tetris game;

    game.setBoard(g);
    game.runTetris(g);
    cout << endl << "******************************" << endl;
    cout << "  NUMBER OF LINES CLEARED: " << game.getLine() << endl;
    cout << "  SCORE: " << game.getScore() << endl;
    cout << "******************************" << endl << endl;
    
    
}

