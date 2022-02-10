#include "Graph.h"
#include "algorithm"
/*
方法：随机法
思路：维护一个行走顺序数组，交换其中两个并计算走遍所有城市的距离，若发现更小的，则更新结果。
*/
class M_Random : public Graph
{
protected:
    int x[citycount]; // 解（行走顺序）
    // int bestX[citycount]; // 最优解
    int minDis; // 解距离
    int tryNumber;

public:
    M_Random(string fileName) : Graph(fileName)
    {
        minDis = 99999999;
        tryNumber = 20000;
        for (int i = 0; i < citycount; i++)
        {
            x[i] = i; // 初始化序列
        }
    };
    double computeDis();
    double findX();
    virtual void outPath();
};