#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "tile.h"

class Block{
    private:
        tile data[NUM_TILES];
        point loc;
        color shade;
        blockType type;
        int size;

    public:
        Block();

        point getLocation() const;
        color getColor() const;
        int getSize() const;

        void setLocation(const point&);
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


};

#endif // BLOCK_H_INCLUDED
