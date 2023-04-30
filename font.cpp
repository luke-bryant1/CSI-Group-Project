#include "font.h"

void letter::init(string fname){
    ifstream input;
    input.open(fname);
    assert(input);

    input >> row >> col;
    for(int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            input >> data[r][c];
        }
    }
    input.close();
}

void letter::display(ostream& out){
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(data[r][c]== '1'){
                out << data[r][c];
            }
            else{
                out << ' ';
            }
        }
         out << endl;
    }
}

void letter::draw(int n, point p, SDL_Plotter& g){
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(data[r][c] == '1'){
                for(int xOff = 0; xOff < n; xOff++){
                    for(int yOff = 0; yOff < n; yOff++){
                        g.plotPixel(xOff + p.x + c * n, yOff + p.y + r * n,0,0,0);
                    }
                }
            }
        }
    }
}

Font::Font(){
    string fname;
    for(char c = 'A'; c <= 'Z'; c++){
        fname = "font\\";
        fname += c;
        fname += ".txt";
        data[c].init(fname);
    }
    for(char c = '0'; c <= '9'; c++){
        fname = "font\\";
        fname += c;
        fname += ".txt";
        data[c].init(fname);
    }

    loc.x = 0;
    loc.y = 0;
    size = 1;
}

void Font::setLoc(point p){
    loc = p;
}

void Font::setSize(int n){
    if(n >= 1){
        size = n;
    }
}

void Font::display(char c, ostream& out){
    data[c].display(out);
}

void Font::draw(char c, SDL_Plotter& g){
    data[c].draw(size,loc, g);
}

void Font::draw(string word, SDL_Plotter& g){
    for(int i = 0; i < word.size(); i++){
        draw(word.at(i), g);
        loc.x += size * 11;
    }
}

