#ifndef HUMANAGENT_H_INCLUDED
#define HUMANAGENT_H_INCLUDED
#include "node.h"

class Human{
    public:
        Human();
        Human(int xLoc, int yLoc, Node startNode);
        ~Human();
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

#endif // HUMANAGENT_H_INCLUDED
