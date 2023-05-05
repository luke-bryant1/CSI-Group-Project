/*
 Authors: Luke Bryant, Bella Henslee, Samuel Choi, Raphe Prince
 Assignment Title: Final Project - Tetris
 Assignment Description: Create a Tetris Game
 Due Date: 5/4/2023
 Date Created: 4/15/2023
 Date Modified: 5/4/2023

 This file contains the declaration for the tile object along with it's various
 functions. We use a compilation of tiles to create the board and to create
 blocks. Each tile has a location, color, border color, size, and two booleans
 returning whether or not the tile is moving and whether or not it is on the board
 or not.
 */

#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "SDL_Plotter.h"
#include "constants.h"

class tile{
    private:
        point loc, prevLoc;
        color shade, borderColor;
        int size;
        bool onTheMove;
        bool isOnScreen;

    public:
        /*
         * description: tile constructor
         * return: none
         * precondition: none
         * postcondition: constructs the tile with size 25
        */
        tile(){
            size = TILE_SIZE;
        }

        /*
         * description: return location of a tile
         * return: point location of the tile
         * precondition: tile exists with a location
         * postcondition: location is returned
        */
        point getLocation() const;

        /*
         * description: return color of a tile
         * return: color of the tile
         * precondition: tile exists with a color
         * postcondition: color is returned
        */
        color getColor() const;

        /*
         * description: return border color of a tile
         * return: border color of the tile
         * precondition: tile exists with a border color
         * postcondition: border color is returned
        */
        color getBorderColor();

        /*
         * description: return size of a tile
         * return: int size of the tile
         * precondition: tile exists with a size
         * postcondition: size is returned
        */
        int getSize() const;

        /*
         * description: sets the border color of a tile
         * return: void
         * precondition: parameter color to be set as border color
         * postcondition: border color is set
        */
        void setBorderColor(color);

        /*
         * description: sets the location of a tile,
                        and makes sure tile does not move off the screen
         * return: void
         * precondition: parameter point to set location to
         * postcondition: location is set
        */
        void setLocation(const point&);

        /*
         * description: sets the color of a tile
         * return: void
         * precondition: parameter color to be set as tile color
         * postcondition: tile color is set
        */
        void setColor(const color&);

        /*
         * description: sets the size of a tile
         * return: void
         * precondition: parameter int to set size to
         * postcondition: tile size is set
        */
        void setSize(int);

        /*
         * description: updates the plot with the tile
         * return: void
         * precondition: SDL plotter is valid
         * postcondition: plotter is updated
        */
        void update(SDL_Plotter& g);

        /*
         * description: determines if two tiles are touching
         * return: boolean returns true if two tiles have the same location
         * precondition: parameter tile to be checked if it has same location
                        as current tile, string direction to be checked, left,
                        right, or down
         * postcondition: determined if tiles are touching
        */
        bool isTouching(tile&, string);

        /*
         * description: return if the tile is moving
         * return: boolean onTheMove, returns true if tile is moving
         * precondition: tile exists with bool onTheMove
         * postcondition: onTheMove is returned
        */
        bool isOnTheMove();

        /*
         * description: stops the tile from moving
         * return: void
         * precondition: tile exists with bool onTheMove
         * postcondition: onTheMove is now false
        */
        void stopMoving();

        /*
         * description: starts the tile moving
         * return: void
         * precondition: tile exists with bool onTheMove
         * postcondition: onTheMove is now true
        */
        void startMoving();

        /*
         * description: sets the member isOnScreen
         * return: void
         * precondition: tile exists with bool isOnScreen,
                        parameter boolean to set isOnScreen
         * postcondition: isOnScreen is now set
        */
        void setIsOnScreen(bool);

        /*
         * description: return if the tile is on the screen
         * return: boolean isOnScreen, returns true if tile is on screen
         * precondition: tile exists with bool isOnScreen
         * postcondition: isOnScreen is returned
        */
        bool getIsOnScreen();

        /*
         * description: erase what is plotted on the screen
         * return: void
         * precondition: SDL Plotter is valid
         * postcondition: navy pixels are plotted on screen to cover
        */
        void erase(SDL_Plotter& g);

        /*
         * description: draw tile on screen
         * return: void
         * precondition: SDL Plotter is valid
         * postcondition: pixels are plotted on screen to form tile
        */
        void draw(SDL_Plotter& g);


};

#endif // TILE_H_INCLUDED
