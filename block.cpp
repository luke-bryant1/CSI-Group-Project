#include "block.h"

using namespace std;

Block::Block(){
    size = TILE_SIZE;
    isCurrentlyMoving = true;
    orientation = east;

    type = square;
    setColor(YELLOW);
    setBorderColor(BACKGROUND);

    loc.x = STARTING_X;
    loc.y = STARTING_Y;
}

void Block::moveLeft(){
    if(tileArray[0].getLocation().x > 0 &&
       tileArray[1].getLocation().x > 0 &&
       tileArray[2].getLocation().x > 0 &&
       tileArray[3].getLocation().x > 0){
        point p = getLocation();
        p.x -= TILE_SIZE; //moves the Block left by one tile
        setLocation(p);
    }
}
void Block::moveRight(){
    if(tileArray[0].getLocation().x < COL * (TILE_SIZE - 3) &&
       tileArray[1].getLocation().x < COL * (TILE_SIZE - 3) &&
       tileArray[2].getLocation().x < COL * (TILE_SIZE - 3) &&
       tileArray[3].getLocation().x < COL * (TILE_SIZE - 3) ){
        point p = getLocation();
        p.x += TILE_SIZE; //moves the Block right by one tile
        setLocation(p);
    }
}
void Block::moveDown(){
    if(tileArray[0].getLocation().y < NUM_ROW - 2 * TILE_SIZE &&
       tileArray[1].getLocation().y < NUM_ROW - 2 * TILE_SIZE &&
       tileArray[2].getLocation().y < NUM_ROW - 2 * TILE_SIZE &&
       tileArray[3].getLocation().y < NUM_ROW - 2 * TILE_SIZE){
        point p = getLocation();
        p.y += TILE_SIZE; //moves the Block down by one tile
        setLocation(p);
    }
}

void Block::move(int level){
    static int count = 0;
    count++;
    if(getLocation().y <= NUM_ROW - TILE_SIZE && count > 100/level){
        count = 0;
        point p = getLocation();
        p.y += TILE_SIZE;
        setLocation(p);
    }
}

void Block::draw(SDL_Plotter& g){
    if(isCurrentlyMoving){
        tileArray[0].draw(g);
        tileArray[1].draw(g);
        tileArray[2].draw(g);
        tileArray[3].draw(g);
    }
}

point Block::getLocation() const{
    return loc;
}
color Block::getColor() {
    return shade;
}
int Block::getSize() const{
    return size;
}

