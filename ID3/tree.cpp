#include "tree.h"


// 所有叶子节点都是唯一结果，返回True
bool tree::checkLeftNode()
{
    if (TR.empty())
    {
        return false;
    }
    bool allUnqiue = true;
    for (int i = 0; i < TR.size(); i++)
    {
        node *currentNode = TR[i];
        vector<dataItem> currentDataItem = currentNode->getDataList();
        if (currentDataItem.empty())
        {
            continue;
        }
        string decision = currentDataItem.at(0).getPlayTennis();
        for (int j = 0; j < currentDataItem.size(); i++)
        {
            if (currentDataItem.at(j).getPlayTennis() != decision)
            {
                allUnqiue = false;
            }
        }
    }
    return allUnqiue;
}