#include "dataItem.h"
#include <vector>
#include <map>

class trainList
{
public:
    vector<dataItem > data;
    vector<string> attributes;
    map<string, vector<string>> map_attribute;
    trainList(string);
    // double E; // 信息熵
    // double CE[4] ; // 条件熵
    // double info ; // 信息增益
    // public:
    // void updateList(vector<dataItem *>); // 当决策了其中一个分支后，其他的分支应该被剪枝
    // void setE();
    // void setInfo();
    // double computeE(int ,int , int);
};
