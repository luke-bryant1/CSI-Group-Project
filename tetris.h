/*
 Authors: Luke Bryant, Bella Henslee, Samuel Choi, Raphe Prince
 Assignment Title: Final Project - Tetris
 Assignment Description: Create a Tetris Game
 Due Date: 5/4/2023
 Date Created: 4/15/2023
 Date Modified: 5/4/2023

 This file contains the Tetris class that is the main hub for running
 our program. This class holds the function declarations for the functions
 that draw the left and right board, the grid, the title screen, and the
 game over screen. It also holds the function declarations for keeping track
 of the score, lines cleared, and level along with the check for full row function.
 The Tetris class is also where all of the functions are that allow you to play the
 game again after losing.
 */

#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"
#include "tile.h"
#include "block.h"
#include "font.h"
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

class Tetris{
    private:
        tile blankTile;
        int line = 0;
        int score = 0;

    public:
        int level = 1;
        tile board[ROW][COL];
        tile rightBoard[ROW][COL];
        tile fullScreen[ROW][COL*2];
        Block currentBlock;

        /*
         description: display start screen
         return: void
         precondition: SDL_Plotter is valid
         postcondition: start screen is displayed to the plotter
         */
        void startScreen(SDL_Plotter& g);

        /*
         description:erase the start screen
         return: void
         precondition: SDL_Plotter is valid
         postcondition: the start screen is erased from the plotter
         */
        void eraseStartScreen(SDL_Plotter& g);

        /*
         description: draws Tetris game screen (left side)
         return: void
         precondition: SDL_Plotter is valid
         postcondition: the Tetris game screen is drawn on the plotter
         */
        void setBoard(SDL_Plotter& g);

        /*
         description: draws grid for the Tetris screen
         return: void
         precondition: SDL_Plotter is valid
         postcondition: the grid is drawn for the Tetris game screen
         */
        void grid(SDL_Plotter& g);

        /*
         description: draws right side of game screen
         return: void
         precondition: SDL_Plotter is valid
         postcondition: the right side of the game screen is drawn on the plotter
         */
        void drawRightBoard(SDL_Plotter& g);

        /*
         description: returns true if the game is running
         return: bool
         precondition: SDL_Plotter is valid
         postcondition: returns true if the game is true
         */
        bool runTetris(SDL_Plotter& g);

        /*
         description: displays the Tetris blocks on the screen
         return: void
         precondition: Block function is valid
         postcondition: draws a Tetris block onto the plotter
         */
        void addBlockToBoard(Block);

        /*
         description: refreshes the screen every time the block falls
         return: void
         precondition: SDL_Plotter is valid
         postcondition: refreshes the screen on the plotter
         */
        void updateBoard(SDL_Plotter& g);

        /*
         description: checks if the row is full
         return: void
         precondition: SDL_Plotter is valid
         postcondition: checks if there is a full row on the game screen
         */
        void checkForFullRow(SDL_Plotter& g);

        /*
         description: increases the number of lines cleared
         return: void
         precondition: int is valid
         postcondition: set line += 1
         */
        void setLine(int);

        /*
         description: return the value of line
         return: int
         precondition: getLine is called
         postcondition: the value of line is returned
         */
        int getLine();

        /*
         description: increments the current score
         return: void
         precondition: int is valid
         postcondition: increase score value
         */
        void setScore(int);

        /*
         description: return the current score
         return: int
         precondition: getScore is called
         postcondition: the value of score is returned
         */
        int getScore();

        /*
         description: shows endgame screen
         return: void
         precondition: SDL_Plotter is valid
         postcondition: the endgame screen is drawn on the plotter
         */
        void endGame(SDL_Plotter& g);

        /*
         description: the score is drawn on the right side of the game screen
         return: void
         precondition: SDL_Plotter, point location, and the score value is valid
         postcondition: draws the score on the right side of the screen
         */
        void drawScore(point p, SDL_Plotter& g, int, int size);

        /*
         description: draws a background color tile on top of the score
         return: void
         precondition: SDL_Plotter and point p is valid
         postcondition: score is erased
         */
        void eraseScore(point p, SDL_Plotter& g);

        /*
         description: sets the score of value n
         return: void
         precondition: int n is valid
         postcondition: int n carries the current value of score
         */
        void setNewScore(int n);

        /*
         description: sets the number of lines cleared
         return: void
         precondition: int n is valid
         postcondition: int n carries the current amount of lines cleared
         */
        void setNewLineTotal(int n);

        /*
         description: resets level 1
         return: void
         precondition: function is called
         postcondition: resets level back to 1 after end game
         */
        void resetLevel();
};




#endif // TETRIS_H_INCLUDED
