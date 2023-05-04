
// This file holds the declarations for both the letter and Font classes.
// We use these functions to open up each letter file, create the array for that letter,
// and display strings and characters to the display. We can change the size of the Font,
// the color of the displayed letters, and the location of the letters.

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include "tetris.h"
#include "SDL_Plotter.h"

class letter{
    private:
        int row = 0, col = 0;
        char data[MAX_FONT_SIZE][MAX_FONT_SIZE];

    public:
        /*
         * description: letter constructor
         * return: none
         * precondition: none
         * postcondition: constructs the letter
         *
        */
        letter(){;}

        /*
         * description: initializes each letter inputted if letter has a file
         * return: void
         * precondition: inputted file name is a valid file with the proper data
         *               for creating the array for the letter
         * postcondition: constructs each letter if it has a valid file
         *
        */
        void init (string );

        /*
         * description: displays the letter to chosen ostream
         * return: void
         * precondition: ostream is a valid ostream and
         *               letter has proper data to be displayed
         * postcondition: the ostream is availiable to be outputted to
         *
        */
        void display(ostream& );

        /*
         * description: draws the letter on the plotter with default color BLACK
         * return: void
         * precondition: letter exist
         * postcondition:
         *
        */
        void draw(int, point, SDL_Plotter& g, color = BLACK);

};

class Font{
    private:
        letter data[256];
        point loc;
        int size;

    public:
        Font();

        void setLoc(point);

        void setSize(int);

        void display(char, ostream& out = cout);

        void draw(char, SDL_Plotter& g, color = BLACK);

        void draw(string, SDL_Plotter& g, color = BLACK);

};

#endif // FONT_H_INCLUDED
