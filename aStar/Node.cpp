#include "Node.h"

void Node::show()
{
    cout << "(x , y) : "
         << "(" << x << " , " << y << ")" << endl;
    cout << "F:" << F << endl;
    cout << "G:" << G << endl;
    cout << "H:" << H << endl;
}

void Node::showParent()
{
    cout << "(x , y) : "
         << "(" << parent->x << " , " << parent->y << ")" << endl;
    cout << "F:" << parent->F << endl;
    cout << "G:" << parent->G << endl;
    cout << "H:" << parent->H << endl;
}

void Node::setF(int f){
    F = f;
}
void Node::setG(int g){
    G = g;
}
void Node::setH(int h){
    F = h;
}

int Node::getx(){
    return x;
}
int Node::gety(){
    return y;
}
int Node::getF(){
    return F;
}
int Node::getG(){
    return G;
}
int Node::getH(){
    return H;
}
bool Node::getVisited(){
    return isVisited;
}