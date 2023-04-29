#include "block.h"

Block::Block(){
    size = TILE_SIZE;
    isCurrentlyMoving = true;
    orientation = east;

    loc.x = STARTING_X;
    loc.y = STARTING_Y;

    setRandType();
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
    if(tileArray[0].getLocation().x < NUM_COL - TILE_SIZE &&
       tileArray[1].getLocation().x < NUM_COL - TILE_SIZE &&
       tileArray[2].getLocation().x < NUM_COL - TILE_SIZE &&
       tileArray[3].getLocation().x < NUM_COL - TILE_SIZE){
        point p = getLocation();
        p.x += TILE_SIZE; //moves the Block right by one tile
        setLocation(p);
    }
}
void Block::moveDown(){
    if(tileArray[0].getLocation().y < NUM_ROW - TILE_SIZE &&
       tileArray[1].getLocation().y < NUM_ROW - TILE_SIZE &&
       tileArray[2].getLocation().y < NUM_ROW - TILE_SIZE &&
       tileArray[3].getLocation().y < NUM_ROW - TILE_SIZE){
        point p = getLocation();
        p.y += TILE_SIZE; //moves the Block down by one tile
        setLocation(p);
    }
}

void Block::move(){
    if(getLocation().y <= NUM_ROW - TILE_SIZE){
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
color Block::getColor() const{
    return shade;
}
int Block::getSize() const{
    return size;
}

void Block::setLocation(const point& a1){
    point b1, c1, d1;

    loc = a1;
    switch(type){
        case bar: 
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
    return;
}

void Block::setSize(int s){
    size = s;
    return;
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
            setType(bar);
            break;
        case l_shape:
            setType(t_shape);
            break;
        case t_shape:
            setType(l_shape);
            break;
        case z_shape:
            break;
    }
}

void Block::update(SDL_Plotter& g){
    g.update();
}

void Block::rotate(){
    // This function rotates the block. Based on the type of the block there are a different number of orientations the block can have. For
    // example, a square has 1 orientation, and a bar has 2, and the others have 4. That is why we will have to have switch statements to
    // determine the type of block and to switch between the certain number of orientations.
    // *Direction of rotation is clockwise.
    switch(type){
        case bar:

            switch(orientation){
                case north:
                    orientation = south;
                    break;
                case south:
                    orientation = north;
                    break;
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
    if( tileArray[0].getLocation().y == NUM_ROW - 2 * TILE_SIZE ||
        tileArray[1].getLocation().y == NUM_ROW - 2 * TILE_SIZE ||
        tileArray[2].getLocation().y == NUM_ROW - 2 * TILE_SIZE ||
        tileArray[3].getLocation().y == NUM_ROW - 2 * TILE_SIZE ){
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
    switch(rand() % 5){
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
    }
    setType(type);
    setColor(shade);
}

