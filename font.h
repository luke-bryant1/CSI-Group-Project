#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include "tetris.h"
#include "SDL_Plotter.h"

class letter{
    private:
        int row = 0, col = 0;
        char data[MAX_FONT_SIZE][MAX_FONT_SIZE];

    public:
        letter(){;}
        void init (string );

        void display(ostream& );

        void draw(int, point, SDL_Plotter&);

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

        void draw(char, SDL_Plotter& g);

        void draw(string, SDL_Plotter& g);




};

#endif // FONT_H_INCLUDED
