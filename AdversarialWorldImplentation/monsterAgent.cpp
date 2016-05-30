#include "monsterAgent.h"

Monster::Monster(){
    item = '`';
}

Monster::Monster(int xLoc, int yLoc, Node startNode){
    item = '`';
    location[0] = xLoc;
    location[1] = yLoc;

    weightAtts[0] = 0;
    weightAtts[1] = 2;
    weightAtts[2] = 0;
    weightAtts[3] = 0;
    weightAtts[4] = -2;
    weightAtts[5] = -2;

    weightDirs[0] = 0;
    weightDirs[1] = 0;
    weightDirs[2] = 0;
    weightDirs[3] = 0;

    riskFactor = 0.1;

    currNode = startNode;

    knownMap = new Node*[10];
    for (int row = 0; row < 10; row++){
        knownMap[row] = new Node[10];
        for (int el = 0; el < 10; el++){
            knownMap[row][el].setLoc(row, el);
        }
    }
    knownMap[xLoc][yLoc] = startNode;
    knownMap[xLoc][yLoc].setExp(1);
}

void Monster::setItem(char obj){
    item = obj;
}

char Monster::getItem(){
    return item;
}

void Monster::moveSpace(int xLoc, int yLoc, Node targetNode){
    location[0] = xLoc;
    location[1] = yLoc;
    currNode = targetNode;
    knownMap[xLoc][yLoc] = currNode;
    if (knownMap[xLoc][yLoc].getExp() == 0 || knownMap[xLoc][yLoc].getExp() == 2){
        knownMap[xLoc][yLoc].setExp(1);
    }
}

void Monster::update(Node **wholeMap){
    for (int row = 1; row < 9; row++){
        for(int col = 1; col < 9; col++){
            knownMap[row][col].getAttributes(tempAtts1);
            for (int comp = 0; comp < 6; comp++){
                if (comp == 1){
                }
                else if (comp == 1 || comp == 2 || comp == 5){
                    knownMap[row-1][col-1].getAttributes(tempAtts2);
                    knownMap[row+1][col-1].getAttributes(tempAtts3);
                    if ((tempAtts1[comp] + tempAtts2[comp] + tempAtts3[comp]) >= 3){
                        knownMap[row][col-1].changeNodeObj(wholeMap[row][col-1].getInNode());
                    }
                    knownMap[row+1][col-1].getAttributes(tempAtts2);
                    knownMap[row+1][col+1].getAttributes(tempAtts3);
                    if ((tempAtts1[comp] + tempAtts2[comp] + tempAtts3[comp]) >= 3){
                        knownMap[row+1][col].changeNodeObj(wholeMap[row+1][col].getInNode());
                    }
                    knownMap[row+1][col+1].getAttributes(tempAtts2);
                    knownMap[row-1][col+1].getAttributes(tempAtts3);
                    if ((tempAtts1[comp] + tempAtts2[comp] + tempAtts3[comp]) >= 3){
                        knownMap[row][col+1].changeNodeObj(wholeMap[row][col+1].getInNode());
                    }
                    knownMap[row-1][col+1].getAttributes(tempAtts2);
                    knownMap[row-1][col-1].getAttributes(tempAtts3);
                    if ((tempAtts1[comp] + tempAtts2[comp] + tempAtts3[comp]) >= 3){
                        knownMap[row-1][col].changeNodeObj(wholeMap[row-1][col].getInNode());
                    }
                }
                else{
                    knownMap[row-1][col-1].getAttributes(tempAtts2);
                    if ((tempAtts1[comp] + tempAtts2[comp]) >= 2){
                        knownMap[row][col-1].changeNodeObj(wholeMap[row][col-1].getInNode());
                    }
                    knownMap[row+1][col-1].getAttributes(tempAtts2);
                    if ((tempAtts1[comp] + tempAtts2[comp]) >= 2){
                        knownMap[row+1][col].changeNodeObj(wholeMap[row+1][col].getInNode());
                    }
                    knownMap[row+1][col+1].getAttributes(tempAtts2);
                    if ((tempAtts1[comp] + tempAtts2[comp]) >= 2){
                        knownMap[row][col+1].changeNodeObj(wholeMap[row][col+1].getInNode());
                    }
                    knownMap[row-1][col+1].getAttributes(tempAtts2);
                    if ((tempAtts1[comp] + tempAtts2[comp]) >= 2){
                        knownMap[row-1][col].changeNodeObj(wholeMap[row-1][col].getInNode());
                    }
                }
            }
        }
    }
}

int Monster::decideMove(){
   //Different for Monster and Monster agents
   //Implement different weights
}

int Monster::decideDir(int corner, int edge){
    //corner = 1 means the bottom left, 2 means bottom right, 3 means top left, and 4 means top right, 0 means no corner
    //edge = 1 means bottom, 2 means right, 3 meanas top, 4 means left, 0 means none
    switch (corner){
        case 1:
            if (weightDirs[0] > weightDirs[1]){
                return 1;}
            else if (weightDirs[1] > weightDirs[0]){
                return 2;}
            else{
                return 0;}
        case 2:
            if (weightDirs[0] > weightDirs[3]){
                return 1;}
            else if (weightDirs[3] > weightDirs[0]){
                return 4;}
            else{
                return 0;}
        case 3:
            if (weightDirs[1] > weightDirs[2]){
                return 2;}
            else if (weightDirs[2] > weightDirs[1]){
                return 3;}
            else{
                return 0;}
        case 4:
            if (weightDirs[1] > weightDirs[3]){
                return 2;}
            else if (weightDirs[3] > weightDirs[1]){
                return 4;}
            else{
                return 0;}
    }
    switch (edge){
        case 1:
            if (weightDirs[0] > weightDirs[1] && weightDirs[0] > weightDirs[3]){
                return 1;}
            else if (weightDirs[1] > weightDirs[0] && weightDirs[1] > weightDirs[3]){
                return 2;}
            else if (weightDirs[3] > weightDirs[1] && weightDirs[3] > weightDirs[0]){
                return 4;}
            else{
                return 0;}
        case 2:
            if (weightDirs[1] > weightDirs[0] && weightDirs[1] > weightDirs[2]){
                return 2;}
            else if (weightDirs[2] > weightDirs[0] && weightDirs[2] > weightDirs[1]){
                return 3;}
            else if (weightDirs[0] > weightDirs[2] && weightDirs[0] > weightDirs[1]){
                return 1;}
            else{
                return 0;}
        case 3:
            if (weightDirs[1] > weightDirs[2] && weightDirs[1] > weightDirs[3]){
                return 2;}
            else if (weightDirs[2] > weightDirs[1] && weightDirs[2] > weightDirs[3]){
                return 3;}
            else if (weightDirs[3] > weightDirs[1] && weightDirs[3] > weightDirs[2]){
                return 4;}
            else{
                return 0;}
        case 4:
            if (weightDirs[3] > weightDirs[0] && weightDirs[3] > weightDirs[2]){
                return 4;}
            else if (weightDirs[0] > weightDirs[2] && weightDirs[0] > weightDirs[3]){
                return 1;}
            else if (weightDirs[2] > weightDirs[3] && weightDirs[2] > weightDirs[0]){
                return 3;}
            else{
                return 0;}
    }
}

bool Monster::canPickUp(Node cNode){
    if (cNode.getInNode() == '!' || cNode.getInNode() == '$'){
        return true;
    }
    else{
        return false;
    }
}

Monster::~Monster(){
    delete [] knownMap;
}
