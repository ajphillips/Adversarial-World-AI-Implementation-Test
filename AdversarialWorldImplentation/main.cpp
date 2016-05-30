#include <iostream>
#include "node.h"
#include "humanAgent.h"
#include "monsterAgent.h"

using namespace std;

void displayMap(Node **m);

void changeMap(Node **m, int row, int col, char obj, int *a);


int main()
{
    cout << "Adversarial world" << endl;

    Node **gameMap;
    int *nodeAtts;
    nodeAtts = new int[6];
    // 0 = footsteps, 1 = glimmer, 2 = light,
    // 3 = rocky, 4 = smell, 5 = wind

    gameMap = new Node*[10];
    for (int row = 0; row < 10; row++){
        gameMap[row] = new Node[10];
        for (int el = 0; el < 10; el++){
            gameMap[row][el].setLoc(row, el);
        }
    }

    changeMap(gameMap, 0, 1, '!', nodeAtts);
    changeMap(gameMap, 4, 6, 'O', nodeAtts);
    changeMap(gameMap, 7, 9, 'M', nodeAtts);
    changeMap(gameMap, 2, 5, 'H', nodeAtts);
    changeMap(gameMap, 5, 7, '$', nodeAtts);
    changeMap(gameMap, 4, 4, '@', nodeAtts);
    changeMap(gameMap, 3, 2, '*', nodeAtts);
    changeMap(gameMap, 1, 9, '#', nodeAtts);
    displayMap(gameMap);

/***Small Test 1***
    gameMap[0][2].getAttributes(nodeAtts);
    cout<<"Sword is near?"<<endl;
    if (nodeAtts[1] > 0){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }

    changeMap(gameMap,2,3,'!',nodeAtts);
    changeMap(gameMap,0,1,'`',nodeAtts);
    displayMap(gameMap);

    gameMap[0][2].getAttributes(nodeAtts);
    cout<<"Sword is near?"<<endl;
    if (nodeAtts[1] > 0){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }

    changeMap(gameMap,1,2,'$',nodeAtts);
    displayMap(gameMap);
    gameMap[0][2].getAttributes(nodeAtts);
    cout<<"Sword is near after new object?"<<endl;
    if (nodeAtts[1] > 0){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }

    changeMap(gameMap,0,1,'!',nodeAtts);
    changeMap(gameMap,2,3,'`',nodeAtts);
    displayMap(gameMap);
    gameMap[0][2].getAttributes(nodeAtts);
    cout<<"Sword is near after new object?"<<endl;
    if (nodeAtts[1] > 0){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }
***/
/***Small test 2***
    gameMap[0][2].getAttributes(nodeAtts);
    cout<<"Sword is near?"<<endl;
    if (nodeAtts[1] == 1){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }

    gameMap[4][5].getAttributes(nodeAtts);
    cout<<"Pit is near?"<<endl;
    if (nodeAtts[5] == 1){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }

    gameMap[6][9].getAttributes(nodeAtts);
    cout<<"Monster is near?"<<endl;
    if (nodeAtts[4] == 1){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }
***/

    cout<<endl;

    delete [] gameMap;
    return 0;
}

