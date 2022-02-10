#include "SAA.h"
#include "random"

double SAA::findX()
{
    for (int i = 0; i < tryNumber; i++)
    {
        int tempX[citycount];
        memcpy(tempX, x, sizeof(x));

        // 达到目标温度，结束
        if (currentT <= endT)
        {
            break;
        }

        // 随机交换x序列
        int a = rand() % citycount;
        int b = rand() % citycount;
        while (a == b)
        {
            a = rand() % citycount;
            b = rand() % citycount;
        }
        swap(tempX[a], tempX[b]);

        double answer = computeDis();
        /*
        若新路径更短，直接取用
        若新路径不会更优，以一定概率接收
        */
        if (answer < minDis) // 找到更小的路径，接受
        {
            memcpy(x, tempX, sizeof(tempX));
            minDis = answer; // 找到更大的路径，一定概率接受
        }
        else
        {
            /*
           差值： de
           常数系数： kT ，常取当前温度
           接收的概率： P(de) = exp(de / k*T) ，注：底数为e， 指数(de / k * T)小于0，概率总在 0-1 之间
           注： 温度不断降低，de / currentT不断变小（负数），P不断接近 0
           */

            default_random_engine e(time(0));
            uniform_real_distribution<double> u(0.00, 1.00);
            double rd = u(e); // 若 P(de) 大于rd ，则接受

            double de = minDis - answer;
            double p = exp(de / currentT);
            
            if (p > rd)
            {
                memcpy(x, tempX, sizeof(tempX));
                minDis = answer;
            }
        }

        currentT *= delta;
    }
    return minDis;
}
