#include <vector>
using namespace std;

class Node{
    public:
    int value;
    int alpha; // MAX层值
    int beta;  // MIN层值
    int high;
    vector<Node *>  childs;
    Node(int);
};

class basicAlgorithm{
    public:
    basicAlgorithm();
    Node * rootTree;
    // void init();
    int process(Node*  , Node * , int);
};