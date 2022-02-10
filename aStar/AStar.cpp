#include "AStar.h"
// #include <iostream>

// using namespace std;
AStar::AStar(Node *_start, Node *_end)
{
    start = _start;
    end = _end;
    openList.push_back(start);
}

void AStar::search()
{
}

void AStar::show()
{
    start->show();
    end->show();
    // cout << start->x << endl;
}