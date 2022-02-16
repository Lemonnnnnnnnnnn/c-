#include "dataItem.h"
#include "trainList.h"

#pragma once

class node
{
private:
    // vector<dataItem> dataList; // 
    trainList* datas; // 相关训练数据
    vector<node *> childs;     // 子节点用数组存储
    string decision;           // 如果相关训练数据中的决策同一，记录为play,notplay , 否则为notOver
public:
    node(trainList*);
    bool checkDecision() ;

    double compute_info(string);
    string find_max_info();
    double compute_condition_entropy();
    double compute_entropy(pair_di);
    pair_di get_decision(vector<dataItem> );
    // void push_child(node *);
    // vector<dataItem> getDataList();
};
