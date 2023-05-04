#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "tile.h"
#include "SDL_Plotter.h"

class Block{
    private:
        point loc;
        color shade, borderColor;
        blockType type;
        direction orientation;
        direction previousOrientation;
        int size = TILE_SIZE;
        bool isCurrentlyMoving;

    public:
        Block();
        tile tileArray[NUM_TILES];
        Mix_Chunk * gameover = Mix_LoadWAV("gameover.wav");

        point getLocation() const;
        color getColor();
        int getSize() const;

        bool isItMoving() const;

        void setLocation(const point&);
        void setColor(const color&);
        void setSize(int);
        void setBorderColor(color);

        void setType(blockType);
        void switchType();
        void update(SDL_Plotter& g);
        void checkForTileBelow(tile board[][COL], int);
        void checkForFloorBelow();

        bool checkForTileUnder(tile board[][COL], int);
        bool checkForTileLeft(tile board[][COL], int);
        bool checkForTileRight(tile board[][COL], int);

        void stopMoving();
        void startMoving();

        void draw(SDL_Plotter& g);
        void move(int);
        void moveLeft();
        void moveRight();
        void moveDown();
        void rotate(tile board[][COL], int);

        void setRandType();

        bool validPosition(tile board[][COL], int);

        bool checkForEndGame();

};

#endif // BLOCK_H_INCLUDED
