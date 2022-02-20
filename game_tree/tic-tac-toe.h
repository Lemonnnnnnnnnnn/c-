
#include "iostream"
#include <vector>

using namespace std;

#define EMPTY_SPACE '-'
#define PLAYER 'X'
#define AI_PLAYER 'O'
#define WIN 1000
#define LOSS -1000
#define DRAW 0
using cell = pair<int, int>;
#define MAX 99999
#define MIN -99999

class AI_Node
{
public:
    AI_Node(char[3][3]);
    char dynamic_scope[3][3];
    int alpha;
    int beta;
    int score;
    pair<int ,int> next;
};



class board
{
private:
    char scope[3][3];

public:
    friend class AI_Player;
    board();
    int get_board_status();
    pair<int, pair<int, int>> AI_Play(AI_Node, char, AI_Node , int);
    void begin();
    void print();
    //  bool check_over(char[3][3] ,char);
};

