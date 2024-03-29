/*
 Authors: Luke Bryant, Bella Henslee, Samuel Choi, Raphe Prince
 Assignment Title: Final Project - Tetris
 Assignment Description: Create a Tetris Game
 Due Date: 5/4/2023
 Date Created: 4/15/2023
 Date Modified: 5/4/2023

Group Work Distribution:
Luke:
 - Created Plotter Window, Board, Tiles, and Blocks
 - Helped developed collisions, clearing row
 - Debugged (General)
 - Commented Code (General)

Bella:
 - Helped developed collisions, clearing row
 - Displayed text on screen
 - Displayed start game screen
 - Debugged (General)
 - Commented Code (General)

Samuel:
 - Created score, lines, and level
 - Created end game screen
 - Helped developed collisions, clearing row
 - Debugged (General)
 - Commented Code (General)

Raphe:
 - Helped developed collisions, clearing row
 - Wrote the font for all of the numbers and letters used
 - Commented Code (General)
 - Debugged (General)

Douglas:
 - N/A

*/

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
                        game.resetLevel();
                    }
                }
            }

        }
    }
}


