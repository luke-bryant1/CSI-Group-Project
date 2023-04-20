#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "tile.h"

class Block{
    private:
        tile tileArray[NUM_TILES];
        point loc;
        color shade;
        blockType type;
        direction orientation;
        int size;
        bool isCurrentlyMoving;
        bool isOnScreen;

    public:
        Block();

        point getLocation() const;
        color getColor() const;
        int getSize() const;

        bool isMoving() const;

        void setLocation(const point&);
        void setOriginalX();
        void setOriginalY();
        void setColor(const color&);
        void setSize(int);
        void setType(blockType);
        void switchType();
        void update(SDL_Plotter& g);

        void draw(SDL_Plotter& g);
        void move();
        void moveLeft();
        void moveRight();
        void moveDown();
        void rotate(); // This rotates blocks *clockwise*
        bool isTouching(Block[], int, int) const;
        void stopMoving();
        void stopIfHitBottom();


};

#endif // BLOCK_H_INCLUDED