void Block::setLocation(const point& a1){
    point b1, c1, d1;

    loc = a1;
    switch(type){
        case bar: //The bar has only two orientations so we only need to have switch statements that rotate the block between two orientations
            switch(orientation){
                case north:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x + 2 * size;
                    c1.y = a1.y;

                    d1.x = a1.x - size;
                    d1.y = a1.y;

                    break;

                case south:
                    b1.x = a1.x;
                    b1.y = a1.y - size;

                    c1.x = a1.x;
                    c1.y = a1.y - 2 * size;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;

                case east:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x + 2 * size;
                    c1.y = a1.y;

                    d1.x = a1.x - size;
                    d1.y = a1.y;

                    break;

                case west:
                    b1.x = a1.x;
                    b1.y = a1.y - size;

                    c1.x = a1.x;
                    c1.y = a1.y - 2 * size;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;
            }

            break;

        case square:
            b1.x = a1.x + size;
            b1.y = a1.y;

            c1.x = a1.x;
            c1.y = a1.y - size;

            d1.x = a1.x + size;
            d1.y = a1.y - size;

            break;

        case l_shape:
             switch(orientation){
                case north:
                    b1.x = a1.x - size;
                    b1.y = a1.y;

                    c1.x = a1.x + size;
                    c1.y = a1.y;

                    d1.x = a1.x + size;
                    d1.y = a1.y - size;

                    break;

                case east:
                    b1.x = a1.x;
                    b1.y = a1.y - size;

                    c1.x = a1.x;
                    c1.y = a1.y + size;

                    d1.x = a1.x + size;
                    d1.y = a1.y + size;

                    break;

                case south:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y;

                    d1.x = a1.x - size;
                    d1.y = a1.y + size;

                    break;

                case west:
                    b1.x = a1.x;
                    b1.y = a1.y + size;

                    c1.x = a1.x;
                    c1.y = a1.y - size;

                    d1.x = a1.x - size;
                    d1.y = a1.y - size;

                    break;
             }

            break;

        case l_shape_opp:
             switch(orientation){
                case north:
                    b1.x = a1.x - size;
                    b1.y = a1.y;

                    c1.x = a1.x + size;
                    c1.y = a1.y;

                    d1.x = a1.x + size;
                    d1.y = a1.y + size;

                    break;

                case east:
                    b1.x = a1.x;
                    b1.y = a1.y - size;

                    c1.x = a1.x - size;
                    c1.y = a1.y + size;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;

                case south:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y;

                    d1.x = a1.x - size;
                    d1.y = a1.y - size;

                    break;

                case west:
                    b1.x = a1.x;
                    b1.y = a1.y + size;

                    c1.x = a1.x;
                    c1.y = a1.y - size;

                    d1.x = a1.x + size;
                    d1.y = a1.y - size;

                    break;
             }

            break;

        case z_shape:
            switch(orientation){
                case north:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x + size;
                    c1.y = a1.y - size;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;

                case east:
                    b1.x = a1.x - size;
                    b1.y = a1.y;

                    c1.x = a1.x + size;
                    c1.y = a1.y + size;

                    d1.x = a1.x;
                    d1.y = a1.y + size;


                    break;

                case south:
                    b1.x = a1.x - size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y + size;

                    d1.x = a1.x;
                    d1.y = a1.y - size;

                    break;

                case west:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y - size;

                    d1.x = a1.x;
                    d1.y = a1.y - size;

                    break;
             }

            break;

        case z_shape_opp:
            switch(orientation){
                case north:
                    b1.x = a1.x - size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y - size;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;

                case east:
                    b1.x = a1.x - size;
                    b1.y = a1.y;

                    c1.x = a1.x + size;
                    c1.y = a1.y - size;

                    d1.x = a1.x;
                    d1.y = a1.y - size;


                    break;

                case south:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x + size;
                    c1.y = a1.y + size;

                    d1.x = a1.x;
                    d1.y = a1.y - size;

                    break;

                case west:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y + size;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;
             }

            break;

        case t_shape:
            switch(orientation){
                case north:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y;

                    d1.x = a1.x;
                    d1.y = a1.y - size;

                    break;

                case east:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x;
                    c1.y = a1.y + size;

                    d1.x = a1.x;
                    d1.y = a1.y - size;

                    break;

                case south:
                    b1.x = a1.x + size;
                    b1.y = a1.y;

                    c1.x = a1.x - size;
                    c1.y = a1.y;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;

                case west:
                    b1.x = a1.x;
                    b1.y = a1.y - size;

                    c1.x = a1.x - size;
                    c1.y = a1.y;

                    d1.x = a1.x;
                    d1.y = a1.y + size;

                    break;
             }

            break;
    }

        tileArray[0].setLocation(a1);
        tileArray[1].setLocation(b1);
        tileArray[2].setLocation(c1);
        tileArray[3].setLocation(d1);

    return;
}
void Block::setColor(const color& c){
    tileArray[0].setColor(c);
    tileArray[1].setColor(c);
    tileArray[2].setColor(c);
    tileArray[3].setColor(c);
    shade = c;
}

void Block::setSize(int s){
    size = s;
}
void Block::setBorderColor(color c){
    tileArray[0].setBorderColor(c);
    tileArray[1].setBorderColor(c);
    tileArray[2].setBorderColor(c);
    tileArray[3].setBorderColor(c);
    borderColor = c;
}

