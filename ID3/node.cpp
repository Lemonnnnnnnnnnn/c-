#include "node.h"


// 根据play和 notplay计算entropy
double compute_entropy(pair_di deci)
{
    double sum = 0.00;
    int total = deci.first + deci.second;
    sum += deci.first / total * log2(deci.first / total);
    sum += deci.second / total * log2(deci.second / total);
    return -(sum);
}

// 多态, 获取play , notplay的个数
pair_di get_decision(DATA_LIST items)
{
    int play = 0;
    int notplay = 0;
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i).PlayTennis == "play")
        {
            play += 1;
        }
        else
        {
            notplay += 1;
        }
    }
    return make_pair(play, notplay);
}


node::node(trainList *_datas)
{
    datas = _datas;
    decision = "not_over";
}

bool node::checkDecision()
{
    if (!datas->list.size())
    {
        return true; // 如果训练集为空，决策结果唯一
    }
    string deci = datas->list.at(0).PlayTennis;
    for (dataItem item : datas->list)
    {
        if (deci != item.PlayTennis)
        {
            return false;
        }
    }
    decision = deci;
    return true;
}


// 寻找最大的信息增益
void node::find_max_info()
{
    // 计算熵
    double entropy = compute_entropy(get_decision(datas->list));
    // 计算信息增益
    double max_info = -9999;
    string max_attribute;
    for (string attribute : datas->attributes)
    {
        // vector<double> condition_entropy;
        double info = compute_info(attribute, entropy);
        if (info > max_info)
        {
            max_info = info;
            max_attribute = attribute;
        }
    }
    attribute = max_attribute;
}


LIST_MAP node::classify(string attribute)
{

    LIST_MAP sonMap;
    // 将 datas 根据属性attribute的子属性存入map中；
    for (dataItem data : datas->list)
    {
        string sonAttribute = data.getAttribute(attribute);
        LIST_MAP::iterator it = sonMap.find(sonAttribute);
        if (it != sonMap.end())
        { // 如果字典中有当前属性
            DATA_LIST &sonList = sonMap[sonAttribute];
            sonList.push_back(data);
        }
        else
        { // 如果字典中没有当前属性
            DATA_LIST newList;
            newList.push_back(data);
            sonMap[sonAttribute] = newList;
        }
    }
    return sonMap;
}

// 计算信息增益
double node::compute_info(string attribute, double entropy)
{
    LIST_MAP sonMap = classify(attribute);

    LIST_MAP::iterator it = sonMap.begin();
    LIST_MAP::iterator it_end = sonMap.end();
    // 计算条件熵的和
    double condition_entropy_sum = 0;
    while (it != it_end)
    {
        DATA_LIST sonDatas = it->second; // 获取子属性对应的各行
        double sonEntropy = compute_entropy(get_decision(sonDatas));
        condition_entropy_sum += sonEntropy;
        it++;
    }
    return entropy - condition_entropy_sum;
}

