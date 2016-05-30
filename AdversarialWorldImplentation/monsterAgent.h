#ifndef MONSTERAGENT_H_INCLUDED
#define MONSTERAGENT_H_INCLUDED
#include "Node.h"

class Monster{
    public:
        Monster();
        Monster(int xLoc, int yLoc, Node startNode);
        ~Monster();
        void setItem(char obj);
        void moveSpace(int xLoc, int yLoc, Node targetNode);
        void update(Node **wholeMap);
        int decideMove();
        int decideDir(int corner, int edge);
        bool canPickUp(Node cNode);
        char getItem();
    private:
        char item;
        double riskFactor;
        int location[2];
        int weightAtts[6];
        int weightDirs[4];
        int *tempAtts1, *tempAtts2, *tempAtts3;
        bool win;
        Node **knownMap;
        Node currNode;
};

#endif // MONSTERAGENT_H_INCLUDED
