#include "block.h"

Block::Block(){
    size = TILE_SIZE;
    isCurrentlyMoving = true;
    isOnScreen = true;

//    loc.x = -50;
//    loc.y = -50;

    //*I think the randomizing functions need to be redone somehow using time. (Sometimes I get weird patterns with the blocks.)
    // I just forgot how to do that lol.

    //This builds the block with a random block type
    switch(rand() % 5){
        case 0:
            type = bar;
            break;
        case 1:
            type = square;
            break;
        case 2:
            type = l_shape;
            break;
        case 3:
            type = t_shape;
            break;
        case 4:
            type = z_shape;
            break;
    }

    //This builds the block with a random color
    switch(rand() % 5){
        case 0:
            shade = RED;
            break;
        case 1:
            shade = ORANGE;
            break;
        case 2:
            shade = YELLOW;
            break;
        case 3:
            shade = GREEN;
            break;
        case 4:
            shade = BLUE;
            break;
    }

    //This builds the block with a random orientation
    switch(rand() % 4){
        case 0:
            orientation = north;
            break;
        case 1:
            orientation = east;
            break;
        case 2:
            orientation = south;
            break;
        case 3:
            orientation = west;
            break;
    }

    setColor(shade);

}

void Block::moveLeft(){
    point p = getLocation();
    p.x -= size; //moves the Block left by one tile
    setLocation(p);
}
void Block::moveRight(){
    point p = getLocation();
    p.x += size; //moves the Block right by one tile
    setLocation(p);
}
void Block::moveDown(){
    point p = getLocation();
    p.y += size; //moves the Block down by one tile
    setLocation(p);
}

void Block::move(){
    point p = getLocation();
//    p.y += size; //I have found the moving left to right works better when we fall down smoothly rather than one "size" at a time
    p.y++;
    setLocation(p);
}

void Block::draw(SDL_Plotter& g){
    if(isOnScreen && isCurrentlyMoving){
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

     if(isOnScreen && isCurrentlyMoving){
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

                    case east:
                        b1.x = a1.x;
                        b1.y = a1.y - size;

                        c1.x = a1.x;
                        c1.y = a1.y - 2 * size;

                        d1.x = a1.x;
                        d1.y = a1.y + size;

                        break;
                }

                break;

            case square: //The square has only one orientation so we don't need to have switch statements rotate the block
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

            case z_shape://The z_shape only has two orientations as well
                switch(orientation){
                    case north:
                        b1.x = a1.x + size;
                        b1.y = a1.y - size;

                        c1.x = a1.x;
                        c1.y = a1.y - size;

                        d1.x = a1.x - size;
                        d1.y = a1.y;

                        break;

                    case east:
                        b1.x = a1.x + size;
                        b1.y = a1.y;

                        c1.x = a1.x + size;
                        c1.y = a1.y + size;

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
    }

    if((a1.x >= 0 && a1.x < NUM_COL - size && a1.y < NUM_ROW - size)&& // There are so many because it checks to make sure every single
       (b1.x >= 0 && b1.x < NUM_COL - size && b1.y < NUM_ROW - size)&& // tile is not touching a wall. I still don't know how to make it
       (c1.x >= 0 && c1.x < NUM_COL - size && c1.y < NUM_ROW - size)&& // not run into other tiles.
       (d1.x >= 0 && d1.x < NUM_COL - size && d1.y < NUM_ROW - size)){
           isOnScreen = true;
       }
    else{
           isOnScreen = false;
       }

    return;
}
void Block::setOriginalX(){
    loc.x = STARTING_X;
}
void Block::setOriginalY(){
    loc.y = STARTING_Y;
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
                    orientation = east;
                    break;
                case east:
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
bool Block::isMoving() const{
    return isCurrentlyMoving;
}

bool Block::isTouching(Block blockArray[], int NUM_OF_BLOCKS, int m) const{
    bool collide = false;
    for(int i = 0; i < NUM_OF_BLOCKS; i++){
        for(int j = 0; j < NUM_TILES; j++){
            for(int k = 0; k < NUM_TILES; k++){
                if(m!=i && blockArray[i].tileArray[j].getLocation().x == tileArray[k].getLocation().x
                        && blockArray[i].tileArray[j].getLocation().y == tileArray[k].getLocation().y  + TILE_SIZE ){
                    collide = true;
                }
            }
        }
    }
    return collide; //returns true if tiles are touching
}

void Block::stopMoving(){
    isCurrentlyMoving = false;
}

void Block::stopIfHitBottom(){
    if((tileArray[0].getLocation().y == NUM_ROW - size)&&
       (tileArray[1].getLocation().y == NUM_ROW - size)&&
       (tileArray[2].getLocation().y == NUM_ROW - size)&&
       (tileArray[3].getLocation().y == NUM_ROW - size)){
            stopMoving();
       }
}

