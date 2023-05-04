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


        /*
        Purpose: Gets block location
        Pre-condition: Block exists and has location
        Post-condition: Point is in (x,y) form
        Returns: point (x,y) location of block corner
        */
        point getLocation() const;


        /*
        Purpose: Gets block color
        Pre-condition: Block exists and has color
        Post-condition: color is constant in constants
        Returns: Color - constant in constants
        */
        color getColor();


        /*
        Purpose: Gets tile size
        Pre-condition: Block exists and has size
        Post-condition: Size is int
        Returns: int Size of tile in block
        */
        int getSize() const;

        /*
        Purpose: Tests if block is moving
        Pre-condition: Block exists and has bool
        Post-condition: bool corresponds to isCurrMov
        Returns: bool isCurrentlyMoving
        */
        bool isItMoving() const;


        /*
        Purpose: Sets Location of block
        Pre-condition: Block exists and has location
        Post-condition: Block set with location at p
        Returns: Void
        */
        void setLocation(const point&);


        /*
        Purpose: Sets color of block
        Pre-condition: Block exists and has color
        Post-condition: Block set with color
        Returns: Void
        */
        void setColor(const color&);


        /*
        Purpose: Sets size of block
        Pre-condition: Block exists and has size
        Post-condition: Block set with size s
        Returns: Void
        */
        void setSize(int s);


        /*
        Purpose: Sets color of block border
        Pre-condition: Block exists and has border color
        Post-condition: Block border set with color
        Returns: Void
        */
        void setBorderColor(color);


        /*
        Purpose: Sets type of block
        Pre-condition: Block exists and has type
        Post-condition: Block is set with type
        Returns: Void
        */
        void setType(blockType);


        /*
        Purpose: Changes block type
        Pre-condition: Block exists and type
        Post-condition: Block has new type assigned
        Returns: Void
        */
        void switchType();


        /*
        Purpose: Updates sdl plotter screen
        Pre-condition: Plotter exists
        Post-condition: Plotter is updated
        Returns: Void
        */
        void update(SDL_Plotter& g);


        /*
        Purpose: Checks for tile below
        Pre-condition: Block exists and is on Board
        Post-condition: It Checked it:)
        Returns: Void
        */
        void checkForTileBelow(tile board[][COL], int);


        /*
        Purpose: Checks for floor below
        Pre-condition: Block exists and is on board
        Post-condition: Stops block if tile under
        Returns: Void
        */
        void checkForFloorBelow();


        /*
        Purpose: Checks for Tile Under
        Pre-condition: Block exists and is on board
        Post-condition: returns true if tile below
        Returns: bool
        */
        bool checkForTileUnder(tile board[][COL], int);


        /*
        Purpose: Checks for tile on left
        Pre-condition: Block exists and is on Board
        Post-condition: Checks for block on left
        Returns: bool
        */
        bool checkForTileLeft(tile board[][COL], int);


        /*
        Purpose: Checks for tile on left
        Pre-condition: Block exists and is on board
        Post-condition: Checks for block on right
        Returns: bool
        */
        bool checkForTileRight(tile board[][COL], int);


        /*
        Purpose: Stops the block
        Pre-condition: Block exists and has bool
        Post-condition: Block is stopped
        Returns: Void
        */
        void stopMoving();


        /*
        Purpose: Starts the active block moving
        Pre-condition: Block exists and is on board
        Post-condition: Block is moving
        Returns: Void
        */
        void startMoving();


        /*
        Purpose: Draws the plotter
        Pre-condition: sdl plotter is installed
        Post-condition: plotter is drawnb
        Returns: Void
        */
        void draw(SDL_Plotter& g);


        /*
        Purpose: Moves the block
        Pre-condition: Block exists
        Post-condition: Block is moved
        Returns: Void
        */
        void move();


        /*
        Purpose: move block to the left
        Pre-condition: block exists with location
        Post-condition: block moves left
        Returns: void
        */
        void moveLeft();


        /*
        Purpose: move block to the right
        Pre-condition: block exists with location
        Post-condition: block moves right
        Returns: void
        */
        void moveRight();


        /*
        Purpose: move block down the screen
        Pre-condition: block exists with location
        Post-condition: block moves down
        Returns: void
        */
        void moveDown();


        /*
        Purpose: rotate block
        Pre-condition: block exists with
                       location and orientation
        Post-condition: block is rotated
        Returns: void
        */
        void rotate(tile board[][COL], int);


        /*
        Purpose: Set block to random type of 7 blocks
        Pre-condition: block is created
        Post-condition: block type is set
        Returns: void
        */
        void setRandType();


        /*
        Purpose: make sure block is at a valid position
        Pre-condition: tile board exists, int for current row
        Post-condition: validPosition is returned
        Returns: bool, returns true if block is at a valid position
        */
        bool validPosition(tile board[][COL], int);


        /*
        Purpose: check to see if the game is over
        Pre-condition: block on screen with location
        Post-condition: game ends
        Returns: bool, if true game should end
        */
        bool checkForEndGame();

};

#endif // BLOCK_H_INCLUDED
