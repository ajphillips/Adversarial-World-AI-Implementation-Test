#include "node.h"

Node::Node(){
    footsteps = 0;
    glimmer = 0;
    light = 0;
    rocky = 0;
    smell = 0;
    wind = 0;
    xLoc = 0;
    yLoc = 0;
    //for use with agent classes.
    //1 if explored by human, 2 if explored by monster, 3 if both, 0 otherwise
    explored = 0;
    inNode = '`';
}
/*
Node::Node(int f, int g, int l, int r, int s, int w, int x, int y){
    footsteps = f;
    glimmer = g;
    light = l;
    rocky = r;
    smell = s;
    wind = w;
    xLoc = x;
    yLoc = y;
    inNode = '`';
}
*/

void Node::setAttributes(int f, int g, int l, int r, int s, int w){
    footsteps += f;
    glimmer += g;
    light += l;
    rocky += r;
    smell += s;
    wind += w;
}

void Node::setLoc(int x, int y){
    xLoc = x;
    yLoc = y;
}

void Node::getAttributes(int *resultArr){
    resultArr[0] = footsteps;
    resultArr[1] = glimmer;
    resultArr[2] = light;
    resultArr[3] = rocky;
    resultArr[4] = smell;
    resultArr[5] = wind;
}

void Node::changeNodeObj(char code){
    inNode = code;
}

char Node::getInNode(){
    return inNode;
}

//Returns false if there is nothing in the node, returns true if there is something in the node
bool Node::check(){
    if ((footsteps+glimmer+light+rocky+smell+wind) == 0){
        return false;
    }
    else{
        return true;
    }
}

//one letter difference in variable, be careful here
void Node::setExp(int explorer){
    explored += explorer;
}

int Node::getExp(){
    return explored;
}
