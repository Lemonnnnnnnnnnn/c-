#include "dataItem.h"
#include "trainList.h"

#pragma once

class node
{
public:
    trainList* datas; // 相关训练数据
    string attribute; // 信息增益最大的属性
    string decision;           // 如果相关训练数据中的决策同一，记录为play,notplay , 否则为notOver
    vector<node *> childs;     // 子节点用数组存储

    node(trainList*);
    bool checkDecision() ;
    double compute_info(string , double);
    void find_max_info();
    LIST_MAP classify(string);
};
