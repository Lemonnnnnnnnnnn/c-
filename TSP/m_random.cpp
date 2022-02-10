#include "m_random.h"

void swap(double &x, double &y)
{
    double temp = x;
    x = y;
    y = temp;
}

// 计算当前行走顺序下的距离
double M_Random::computeDis()
{
    int disSum = 0;
    for (int i = 0; i < citycount - 1; i++)
    {
        disSum += distance[x[i]][x[i + 1]];
    }
    return disSum;
}

double M_Random::findX()
{
    for (int i = 0; i < tryNumber; i++)
    {
        double answer = computeDis();
        if (answer < minDis)
        {
            minDis = answer;
        }

        // 随机交换x序列
        int a = rand() % citycount;
        int b = rand() % citycount;
        while (a == b)
        {
            a = rand() % citycount;
            b = rand() % citycount;
        }
        swap(x[a], x[b]);
    }
    return minDis;
}

void M_Random::outPath()
{
    for (int i = 0; i < citycount; i++)
    {
        if (i != citycount - 1)
        {
            cout << city[x[i]].name << " -> ";
        }
        else
        {
            cout << city[x[i]].name << endl;
        }
    }
}