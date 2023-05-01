#include "tetris.h"

void Tetris::startScreen(SDL_Plotter& g){
    point p(0,0);
    Font text;

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < 2*COL; j++){
            if(p.x == 2 * COL * TILE_SIZE){
                p.x = 0;
            }
            fullScreen[i][j].setLocation(p);
            fullScreen[i][j].setColor(NAVY);
            fullScreen[i][j].setBorderColor(NAVY);
            fullScreen[i][j].draw(g);
            p.x+= TILE_SIZE;
        }
        p.y+= TILE_SIZE;
    }

    //draw yellow border
    point yellowBorderLoc (25, 210);
    int length = 450, height = 145;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < height; j++){
            if(i == 0 || i == length - 1 || j == 0 || j == height - 1){
                g.plotPixel(yellowBorderLoc.x + i, yellowBorderLoc.y + j, YELLOW);
            }
        }
    }

    int tetrisFontSize = 6;
    point tetrisLoc (50, 220);
    text.setLoc(tetrisLoc);
    text.setSize(tetrisFontSize);
    text.draw("T", g, YELLOW);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("E", g, ORANGE);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("T", g, RED);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("R", g, PURPLE);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("I", g, BLUE);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("S", g, GREEN);

    point startLoc (30, 300);
    text.setLoc(startLoc);
    text.setSize(2);
    text.draw("PRESS SPACE TO START", g, YELLOW);

}

void Tetris::eraseStartScreen(SDL_Plotter& g){
    point p(0,0);

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < 2*COL; j++){
            if(p.x == 2 * COL * TILE_SIZE){
                p.x = 0;
            }
            fullScreen[i][j].setLocation(p);
            fullScreen[i][j].setColor(NAVY);
            fullScreen[i][j].setBorderColor(NAVY);
            fullScreen[i][j].draw(g);
            p.x+= TILE_SIZE;
        }
        p.y+= TILE_SIZE;
    }

}

void Tetris::setBoard(SDL_Plotter& g){
    point p(0,0);

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(p.x == COL * TILE_SIZE){
                p.x = 0;
            }
            board[i][j].setLocation(p);
            board[i][j].setColor(BACKGROUND);
            board[i][j].setBorderColor(LIGHTGRAY);

            board[i][j].draw(g);
            board[i][j].setIsOnScreen(false);
            p.x+= TILE_SIZE;
        }
        p.y+= TILE_SIZE;
    }
}

void Tetris::grid(SDL_Plotter& g){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            board[i][j].draw(g);
        }
    }
}

void Tetris::drawRightBoard(SDL_Plotter& g){
    point p(COL * (TILE_SIZE + 1),0);
    int currentScore = 0, currentLine  = 0;
    string stringScore = "0", stringLines = "0";
    stringstream ss;
    Font text;

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(p.x > NUM_COL){
                p.x = COL * (TILE_SIZE + 1);
            }
            rightBoard[i][j].setLocation(p);
            rightBoard[i][j].setColor(NAVY);
            rightBoard[i][j].setBorderColor(NAVY);
            rightBoard[i][j].draw(g);
            p.x+= TILE_SIZE;
        }
        p.y+= TILE_SIZE;
    }

    point scoreWord (300,100);
    point scoreNum  (300,150);
    point lineWord  (300,200);
    point lineNum   (300,250);

    //print TETRIS
    int tetrisFontSize = 3;
    point tetrisLoc (285, 25);
    text.setLoc(tetrisLoc);
    text.setSize(tetrisFontSize);
    text.draw("T", g, YELLOW);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("E", g, ORANGE);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("T", g, RED);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("R", g, PURPLE);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("I", g, BLUE);
    tetrisLoc.x += tetrisFontSize * 11;
    text.draw("S", g, GREEN);

    //print score as 0
    text.setLoc(scoreWord);
    text.setSize(2);
    text.draw("SCORE", g, CYAN);
    text.setLoc(scoreNum);
    ss.clear();
    ss.str("");
    ss << currentScore;
    stringScore = ss.str();
    text.draw(stringScore,g, CYAN);

    //print lines as 0
    text.setLoc(lineWord);
    text.setSize(2);
    text.draw("LINES", g, YELLOW);
    text.setLoc(lineNum);
    ss.clear();
    ss.str("");
    ss << currentLine;
    stringLines = ss.str();
    text.draw(stringLines,g, YELLOW);
}

void Tetris::runTetris(SDL_Plotter& g){
    char key;

    int currentScore = 0, previousScore = 0,
        currentLine  = 0, previousLine  = 0;
    string stringScore = "0", stringLines = "0";
    stringstream ss;
    Font text;

    text.setSize(2);

    point scoreNum  (300,150);
    point lineNum   (300,250);

    blankTile.setColor(BACKGROUND);
    blankTile.setBorderColor(BACKGROUND);

    while(!g.getQuit()){
        if(g.kbhit()){
            while(key = g.getKey()){
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
        }
        previousScore = currentScore;

        updateBoard(g);
        checkForFullRow(g);

        currentScore = getScore();

        if(currentScore > previousScore){
            for(int i = 0; i < 5;i++){
                blankTile.setLocation(scoreNum);
                blankTile.draw(g);
                scoreNum.x += TILE_SIZE;
            }

            scoreNum.x = 300;
            scoreNum.y = 150;

            text.setLoc(scoreNum);
            ss.clear();
            ss.str("");
            ss << currentScore;
            stringScore = ss.str();
            text.draw(stringScore,g, CYAN);
        }

        previousLine = currentLine;

        updateBoard(g);
        checkForFullRow(g);

        currentLine = getLine();

        if(currentLine > previousLine){
            for(int i = 0; i < 15;i++){
                blankTile.setLocation(lineNum);
                blankTile.draw(g);
                lineNum.x += TILE_SIZE;
            }

            lineNum.x = 300;
            lineNum.y = 250;

            text.setLoc(lineNum);
            ss.clear();
            ss.str("");
            ss << currentLine;
            string stringLines = ss.str();
            text.draw(stringLines,g, ORANGE);
        }

        currentBlock.checkForTileBelow(board,ROW);
        currentBlock.checkForFloorBelow();
        updateBoard(g);

        if(!currentBlock.checkForTileUnder(board,ROW)){
            currentBlock.move();
        }

        grid(g);
        updateBoard(g);
        currentBlock.draw(g);
        currentBlock.update(g);
        grid(g);
        currentBlock.draw(g);
        currentBlock.update(g);
        updateBoard(g);

        if(!currentBlock.isItMoving()){

            addBlockToBoard(currentBlock);
            currentBlock.setLocation(START_POINT);
            currentBlock.setRandType();
            currentBlock.update(g);
            currentBlock.startMoving();
        }

        g.Sleep(100);
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

void Tetris::setLine(int n){
    line += n;
}

int Tetris::getLine(){
    return line;
}

void Tetris::setScore(int n){
    if(n == 1){
        score += 40;
    }
    if(n == 2){
        score += 100;
    }
    if(n == 3){
        score += 300;
    }
    if(n == 4){
        score += 1200;
    }
}

int Tetris::getScore(){
    return score;
}

void Tetris::checkForFullRow(SDL_Plotter& g){
    int count;
    int l = 0;
    for(int i = 0; i < ROW; i++){
        count = 0;
        for(int j = 0; j < COL; j++){
            if(board[i][j].getIsOnScreen()){
                count++;
            }
            if(count == COL){
                setLine(1);
                l++;
                setScore(l);
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