//Displays game map data to screen referencing gameMap array of node objects
void displayMap(Node **m){
    for (int j = 0; j < 10; j++){
        cout<<"+ - + - + - + - + - + - + - + - + - + - +"<<endl;
        for (int k = 0; k < 10; k++){
            cout<<"| "<<m[j][k].getInNode()<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<"+ - + - + - + - + - + - + - + - + - + - +"<<endl;
}

//modifies the game map by changing the object at the specified gameMap node
//also sets attributes for surrounding nodes
void changeMap(Node **m, int row, int col, char obj, int *a){
    char temp;
    temp = m[row][col].getInNode();
    m[row][col].changeNodeObj(obj);
    //When the character entered for obj is " ' "
    //set attribute value to zero for the attribute type that moved
    if (obj == '`'){
        if (row == 9){
        }
        else{
            m[row+1][col].getAttributes(a);
            switch(temp){
                case 'M':
                    m[row+1][col].setAttributes(a[0], a[1], a[2], a[3], -1, a[5]);
                    break;
                case 'H':
                    m[row+1][col].setAttributes(-1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row+1][col].setAttributes(a[0], a[1], a[2], a[3], a[4], -1);
                    break;
                case '!':
                    m[row+1][col].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row+1][col].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row+1][col].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row+1][col].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row+1][col].setAttributes(a[0], a[1], a[2], -1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
        if (row == 0){
        }
        else{
            m[row-1][col].getAttributes(a);
            switch(temp){
                case 'M':
                    m[row-1][col].setAttributes(a[0], a[1], a[2], a[3], -1, a[5]);
                    break;
                case 'H':
                    m[row-1][col].setAttributes(-1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row-1][col].setAttributes(a[0], a[1], a[2], a[3], a[4], -1);
                    break;
                case '!':
                    m[row-1][col].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row-1][col].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row-1][col].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row-1][col].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row-1][col].setAttributes(a[0], a[1], a[2], -1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
        if (col == 9){
        }
        else{
            m[row][col+1].getAttributes(a);
            switch(temp){
                case 'M':
                    m[row][col+1].setAttributes(a[0], a[1], a[2], a[3], -1, a[5]);
                    break;
                case 'H':
                    m[row][col+1].setAttributes(-1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row][col+1].setAttributes(a[0], a[1], a[2], a[3], a[4], -1);
                    break;
                case '!':
                    m[row][col+1].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row][col+1].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row][col+1].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row][col+1].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row][col+1].setAttributes(a[0], a[1], a[2], -1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
        if (col == 0){
        }
        else{
            m[row][col-1].getAttributes(a);
            switch(temp){
                case 'M':
                    m[row][col-1].setAttributes(a[0], a[1], a[2], a[3], -1, a[5]);
                    break;
                case 'H':
                    m[row][col-1].setAttributes(-1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row][col-1].setAttributes(a[0], a[1], a[2], a[3], a[4], -1);
                    break;
                case '!':
                    m[row][col-1].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row][col-1].setAttributes(a[0], -1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row][col-1].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row][col-1].setAttributes(a[0], a[1], -1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row][col-1].setAttributes(a[0], a[1], a[2], -1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
    }
    //When the character entered for obj is anything other than " ` "
    //Set attribute value for type of object that is being placed here
    else{
        if (row == 9){
        }
        else{
            m[row+1][col].getAttributes(a);
            switch(obj){
                case 'M':
                    m[row+1][col].setAttributes(a[0], a[1], a[2], a[3], 1, a[5]);
                    break;
                case 'H':
                    m[row+1][col].setAttributes(1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row+1][col].setAttributes(a[0], a[1], a[2], a[3], a[4], 1);
                    break;
                case '!':
                    m[row+1][col].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row+1][col].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row+1][col].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row+1][col].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row+1][col].setAttributes(a[0], a[1], a[2], 1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
        if (row == 0){
        }
        else{
            m[row-1][col].getAttributes(a);
            switch(obj){
                case 'M':
                    m[row-1][col].setAttributes(a[0], a[1], a[2], a[3], 1, a[5]);
                    break;
                case 'H':
                    m[row-1][col].setAttributes(1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row-1][col].setAttributes(a[0], a[1], a[2], a[3], a[4], 1);
                    break;
                case '!':
                    m[row-1][col].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row-1][col].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row-1][col].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row-1][col].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row-1][col].setAttributes(a[0], a[1], a[2], 1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
        if (col == 9){
        }
        else{
            m[row][col+1].getAttributes(a);
            switch(obj){
                case 'M':
                    m[row][col+1].setAttributes(a[0], a[1], a[2], a[3], 1, a[5]);
                    break;
                case 'H':
                    m[row][col+1].setAttributes(1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row][col+1].setAttributes(a[0], a[1], a[2], a[3], a[4], 1);
                    break;
                case '!':
                    m[row][col+1].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row][col+1].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row][col+1].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row][col+1].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row][col+1].setAttributes(a[0], a[1], a[2], 1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
        if (col == 0){
        }
        else{
            m[row][col-1].getAttributes(a);
            switch(obj){
                case 'M':
                    m[row][col-1].setAttributes(a[0], a[1], a[2], a[3], 1, a[5]);
                    break;
                case 'H':
                    m[row][col-1].setAttributes(1, a[1], a[2], a[3], a[4], a[5]);
                    break;
                case 'O':
                    m[row][col-1].setAttributes(a[0], a[1], a[2], a[3], a[4], 1);
                    break;
                case '!':
                    m[row][col-1].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '$':
                    m[row][col-1].setAttributes(a[0], 1, a[2], a[3], a[4], a[5]);
                    break;
                case '*':
                    m[row][col-1].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '#':
                    m[row][col-1].setAttributes(a[0], a[1], 1, a[3], a[4], a[5]);
                    break;
                case '@':
                    m[row][col-1].setAttributes(a[0], a[1], a[2], 1, a[4], a[5]);
                    break;
            }
            for (int e = 0; e < 6; e++){
                a[e] = 0;
            }
        }
    }
}