void Block::setType(blockType input_type){
    type = input_type;
}
void Block::switchType(){
    switch(type){
        case bar:
            setType(square);
            break;
        case square:
            setType(l_shape);
            break;
        case l_shape:
            setType(t_shape);
            break;
        case t_shape:
            setType(z_shape);
            break;
        case z_shape:
            setType(l_shape_opp);
            break;
        case l_shape_opp:
            setType(z_shape_opp);
            break;
        case z_shape_opp:
            break;
    }
}

void Block::update(SDL_Plotter& g){
    g.update();
}

void Block::rotate(tile board[][COL], int ROW){
    previousOrientation = orientation;
    switch(type){
        case bar:
            switch(orientation){
                case north:
                    orientation = south;
                    break;
                case south:
                    orientation = north;
                    break;
                case east:
                    orientation = north;
                case west:
                    orientation = north;
            }

            break;

        case square:

            break;

        case l_shape:

            switch(orientation){
                case north:
                    orientation = east;
                    break;
                case east:
                    orientation = south;
                    break;
                case south:
                    orientation = west;
                    break;
                case west:
                    orientation = north;
                    break;
            }

            break;

        case l_shape_opp:

            switch(orientation){
                case north:
                    orientation = east;
                    break;
                case east:
                    orientation = south;
                    break;
                case south:
                    orientation = west;
                    break;
                case west:
                    orientation = north;
                    break;
            }

            break;

        case z_shape:

            switch(orientation){
                case north:
                    orientation = east;
                    break;
                case east:
                    orientation = south;
                    break;
                case south:
                    orientation = west;
                    break;
                case west:
                    orientation = north;
                    break;
            }

            break;

        case z_shape_opp:

            switch(orientation){
                case north:
                    orientation = east;
                    break;
                case east:
                    orientation = south;
                    break;
                case south:
                    orientation = west;
                    break;
                case west:
                    orientation = north;
                    break;
            }

            break;

        case t_shape:

            switch(orientation){
                case north:
                    orientation = east;
                    break;
                case east:
                    orientation = south;
                    break;
                case south:
                    orientation = west;
                    break;
                case west:
                    orientation = north;
                    break;
            }

            break;
    }
    setLocation(loc);
    if(!validPosition(board,ROW)){
        orientation = previousOrientation;
        setLocation(loc);
    }

}
bool Block::isItMoving() const{
    return isCurrentlyMoving;
}
void Block::checkForTileBelow(tile board[][COL], int ROW){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                if( tileArray[0].isTouching(board[i][j], "down") ||
                    tileArray[1].isTouching(board[i][j], "down") ||
                    tileArray[2].isTouching(board[i][j], "down") ||
                    tileArray[3].isTouching(board[i][j], "down") ){
                    stopMoving();
                }
            }
        }
    }
}

bool Block::checkForTileUnder(tile board[][COL], int ROW){
    bool isTile = false;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                if( tileArray[0].isTouching(board[i][j], "down") ||
                    tileArray[1].isTouching(board[i][j], "down") ||
                    tileArray[2].isTouching(board[i][j], "down") ||
                    tileArray[3].isTouching(board[i][j], "down") ){
                    isTile = true;
                }
            }
        }
    }
    return isTile;
}
bool Block::checkForTileLeft(tile board[][COL], int ROW){
    bool isTile = false;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                if( tileArray[0].isTouching(board[i][j], "left") ||
                    tileArray[1].isTouching(board[i][j], "left") ||
                    tileArray[2].isTouching(board[i][j], "left") ||
                    tileArray[3].isTouching(board[i][j], "left") ){
                    isTile = true;
                }
            }
        }
    }
    return isTile;
}
bool Block::checkForTileRight(tile board[][COL], int ROW){
    bool isTile = false;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                if( tileArray[0].isTouching(board[i][j], "right") ||
                    tileArray[1].isTouching(board[i][j], "right") ||
                    tileArray[2].isTouching(board[i][j], "right") ||
                    tileArray[3].isTouching(board[i][j], "right") ){
                    isTile = true;
                }
            }
        }
    }
    return isTile;
}

