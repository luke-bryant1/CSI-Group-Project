#include <iostream>
#include <cmath>
#include "tile.h"
#include "block.h"


using namespace std;

int main(int argc, char ** argv){
    SDL_Plotter g(NUM_ROW,NUM_COL); //These coordinates are the size of the window plotter
    char key;
    Block blockArray[NUM_OF_BLOCKS]; //We need to put this in a different "tetris.cpp" file
    int i = 0; //"i" tells us which block we are currently moving and the zero puts us at the first block in the array to start


    while(i < NUM_OF_BLOCKS){
        blockArray[i].setOriginalX(); //This puts the first place the block is drawn at the top near the middle
        blockArray[i].setOriginalY(); //This puts the block with enough room for the full block to be drawn
        //blockArray[i].startMoving();
                                        // we need to put these things into the block constructor
        while(blockArray[i].isMoving() && !g.getQuit()){
            if(g.kbhit()){
                key = g.getKey();
                switch(key){
                    case RIGHT_ARROW: blockArray[i].moveRight();
                                    break;
                    case LEFT_ARROW: blockArray[i].moveLeft();
                                    break;
                    case DOWN_ARROW: blockArray[i].moveDown();
                                    break;
                    case UP_ARROW: blockArray[i].rotate();
                                    break;
                }
            }

            blockArray[i].move();
            blockArray[i].draw(g);
            blockArray[i].stopIfHitBottom();
            if(blockArray[i].isTouching(blockArray, NUM_OF_BLOCKS, i)){
                blockArray[i].stopMoving();
            }

            blockArray[i].update(g);
            g.Sleep(SPEED);
        }
    i++; //This moves us to the next block when the current block stops moving
    }
}


//		    R = rand()%256; //This makes it a random color.
//		    G = rand()%256;
//		    B = rand()%256;
//		    xOff = rand() % g.getCol(); //This plots it in a random location
//		    yOff = rand() % g.getCol();
//            yOff += rate; //This makes it look like it's falling.
//
//            g.update();
//            g.Sleep(speed); //This makes the plotter slow down.
//
//            if(yOff == 0 || yOff > g.getRow() - size){ //The square now bounces up and down
//                      rate *= -1;                      //when it hits the top and bottom.
//            }

//		for(int x = 0; x < size; x++){
//            for(int y = 0; y < size; y++){
//                g.plotPixel(x + xOff, y + yOff, 0, 0, 0); //This plots a point at (x + xOff, y + yOff)
//                                                            with color black
//		        g.update();
//            }
//        }


void drawCircle(point loc, int size, color c, SDL_Plotter& g){
	for(double i = -size; i <= size;i+=0.1){
		for(double j = -size; j <= size; j+=0.1){
			if(i*i + j*j <= size*size){
				g.plotPixel(round(loc.x+i),round(loc.y+j),c);
			}
		}
	}

}

void drawSquare(SDL_Plotter& g, int xOff, int yOff,
                int size, int R, int G, int B){
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            g.plotPixel(x + xOff, y + yOff, R, G, B);
        }
    }

}
