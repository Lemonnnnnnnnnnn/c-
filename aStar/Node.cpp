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