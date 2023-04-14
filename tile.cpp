#include "tile.h"


void tile::moveLeft(){
    point p = getLocation();
    p.x -= size; //moves the tile left by one tile
    setLocation(p);
}
void tile::moveRight(){
    point p = getLocation();
    p.x += size; //moves the tile right by one tile
    setLocation(p);
}
void tile::moveDown(){
    point p = getLocation();
    p.y += size; //moves the tile down by one tile
    setLocation(p);
}

void tile::move(){
    point p = getLocation();
    p.y += size; //makes it fall one tile space at a time
    setLocation(p);
}

void tile::draw(SDL_Plotter& g){
    color currColor;
    //erase
    for(int r = 0; r < size; r++){ //"size" comes from inside the object
        for(int c = 0; c < size; c++){
            g.plotPixel(prevLoc.x + c, prevLoc.y + r, BACKGROUND); //this erases the previous location
        }
    }
    //draw
    for(int r = 0; r < size; r++){ //"size" comes from inside the object
        for(int c = 0; c < size; c++){
            currColor = shade;
            if(c == 0 || r == 0 || r == size - 1 || c == size - 1){
                currColor = BLACK; //This adds a black boarder around the edge of the tile
            }
            g.plotPixel(loc.x + c, loc.y + r, currColor); //this draws the square
        }
    }
    prevLoc = loc;
}

point tile::getLocation() const{
    return loc;
}
color tile::getColor() const{
    return shade;
}
int tile::getSize() const{
    return size;
}

void tile::setLocation(const point& p){
//    prevLoc = loc; //This sets the previous location to loc before it updates loc
//    we had to to move this to the last place that it was drawn so it wouldn't leave a streak
    if(p.x >= 0 && p.y>= 0 &&
       p.x < NUM_COL - size && p.y < NUM_ROW - size){
        loc = p;
    }
    return;
}
void tile::setColor(const color& c){
    shade = c;
    return;
}
void tile::setSize(int s){
    size = s;
    return;
}
void tile::update(SDL_Plotter& g){
    g.update();
}
