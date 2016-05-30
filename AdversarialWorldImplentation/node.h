#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED


/***REWRITE SOME ATTRIBUTE CALCULATIONS***/
class Node
{
public:
	Node();
	//Node(int f, int g, int l, int r, int s, int w, int x, int y);
	~Node(){};
    void setAttributes(int f, int g, int l, int r, int s, int w);
    void getAttributes(int *resultArr);
    void setLoc(int x, int y);
    void changeNodeObj(char code);
    void setExp(int explorer);
    int getExp();
    char getInNode();
    bool check();
private:
    int footsteps, glimmer, light, rocky, smell, wind, xLoc, yLoc, explored;
    char inNode;
};

#endif // NODE_H_INCLUDED
