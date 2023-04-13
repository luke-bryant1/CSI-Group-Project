#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"

class tile{
    private:
        point loc, prevLoc;   //"loc" is for the location
        color shade; // "shade" is for the color
        int size;

    public:
        tile(){
            size = 20;
        }

        point getLocation() const;
        color getColor() const;
        int getSize() const;

        void setLocation(const point&);
        void setColor(const color&);
        void setSize(int);

        void draw(SDL_Plotter& g);
        void move();
        void moveLeft();
        void moveRight();
};

#endif // TILE_H_INCLUDED