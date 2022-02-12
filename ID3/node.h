#include <vector>
#include "dataItem.h"

#pragma once

using namespace std;
class node
{
private:
    vector<dataItem> dataList;
    node* child;
    /* data */
public:
    node(vector<dataItem>);
    void push_child(node*);
    vector<dataItem> getDataList();
};
