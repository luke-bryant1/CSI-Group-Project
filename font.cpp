/*
 Authors: Luke Bryant, Bella Henslee, Samuel Choi, Raphe Prince
 Assignment Title: Final Project - Tetris
 Assignment Description: Create a Tetris Game
 Due Date: 5/4/2023
 Date Created: 4/15/2023
 Date Modified: 5/4/2023
 */

#include "font.h"

void letter::init(string fname){
    //open file to get data for letter
    ifstream input;
    input.open(fname);
    assert(input);

    //this gets the size of the letter in the array and builds the array
    input >> row >> col;
    for(int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            input >> data[r][c];
        }
    }
    input.close();
}

void letter::display(ostream& out){
    //this outputs the letter to the chosen ostream
    //(not onto the plotter)
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(data[r][c]== '1'){
                out << data[r][c];
            }
            else{
                out << ' ';
            }
        }
         out << endl;
    }
}

void letter::draw(int n, point p, SDL_Plotter& g, color letterColor){
    //plot the letter onto the plotter based on the size, location, and color chosen
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(data[r][c] == '1'){
                for(int xOff = 0; xOff < n; xOff++){
                    for(int yOff = 0; yOff < n; yOff++){
                        g.plotPixel(xOff + p.x + c * n, yOff + p.y + r * n,letterColor);
                    }
                }
            }
        }
    }
}

Font::Font(){
    //open the files and initialize the letters
    string fname;
    for(char c = 'A'; c <= 'Z'; c++){
        fname = "font\\";
        fname += c;
        fname += ".txt";
        data[c].init(fname);
    }
    //do the same for the each number
    for(char c = '0'; c <= '9'; c++){
        fname = "font\\";
        fname += c;
        fname += ".txt";
        data[c].init(fname);
    }
    //set the initial location of the letters to (0,0) and size as 1
    loc.x = 0;
    loc.y = 0;
    size = 1;
}

void Font::setLoc(point p){
    //sets the location of the font to p
    loc = p;
}

void Font::setSize(int n){
    //sets the size of the font only if it is greater than or equal to 1
    if(n >= 1){
        size = n;
    }
}

void Font::display(char c, ostream& out){
    //displays the character to the ostream chosen
    data[c].display(out);
}

void Font::draw(char c, SDL_Plotter& g, color shade){
    //calls the draw function for the character c
    data[c].draw(size,loc, g, shade);
}

void Font::draw(string word, SDL_Plotter& g, color shade){
    //calls the draw function for each letter in the inputted string
    for(int i = 0; i < word.size(); i++){
        draw(word.at(i), g, shade);
        loc.x += size * 9;
    }
}

