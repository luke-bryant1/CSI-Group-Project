#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include "tile.h"
#include "SDL_Plotter.h"

class Block{

    private:
        tile data[NUM_TILES];
        point loc;
        color shade;
        blockType type;

    public:
        Block();


};

#endif // BLOCK_H_INCLUDED
