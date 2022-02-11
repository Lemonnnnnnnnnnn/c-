#include "AStar.h"

AStar::AStar(Node *_start, Node *_end)
{
    start = _start;
    end = _end;
    // 计算start的F,G,H
    start->setG(end->getx() - start->getx() + end->gety() - start->gety());
    start->setH(start->getG());
    openList.push_back(start); // 将起始位置添加进开启列表中
}

void AStar::search()
{
    while (!openList.size() || !searchTarget())
    { // 如果目标格不在“开启列表中”
        findNext(); // 走一步
        
    }
    // 目标格在“开启列表中”，沿着每一格的父节点移动到起始格
    if (!openList.size())
    {
        cout << "路径不存在" << endl;
    }
    else
    {
        trace();
    }
}

void AStar::setArround()
{
}

void AStar::findNext()
{
    Node *nextNode;
    int minF = 99999;
    // 遍历开启列表，查找F值最低的格子
    for (int i = 0; i < openList.size(); i++)
    {
        if (openList[i]->getF() < minF)
        {
            minF = openList[i]->getF();
            nextNode = openList[i];
        }
    }
    // 走一步
    nextNode->setVisited(true);
    closeList.push_back(nextNode);
    // 设置周围8格的F,G,H
}

void AStar::trace()
{
    Node *temp = end;
    temp->show();
    while (temp->parent)
    {
        temp->showParent();
    }
}

bool AStar::searchTarget()
{
    for (int i = 0; i < openList.size(); i++)
    {
        if (openList[i] == end)
        {
            return true;
        }
    }
    return false;
}

void AStar::show()
{
    start->show();
    end->show();
    // cout << start->x << endl;
}