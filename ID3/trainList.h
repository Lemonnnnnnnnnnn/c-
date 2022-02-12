#include "dataItem.h"
#include <vector>

class trainList
{
private:
    vector<dataItem *> list;
    double E; // 信息熵
    // double CE[4] ; // 条件熵
    double info ; // 信息增益
    /* data */
public:
    trainList(string);
    void updateList(vector<dataItem *>); // 当决策了其中一个分支后，其他的分支应该被剪枝
    void setE();
    void setInfo();
    double computeE(int ,int , int);
};

