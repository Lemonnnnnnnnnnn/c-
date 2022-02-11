#include "AStar.h"
#include "cmath"

AStar::AStar(Node *_start, Node *_end)
{
    start = _start;
    end = _end;
    // 计算start的F,G,H
    start->setH(abs(end->getx() - start->getx()) + abs(end->gety() - start->gety()));
    start->setF(start->getH());
    openList.push_back(start); // 将起始位置添加进开启列表中
    preNode = NULL;
}

void AStar::search()
{
    while (!searchTarget())
    {               // 如果目标格不在“开启列表中”
        findNext(); // 走一步,并把周围8格加入openList
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



bool AStar::searchTarget()
{
    for (int i = 0; i < openList.size(); i++)
    {
        if (openList[i]->getx() == end->getx() && openList[i]->gety() == end->gety())
        {
            end->setParent(preNode);
            return true;
        }
    }
    return false;
}

void AStar::findNext()
{
    Node *nextNode;
    int minF = 99999;
    // 遍历开启列表，查找F值最低的格子
    for (int i = 0; i < openList.size(); i++)
    {
        if (openList[i]->getVisited())
        {
            continue;
        }
        if (openList[i]->getF() < minF)
        {
            minF = openList[i]->getF();
            nextNode = openList[i];
        }
    }
    // 走一步
    nextNode->setParent(preNode);
    nextNode->setVisited(true);
    setpreNode(nextNode);

    cout << "next position: ";
    cout << "(" << nextNode->getx() << " , " << nextNode->gety() << ")";
    cout << " , ";
    cout << "distance end : " << nextNode->getH() << endl;
    closeList.push_back(nextNode);
    // 设置周围8格的F,G,H
    setArround(nextNode);
}

void AStar::trace()
{
    Node *temp = end;
    temp->show();
    while (temp->parent)
    {
        cout << " -> ";
        temp->showParent();
        temp = temp->parent;
    }
}



void AStar::setArround(Node *n)
{
    int i, j; // i为x坐标，j为y坐标
    int currentX = n->getx();
    int currentY = n->gety();
    for (i = currentX - 1; i <= currentX + 1; i++)
    {
        for (j = currentY - 1; j <= currentY + 1; j++)
        {

            if (i == currentX && j == currentY)
            { // 跳过当前节点的位置
                continue;
            }
            //判断当前遍历的节点是否在关闭列表中
            bool isInClose = searchCloseList(i, j);
            // 如果在关闭列表中，跳过当前节点
            if (isInClose)
            {
                continue;
            }

            // 判断当前遍历的节点是否在打开列表中
            bool isInOpen = searchOpenList(i, j);

            // 如果没在打开列表中，更新H,G,F ， 并加入打开列表
            if (!isInOpen)
            {
                Node *newNode = new Node(i, j);
                newNode->setH(abs(end->getx() - i) + abs(end->gety() - j));
                newNode->setG(abs(start->getx() - i) + abs(start->gety() - j));
                newNode->setF(newNode->getG() + newNode->getH());
                openList.push_back(newNode);
            }
        }
    }
}

bool AStar::searchCloseList(int x, int y)
{
    for (int i = 0; i < closeList.size(); i++)
    {
        if (closeList[i]->getx() == x && closeList[i]->gety() == y)
        {
            return true;
        }
    }
    return false;
}




bool AStar::searchOpenList(int x, int y)
{
    bool isInOpen = false;

    // 判断当前遍历的节点是否在打开列表中
    for (int k = 0; k < openList.size(); k++)
    {
        if (openList[k]->getx() == x && openList[k]->gety() == y)
        {
            isInOpen = true;
            if (openList[k]->getVisited())
            { // 如果被访问过，跳出循环
                break;
            }
            else
            { // 如果没被访问过，比较新旧F值，更新节点数值，并跳出循环
                int newH = abs(end->getx() - x) + abs(end->gety() - y);
                int newG = abs(start->getx() - x) + abs(start->gety() - y);
                int newF = newH + newG;
                if (newF < openList[k]->getF())
                {
                    openList[k]->setH(newH);
                    openList[k]->setG(newG);
                    openList[k]->setF(newF);
                }
                break;
            }
        }
    }
    return isInOpen;
}



void AStar::setpreNode(Node *node)
{
    preNode = node;
}


