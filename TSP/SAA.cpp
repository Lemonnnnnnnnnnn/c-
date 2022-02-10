#include "SAA.h"
#include "random"

double SAA::findX()
{
    int a = 0;
    while (currentT > endT)
    {
        a += 1;
        for (int i = 0; i < DTMC; i++) // 随机交换
        {
            int tempX[citycount];
            memcpy(tempX, x, sizeof(x)); // 复制前一个解

            // 随机交换x序列
            int a = rand() % citycount;
            int b = rand() % citycount;
            while (a == b)
            {
                a = rand() % citycount;
                b = rand() % citycount;
            }
            swap(tempX[a], tempX[b]);

            double newDis = computeDis();
            /*
            若新路径更短，直接取用
            若新路径不会更优，以一定概率接收
            */
            if (newDis < minDis) // 找到更小的路径，接受
            {
                memcpy(x, tempX, sizeof(tempX));
                minDis = newDis; 
            }
            else
            {
                /*
               差值： de
               常数系数： kT ，常取当前温度
               接收的概率： P(de) = exp(de / k*T) ，注：底数为e， 指数(de / k * T)小于0，概率总在 0-1 之间
               注： 温度不断降低，de / currentT不断变小（负数），P不断接近 0 ，趋于不接受
               */

                default_random_engine e(time(0));
                uniform_real_distribution<double> u(0.00, 1.00);
                double rd = u(e); // 若 P(de) 大于rd ，则接受

                double de = minDis - newDis;
                double p = exp(de / currentT);

                if (p > rd)
                {
                    memcpy(x, tempX, sizeof(tempX));
                    minDis = newDis;
                }
            }
        }

        currentT *= delta;
    }
    cout << a << endl;
    return minDis;
}
