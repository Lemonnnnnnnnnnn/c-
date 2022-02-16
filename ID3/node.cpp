#include "node.h"

node::node(vector<dataItem> _dataList)
{
    dataList = _dataList;
    decision = "not_over";
    // child = NULL;
}

// void node::push_child(node *_node){
//     child = _node;
// };

// vector<dataItem> node::getDataList(){
//     return dataList;
// }

bool node::checkDecision(){
    if(!dataList.size()){
        return true; // 如果训练集为空，决策结果唯一
    }
    string decision = dataList.at(0).getPlayTennis();
    for(dataItem item : dataList){
        if(decision != item.getPlayTennis()){
            return false;
        }
    }
    return true;
}