#include "tetris.h"


void Tetris::setBoard(SDL_Plotter& g){
    point p(0,0);

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(p.x == NUM_COL){
                p.x = 0;
            }
            board[i][j].setLocation(p);
            board[i][j].setColor(BACKGROUND);
            board[i][j].draw(g);
            board[i][j].setIsOnScreen(false);
            p.x+= TILE_SIZE;
        }
        if(p.y == NUM_ROW){
            p.y = 0;
        }
        p.y+= TILE_SIZE;
    }
}

void Tetris::runTetris(SDL_Plotter& g){
    char key;
    while(!g.getQuit()){
        if(g.kbhit()){
            key = g.getKey();
            switch(key){
                case RIGHT_ARROW:
                    if(!currentBlock.checkForTileRight(board,ROW)){
                        currentBlock.moveRight();
                    }
                                break;
                case LEFT_ARROW:
                    if(!currentBlock.checkForTileLeft(board,ROW)){
                        currentBlock.moveLeft();
                    }
                                break;
                case DOWN_ARROW:
                    if(!currentBlock.checkForTileUnder(board,ROW)){
                        currentBlock.moveDown();
                    }
                                break;
                case UP_ARROW: currentBlock.rotate();
                                break;
            }
        }

        updateBoard(g);
        checkForFullRow(g);
        currentBlock.checkForTileBelow(board,ROW);
        currentBlock.checkForFloorBelow();

        if(!currentBlock.checkForTileUnder(board,ROW)){
            currentBlock.move();
        }

        currentBlock.draw(g);
        currentBlock.update(g);

        if(!currentBlock.isItMoving()){

            addBlockToBoard(currentBlock);
            currentBlock.setLocation(START_POINT);
            currentBlock.setRandType();
            currentBlock.update(g);
            currentBlock.startMoving();
        }

        g.Sleep(SPEED);
    }

}

void Tetris::addBlockToBoard(Block inputBlock){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            for(int k = 0; k < NUM_TILES; k++){
                if(board[i][j].getLocation().x == inputBlock.tileArray[k].getLocation().x &&
                   board[i][j].getLocation().y == inputBlock.tileArray[k].getLocation().y ){
                        board[i][j].setColor(inputBlock.tileArray[k].getColor());
                        board[i][j].setIsOnScreen(true);
                }
            }
        }
    }
}

void Tetris::updateBoard(SDL_Plotter& g){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                board[i][j].draw(g);
            }
        }
    }
}

void Tetris::checkForFullRow(SDL_Plotter& g){
    int count;
    for(int i = 0; i < ROW; i++){
        count = 0;
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                count++;
            }
            if(count == COL){
                for(int k = 0; k < COL; k++){
                    for(int l = i; l > 0; l--){
                        board[l][k].setColor(board[l-1][k].getColor());
                        board[l][k].draw(g);
                        board[l][k].setIsOnScreen(board[l-1][k].getIsOnScreen());
                    }
                }
            }
        }
    }
}

