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
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            g.plotPixel(prevLoc.x + c, prevLoc.y + r, BACKGROUND);
        }
    }

    //draw
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            currColor = shade;
            if(c == 0 || r == 0 || r == size - 1 || c == size - 1){
                currColor = borderColor;
            }
            g.plotPixel(loc.x + c, loc.y + r, currColor); //this draws the square
        }
    }
    prevLoc = loc;
}
void tile::erase(SDL_Plotter& g){
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++){
            g.plotPixel(loc.x + c, loc.y + r, NAVY);
        }
    }
}

point tile::getLocation() const{
    return loc;
}
color tile::getColor() const{
    return shade;
}
color tile::getBorderColor(){
    return borderColor;
}
int tile::getSize() const{
    return size;
}

void tile::setLocation(const point& p){
    loc = p;

    if(p.y == NUM_ROW - size){
        onTheMove = false;
    }

    return;
}
void tile::setColor(const color& c){
    shade = c;
}
void tile::setBorderColor(color c){
    borderColor = c;
}
void tile::setSize(int s){
    size = s;
    return;
}
void tile::update(SDL_Plotter& g){
    g.update();
}

bool tile::isTouching(tile& other, string direcToCheck){
    bool itIsTouching = false;

    if(direcToCheck == "left"){
        if(loc.x - TILE_SIZE == other.loc.x &&
           loc.y == other.loc.y){
                itIsTouching = true;
        }
    }
    if(direcToCheck == "right"){
        if(loc.x + TILE_SIZE == other.loc.x &&
           loc.y == other.loc.y){
            itIsTouching = true;
        }
    }
    if(direcToCheck == "down"){
        if(loc.x == other.loc.x &&
           loc.y + TILE_SIZE == other.loc.y){
            itIsTouching = true;
        }
    }

    return itIsTouching;
}
bool tile::isOnTheMove(){
    return onTheMove;
}
void tile::stopMoving(){
    onTheMove = false;
}
void tile::startMoving(){
    onTheMove = true;
}

void tile::setIsOnScreen(bool onOrOff){
    isOnScreen = onOrOff;
}
bool tile::getIsOnScreen(){
    return isOnScreen;
}

