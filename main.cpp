#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "tile.h"

using namespace std;

//void drawSquare(SDL_Plotter& g, int xOff = 0, int yOff = 0, //Default values are only in the prototype.
//                int size = 25, int R = 0, int G = 0, int B = 0);
//
//void drawCircle(point loc, int size, color c, SDL_Plotter& g);

int main(int argc, char ** argv)
{

    SDL_Plotter g(NUM_ROW,NUM_COL); //These coordinates are the size of the window plotter
    char keyl
    tile a;
    a.setColor(RED);
    a.setSize(g.getCol()/12);
//    point p;
//    color c;
//    int size = 50;
//    int xOff = 0, yOff = 0; //This will help plot the square in a certain location.
//    int R, G, B;
//    int speed = 0; //This changed the speed the square moves.
//    int rate = 1; //This can change the direction of the falling square
//    char key;

    while (!g.getQuit())
    {
//        drawSquare(g, 100, 100, size, 255, 255, 255); //This erases the object so it doesn't leave a trail.
		if(g.kbhit()){
            key = g.getKey();
            switch(key){
                case RIGHT_ARROW: a.moveRight();
                                break;
                case LEFT_ARROW: a.moveLeft();
                                break;

            }
		}
		a.move();
		a.draw(g);
		a.update();
		g.Sleep(100); //This controls the speed that the block moves

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
//		        g.update(); //This actually takes it from memory and draws it to the screen.
//            }
//        }
    }
}


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
            g.plotPixel(x + xOff, y + yOff, R, G, B)
        }
    }

}
