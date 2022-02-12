#include "node.h"

node::node(vector<dataItem> _dataList)
{
    dataList = _dataList;
}

void node::push_child(node *_node){
    child = _node;
};

vector<dataItem> node::getDataList(){
    return dataList;
}