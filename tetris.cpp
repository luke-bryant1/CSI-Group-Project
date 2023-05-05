/*
 Authors: Luke Bryant, Bella Henslee, Samuel Choi, Raphe Prince
 Assignment Title: Final Project - Tetris
 Assignment Description: Create a Tetris Game
 Due Date: 5/4/2023
 Date Created: 4/15/2023
 Date Modified: 5/4/2023
 */

#include "tetris.h"

void Tetris::startScreen(SDL_Plotter& g){
    // We are unsure why, but this Tetris.mp3 music file
    // only plays on certain machines.
    g.initSound("Tetris.mp3");
    g.playSound("Tetris.mp3");
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
    int length = 450, height = 120;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < height; j++){
            if(i == 0 || i == length - 1 || j == 0 || j == height - 1){
                g.plotPixel(yellowBorderLoc.x + i, yellowBorderLoc.y + j, YELLOW);
            }
        }
    }

    int tetrisFontSize = 8;
    point tetrisLoc (40, 220);
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

    point startLoc (75, 300);
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
    int currentScore = 0, currentLine  = 0, currentLevel = 1;
    string stringScore = "0", stringLines = "0", stringLevel = "1";
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
    point levelWord (300,300);
    point levelNum  (300,350);

    //print TETRIS
    int tetrisFontSize = 4;
    point tetrisLoc (265, 25);
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
    text.setSize(3);
    text.draw("SCORE", g, CYAN);
    drawScore(scoreNum, g, currentScore,3);

    //print lines as 0
    text.setLoc(lineWord);
    text.setSize(3);
    text.draw("LINES", g, CYAN);
    drawScore(lineNum, g, currentLine,3);

    //draw level as 0
    text.setLoc(levelWord);
    text.setSize(3);
    text.draw("LEVEL", g, CYAN);
    drawScore(levelNum, g, currentLevel,3);

}

bool Tetris::runTetris(SDL_Plotter& g){
    char key;
    bool gameOver = false;
    Font text;
    int currentScore = 0, previousScore = 0,
        currentLine  = 0, previousLine  = 0,
        previousLevel;
    string stringScore = "0", stringLines = "0";
    stringstream ss;

    point scoreNum  (300,150);
    point lineNum   (300,250);
    point levelNum  (300,350);

    g.initSound("clear.wav");

    while(!g.getQuit() && !gameOver){
        if(g.kbhit()){
            while(key = g.getKey()){
                switch(key){
                    //this moves the tile when you hit a key
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
                    case UP_ARROW:
                            currentBlock.rotate(board,ROW);
                        break;
                    case ' ':
                        for(int i = 0; i < ROW; i++){
                            if(!currentBlock.checkForTileUnder(board,ROW)){
                                currentBlock.moveDown();
                            }
                        }
                        break;
                }
            }
        }

        previousScore = currentScore;
        previousLine = currentLine;
        previousLevel = level;
        checkForFullRow(g);
        currentScore = getScore();

        //this updates the score when you clear a line
        if(currentScore != previousScore){
            eraseScore(scoreNum, g);
            drawScore(scoreNum, g, currentScore,3);
            g.playSound("clear.wav");
        }
        currentLine = getLine();

        //this updates number of lines you have cleared when you clear a line
        if(currentLine != previousLine){
            eraseScore(lineNum, g);
            drawScore(lineNum, g, currentLine,3);
        }

        //this updates the level you are on every 6 lines you clear
        if(level != previousLevel){
            eraseScore(levelNum, g);
            drawScore(levelNum, g, level,3);
        }

        currentBlock.checkForTileBelow(board,ROW);
        currentBlock.checkForFloorBelow();
        updateBoard(g);

        if(!currentBlock.checkForTileUnder(board,ROW)){
            currentBlock.move(level);
        }

        grid(g);
        currentBlock.draw(g);
        currentBlock.update(g);
        updateBoard(g);

        if(currentBlock.checkForEndGame()){
            drawScore(scoreNum, g, currentScore,3);
            drawScore(lineNum, g, currentLine,3);
            eraseScore(scoreNum, g);
            eraseScore(lineNum, g);
            gameOver = true;
        }

        if(!currentBlock.isItMoving()){
            addBlockToBoard(currentBlock);
            currentBlock.setLocation(START_POINT);
            currentBlock.setRandType();
            currentBlock.update(g);
            currentBlock.startMoving();
        }
        g.Sleep(SPEED);
    }
    return gameOver;
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
                //change speed every 6 levels
                if(getLine() % 6 == 0){
                    level++;
                }

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

void Tetris::endGame(SDL_Plotter& g){
    point p(0,0);
    Font text;
    int currentScore, currentLine;
    string stringScore = "0", stringLines = "0";
    stringstream ss;

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

    int tetrisFontSize = 10;
    point gameloc (85, 140);
    text.setLoc(gameloc);
    text.setSize(tetrisFontSize);
    text.draw("GAME", g, RED);

    point endloc (85, 240);
    text.setLoc(endloc);
    text.setSize(tetrisFontSize);
    text.draw("OVER", g, RED);

    point replayloc (30, 380);
    text.setLoc(replayloc);
    text.setSize(2);
    text.draw("PRESS SPACE TO PLAY AGAIN", g, YELLOW);

    point scoreloc (180, 460);
    text.setLoc(scoreloc);
    text.setSize(2);
    text.draw("SCORE", g, CYAN);

    point scorenum (300, 460);
    currentScore = getScore();
    drawScore(scorenum,g,currentScore,2);

    point lineword (180, 500);
    text.setLoc(lineword);
    text.draw("LINES", g, CYAN);

    point linenum (300, 500);
    currentLine = getLine();
    drawScore(linenum,g,currentLine,2);

    point levelword (180, 540);
    text.setLoc(levelword);
    text.draw("LEVEL", g, CYAN);

    point levelnum (300, 540);
    drawScore(levelnum,g,level,2);
}

void Tetris::eraseScore(point p, SDL_Plotter& g){
    blankTile.setColor(NAVY);
    blankTile.setBorderColor(NAVY);

    for(int i = 0; i < 2;i++){
        for(int j = 0; j < 10; j++){
            if(p.x == 9 * TILE_SIZE){
                p.x = 300;
            }
            blankTile.setLocation(p);
            blankTile.erase(g);
            p.x += TILE_SIZE;
        }
        p.y += TILE_SIZE;
    }
}

void Tetris::drawScore(point p, SDL_Plotter& g, int currentNum, int size){
    stringstream ss;
    string outputString;
    Font text;
    text.setSize(size);

    text.setLoc(p);
    ss.clear();
    ss.str("");
    ss << currentNum;
    outputString = ss.str();
    text.draw(outputString,g, YELLOW);
}
void Tetris::setNewScore(int n){
    score = n;
}
void Tetris::setNewLineTotal(int n){
    line = n;
}

void Tetris::resetLevel(){
    level = 1;
}
