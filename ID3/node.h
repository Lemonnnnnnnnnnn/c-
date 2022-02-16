#include <vector>
#include "dataItem.h"

#pragma once

using namespace std;
class node
{
private:
    vector<dataItem> dataList; // 相关训练数据
    vector<node *> childs;     // 子节点用数组存储
    string decision;           // 如果相关训练数据中的决策同一，记录为play,notplay , 否则为notOver
public:
    node(vector<dataItem>);
    bool checkDecision() ;
    // void push_child(node *);
    // vector<dataItem> getDataList();
};
