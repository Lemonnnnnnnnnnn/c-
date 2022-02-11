#include <iostream>

using namespace std;

/*
 G : 距离起点距离
 H ： 距离终点距离
 F : G + H
*/
class Node
{
private:
    int x, y;
    int F, G, H;
    bool isVisited;

public:
    Node *parent;
    Node(int _x, int _y) : x(_x), y(_y), F(0), G(0), H(0), parent(NULL), isVisited(false){};
    void show();
    void showParent();
    void setParent(Node *);
    void setF(int);
    void setG(int);
    void setH(int);
    void setVisited(bool);
    int getx();
    int gety();
    int getF();
    int getG();
    int getH();
    bool getVisited();
};
