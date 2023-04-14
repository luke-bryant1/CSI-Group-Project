#include "block.h"

Block::Block(){
    size = TILE_SIZE;

    //This builds the block with a random block type
    switch(rand()%5){
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
    switch(rand()%5){
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
    data[0].draw(g);
    data[1].draw(g);
    data[2].draw(g);
    data[3].draw(g);
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

    if(a1.x >= 0 && a1.y >= 0 &&
       a1.x < NUM_COL - size && a1.y < NUM_ROW - size){
        loc = a1;
        switch(type){
            case bar:
                b1.x = a1.x + size;
                b1.y = a1.y;

                c1.x = a1.x + 2 * size;
                c1.y = a1.y;

                d1.x = a1.x + 3 * size;
                d1.y = a1.y;

                break;

            case square:
                b1.x = a1.x + size;
                b1.y = a1.y;

                c1.x = a1.x;
                c1.y = a1.y + size;

                d1.x = a1.x + size;
                d1.y = a1.y + size;

                break;

            case l_shape:
                b1.x = a1.x + size;
                b1.y = a1.y;

                c1.x = a1.x + 2 * size;
                c1.y = a1.y;

                d1.x = a1.x + 2 * size;
                d1.y = a1.y + size;

                break;

            case z_shape:
                b1.x = a1.x + size;
                b1.y = a1.y;

                c1.x = a1.x + size;
                c1.y = a1.y + size;

                d1.x = a1.x + 2 * size;
                d1.y = a1.y + size;

                break;

            case t_shape:
                b1.x = a1.x + size;
                b1.y = a1.y;

                c1.x = a1.x + 2 * size;
                c1.y = a1.y;

                d1.x = a1.x + size;
                d1.y = a1.y + size;

                break;
        }

        data[0].setLocation(a1);
        data[1].setLocation(b1);
        data[2].setLocation(c1);
        data[3].setLocation(d1);
    }

    return;
}
void Block::setColor(const color& c){
    data[0].setColor(c);
    data[1].setColor(c);
    data[2].setColor(c);
    data[3].setColor(c);
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
