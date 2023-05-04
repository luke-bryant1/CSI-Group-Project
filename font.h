 /*
This file holds the declarations for both the letter and Font classes. We use these
functions to open up each letter file, create the array for that letter,and display
strings and characters to the display. We can change the size of the Font,the color of
the displayed letters, and the location of the letters.
*/

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
         * precondition: letter and plotter exists
         * postcondition: the letter will be drawn onto the plotter in a given location
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
        /*
         * description: opens all of the files for all of the characters and numbers
         *              and initializes them by calling the letter function init(). It
         *              also sets the original location at (0,0) and size of the font
         * return: none
         * precondition: letter function init() exists
         * postcondition:
         *
        */
        Font();

        /*
         * description: sets the location of the font to the point given
         * return: void
         * precondition: the font exists
         * postcondition: the location of the font will be updated to the point inputted
         *
        */
        void setLoc(point);

        /*
         * description: sets the size of the font to the int inputted
         * return: void
         * precondition: size must be greater than or equal to 1
         * postcondition: the new size of the font will be updated to the int inputted
         *
        */
        void setSize(int);

        /*
         * description: displays the inputted character to the chosen ostream with the
         *              default ostream of cout
         * return: void
         * precondition: character is a capital letter or number
         * postcondition: character will be displayed to ostream
         *
        */
        void display(char, ostream& out = cout);

        /*
         * description: draws the character inputted with a chosen
         *              color by calling the function for drawing a letter
         * return: void
         * precondition: draw function for letter exists and plotter exists
         * postcondition: displays the character onto the plotter
         *
        */
        void draw(char, SDL_Plotter& g, color = BLACK);

        /*
         * description: draws the string inputted with a chosen
         *              color by calling the function for drawing
         *              a single character multiple times
         * return: void
         * precondition: draw function for letter exists and draw function for
         *               font exists and plotter exists
         * postcondition: displays the string onto the plotter with chosen color
         *
        */
        void draw(string, SDL_Plotter& g, color = BLACK);

};

#endif // FONT_H_INCLUDED
