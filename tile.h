#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"

class tile{
    private:
        point loc, prevLoc;   //"loc" is for the location
        color shade; // "shade" is for the color
        int size;
        bool onTheMove;
        bool isOnScreen;

    public:
        tile(){
            size = TILE_SIZE;
        }

        point getLocation() const;
        color getColor() const;
        int getSize() const;

        void setLocation(const point&);
        void setColor(const color&);
        void setSize(int);
        void update(SDL_Plotter& g);
        bool isTouching(tile&, string);
        bool isOnTheMove();
        void stopMoving();
        void startMoving();

        void draw(SDL_Plotter& g);
        void move();
        void moveLeft();
        void moveRight();
        void moveDown();

        void setIsOnScreen(bool);
        bool getIsOnScreen();
};

#endif // TILE_H_INCLUDED
