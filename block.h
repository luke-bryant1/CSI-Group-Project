#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "tile.h"
#include "SDL_Plotter.h"

class Block{
    private:
        point loc;
        color shade;
        blockType type;
        direction orientation;
        int size = TILE_SIZE;
        bool isCurrentlyMoving;

    public:
        Block();
        tile tileArray[NUM_TILES];

        point getLocation() const;
        color getColor() const;
        int getSize() const;

        bool isItMoving() const;

        void setLocation(const point&);
        void setColor(const color&);
        void setSize(int);

        void setType(blockType);
        void switchType();
        void update(SDL_Plotter& g);
        void checkForTileBelow(tile board[][COL], int);
        void checkForFloorBelow();

        void stopMoving();
        void startMoving();

        void draw(SDL_Plotter& g);
        void move();
        void moveLeft();
        void moveRight();
        void moveDown();
        void rotate(); // This rotates blocks *clockwise*

        void setRandColor();
        void setRandType();
        void setRandOrientation();

};

#endif // BLOCK_H_INCLUDED
