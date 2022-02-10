class Node
{
private:
    int x,y;
    int F,G,H;
    Node * parent;
    // bool isVisited;
public:
    Node(int _x , int _y) : x(_x),y(_y),F(0),G(0),H(0),parent(NULL);
};