void Block::checkForFloorBelow(){
    if( tileArray[0].getLocation().y == NUM_ROW - TILE_SIZE ||
        tileArray[1].getLocation().y == NUM_ROW - TILE_SIZE ||
        tileArray[2].getLocation().y == NUM_ROW - TILE_SIZE ||
        tileArray[3].getLocation().y == NUM_ROW - TILE_SIZE ){
        stopMoving();
    }
}

void Block::stopMoving(){
    isCurrentlyMoving = false;
    tileArray[0].stopMoving();
    tileArray[1].stopMoving();
    tileArray[2].stopMoving();
    tileArray[3].stopMoving();
}

void Block::startMoving(){
    isCurrentlyMoving = true;
    tileArray[0].startMoving();
    tileArray[1].startMoving();
    tileArray[2].startMoving();
    tileArray[3].startMoving();
}

void Block::setRandType(){
    switch(rand() % 7){
        case 0:
            type  = bar;
            shade = CYAN;
            break;
        case 1:
            type  = square;
            shade = YELLOW;
            break;
        case 2:
            type  = l_shape;
            shade = RED;
            break;
        case 3:
            type  = t_shape;
            shade = BLUE;
            break;
        case 4:
            type  = z_shape;
            shade = PURPLE;
            break;
        case 5:
            type  = l_shape_opp;
            shade = GREEN;
            break;
        case 6:
            type  = z_shape_opp;
            shade = ORANGE;
            break;

    }
    setType(type);
    setColor(shade);
    setBorderColor(BACKGROUND);
}

bool Block::validPosition(tile board[][COL], int ROW){
    bool validPosition = true;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                if((tileArray[0].getLocation().x == board[i][j].getLocation().x && tileArray[0].getLocation().y == board[i][j].getLocation().y ) ||
                   (tileArray[1].getLocation().x == board[i][j].getLocation().x && tileArray[1].getLocation().y == board[i][j].getLocation().y ) ||
                   (tileArray[2].getLocation().x == board[i][j].getLocation().x && tileArray[2].getLocation().y == board[i][j].getLocation().y ) ||
                   (tileArray[3].getLocation().x == board[i][j].getLocation().x && tileArray[3].getLocation().y == board[i][j].getLocation().y ) ||
                    tileArray[0].getLocation().x < 0 || tileArray[1].getLocation().x < 0 ||
                    tileArray[2].getLocation().x < 0 || tileArray[3].getLocation().x < 0 ||
                    tileArray[0].getLocation().x > COL * (TILE_SIZE - 1) || tileArray[1].getLocation().x > COL * (TILE_SIZE - 1)  ||
                    tileArray[2].getLocation().x > COL * (TILE_SIZE - 1)  || tileArray[3].getLocation().x > COL * (TILE_SIZE - 1) ){
                    validPosition = false;
                }
            }
        }
    }
    return validPosition;
}


bool Block::checkForEndGame(){
    bool isEndGame = false;
    if((isItMoving() == false && (tileArray[0].getLocation().y == TILE_SIZE-100 || tileArray[0].getLocation().y < TILE_SIZE-100)) ||
       (isItMoving() == false && (tileArray[1].getLocation().y == TILE_SIZE-100 || tileArray[1].getLocation().y < TILE_SIZE-100)) ||
       (isItMoving() == false && (tileArray[2].getLocation().y == TILE_SIZE-100 || tileArray[2].getLocation().y < TILE_SIZE-100)) ||
       (isItMoving() == false && (tileArray[3].getLocation().y == TILE_SIZE-100 || tileArray[3].getLocation().y < TILE_SIZE-100))){
        isEndGame = true;
    }
    return isEndGame;
}

