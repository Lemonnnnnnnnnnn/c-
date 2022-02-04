#include <iostream>
#include <math.h>
#include <random>
#include <time.h>
#include "./individual.h"
#include "./groupRange.h"
#include <iostream>
#include <iomanip>
#include <bitset>

void InitGroup();           // 初始化所有种群
void CaculateFitness();     // 计算适应值
double FitnessFunc();       // 适应值函数
void CaculateFitnessP();    // 适应值概率  适应值越高 -> 适应值概率越大 -> 被选择的概率越大
void CaculateFitnessPSum(); // 计算累计概率  用于轮盘赌
void Select();              // 选择方法（轮盘赌）
void Crossing();            // 杂交
void variating();           // 变异
void evolution();           //进化
// double randomDouble();      // 产生0-1之间的随机数

using namespace std;
//常数
const int chromosome_accuracy = 24; // 精确度位数
const int individualNumber = 50;    // 个体数
const double variationP = 0.01;     // 变异概率
const double crossP = 0.8;          // 杂交概率
const int evolutionNumber = 500;    // 进化代数
vector<Individual> newGroup;        // 当前种群组
vector<Individual> midGroup;        // 轮盘选择出的种群组
vector<Individual> nextGroup;       // 下一种群组

double FitnessFunc(double x1, double x2)
{
    // f(x1,x2) = 21.5+x1*sin(4pi*x1)+x2*sin(20pi*x2)）为适应度计算函数
    return 21.5 + x1 * sin(4 * M_PI * x1) + x2 * sin(20 * M_PI * x2);
}

// double randomDouble()
// {
//     default_random_engine e(time(0));                // 时间种子，可以看作随机强度
//     uniform_real_distribution<double> u(0.00, 1.00); // 定义随机范围
//     return u(e);
// }

void InitGroup()
{
    double initArray[individualNumber][chromosomeNumber];
    for (int i = 0; i < chromosomeNumber; i++)
    {
        default_random_engine e(time(0));                                                               // 时间种子，可以看作随机强度
        uniform_real_distribution<double> u(chromosomeRange[i].getLow(), chromosomeRange[i].getHigh()); // 定义随机范围
        for (int j = 0; j < individualNumber; j++)
        {
            initArray[j][i] = u(e);
        }
    }

    for (int i = 0; i < individualNumber; i++)
    {
        Individual currentGroup(initArray[i]);
        newGroup.push_back(currentGroup);
    }
}

void CaculateFitness()
{
    // 对染色体执行固定函数，结果为适应值
    double currentChromosome[chromosomeNumber];
    for (int i = 0; i < individualNumber; i++)
    {
        Individual &currentGroup = newGroup.at(i);

        for (int j = 0; j < chromosomeNumber; j++)
        {
            currentChromosome[j] = currentGroup.getChromosome()[j];
            double fitness = FitnessFunc(currentChromosome[0], currentChromosome[1]);
            currentGroup.setFitness(fitness);
        }
    }
}

void CaculateFitnessP()
{
    // 个体适应值 / 总体适应值之和 等于个体适应值概率
    double sum = 0;
    for (int i = 0; i < individualNumber; i++)
    {
        Individual currentGroup = newGroup.at(i);
        sum += currentGroup.getFitness();
    }
    for (int i = 0; i < individualNumber; i++)
    {
        Individual &currentGroup = newGroup.at(i);
        double currentFitness = currentGroup.getFitness();
        double currentFitnessP = currentFitness / sum;
        currentGroup.setFitnessProbability(currentFitnessP);
    }
}

void CaculateFitnessPSum()
{
    double sum = 0;
    for (int i = 0; i < individualNumber; i++)
    {
        Individual &currentGroup = newGroup.at(i);
        sum += currentGroup.getFitnessProbability();
        currentGroup.setFitnessSum(sum);
    }
}

/*
轮盘赌选择法可用如下过程模拟来实现：
(1)在[0,1]内产生一个均匀分布的随机数r。
(2)若r ≤ q1，则群组 x1 被选中。
(3)若r > q1 且 r <= q2, 则群组x2被选中。
其中的qi称为群组xi(i=1,2,…,N)的积累概率

被选中的群组加入中间群组，进入下一阶段处理

*/
void Select()
{
    double randomArray[individualNumber];
    default_random_engine e(time(0));                // 时间种子，可以看作随机强度
    uniform_real_distribution<double> u(0.00, 1.00); // 定义随机范围
    for (int i = 0; i < individualNumber; i++)
    {
        randomArray[i] = u(e);
    }

    for (int i = 0; i < individualNumber; i++) // 做50次轮盘赌
    {
        for (int j = 0; j < individualNumber; j++) // 在0-1中找到赌中的那个区间
        {
            if (randomArray[i] <= newGroup.at(j).getFitnessSum())
            {
                midGroup.push_back(newGroup.at(j));
                break;
            }
            else
            {
                if (j + 1 < individualNumber && randomArray[i] <= newGroup.at(j + 1).getFitnessSum())
                {
                    midGroup.push_back(newGroup.at(j + 1));
                    break;
                }
            }
        }
    }
    newGroup.clear();
}
/*
1. 相邻两两杂交，杂交生成两个孩子，以保证群体数量不变
2. 随机生成概率p，当杂交概率crossP 大于 p时进行杂交，否则直接将当前选择的个体基因复制给下一代
3. 对每一个染色体逐个进行杂交，
    用bitset将父母的每个染色体 十进制转二进制 ，
    用rand()生成交叉点，交叉点之后的位置父母染色体两两互换实现杂交
4. 如果孩子的区间不属于种群区间，将父母的个体基因赋值给下一代（同2）
*/
void Crossing()
{
    default_random_engine e(time(0));                // 时间种子，可以看作随机强度
    uniform_real_distribution<double> u(0.00, 1.00); // 定义随机范围
    for (int i = 0; i < individualNumber; i += 2)    // 相邻两两杂交
    {
        double p = u(e);
        if (crossP > p)
        {
            // 双亲染色体数组
            double fatherChromosome[chromosomeNumber];
            double motherChromosome[chromosomeNumber];

            double newArrayChild1[chromosomeNumber];
            double newArrayChild2[chromosomeNumber];

            memcpy(fatherChromosome, midGroup.at(i).getChromosome(), sizeof(midGroup.at(i).getChromosome()));
            memcpy(motherChromosome, midGroup.at(i + 1).getChromosome(), sizeof(midGroup.at(i + 1).getChromosome()));
            // 编码并单点杂交
            for (int j = 0; j < chromosomeNumber; j++) //对每一个染色体逐个进行杂交
            {
                // 十进制转二进制
                bitset<chromosome_accuracy> fatherBit(fatherChromosome[j] * pow(10, 6)); // 加大数值后编码，增加精确度
                bitset<chromosome_accuracy> motherBit(motherChromosome[j] * pow(10, 6));
                // 交叉点
                int crossPoint = rand() % chromosome_accuracy;
                // 交换
                for (int k = crossPoint; k < chromosome_accuracy; k++)
                {
                    double temp = fatherBit[k];
                    fatherBit[k] = motherBit[k];
                    motherBit[k] = temp;
                }
                // 解码
                newArrayChild1[j] = double(fatherBit.to_ullong()) / pow(10, 6); // 先解码后还原
                newArrayChild2[j] = double(motherBit.to_ullong()) / pow(10, 6);
            }

            bool child1Success = true;
            bool child2Success = true;

            //如果孩子的区间不属于种群区间，将父母的个体基因赋值给下一代
            for (int j = 0; j < chromosomeNumber; j++)
            {
                if (newArrayChild1[j] < chromosomeRange[j].getLow() || newArrayChild1[j] > chromosomeRange[j].getHigh())
                {
                    nextGroup.push_back(midGroup[i]);
                    nextGroup.push_back(midGroup[i + 1]);
                    child1Success = false;
                    break;
                }
                if (newArrayChild2[j] < chromosomeRange[j].getLow() || newArrayChild2[j] > chromosomeRange[j].getHigh())
                {
                    nextGroup.push_back(midGroup[i]);
                    nextGroup.push_back(midGroup[i + 1]);
                    child2Success = false;
                    break;
                }
                /* code */
            }

            if (child1Success && child2Success)
            {
                Individual newChild1(newArrayChild1);
                Individual newChild2(newArrayChild2);
                nextGroup.push_back(newChild1);
                nextGroup.push_back(newChild2);
            }
        }
        else
        {
            nextGroup.push_back(midGroup[i]);
            nextGroup.push_back(midGroup[i + 1]);
        }
    }
    midGroup.clear();
}

void variating()
{
    default_random_engine e(time(0));                // 时间种子，可以看作随机强度
    uniform_real_distribution<double> u(0.00, 1.00); // 定义随机范围
    for (int i = 0; i < individualNumber; i++)
    {
        double p = u(e);
        if (variationP > p)
        {
            double chromosomeBit[chromosomeNumber]; // 二进制
            double chromosome[chromosomeNumber];    // 十进制

            memcpy(chromosomeBit, nextGroup.at(i).getChromosome(), sizeof(nextGroup.at(i).getChromosome()));
            bitset<chromosome_accuracy> chromosome1(chromosome[0] * pow(10, 6));
            bitset<chromosome_accuracy> chromosome2(chromosome[1] * pow(10, 6));

            int variatingPoint = rand() % chromosome_accuracy;
            // 变异
            chromosome1.flip();
            chromosome2.flip();

            chromosome[0] = double(chromosome1.to_ullong()) / pow(10, 6);
            chromosome[1] = double(chromosome2.to_ullong()) / pow(10, 6);

            bool chromosome_success = true;
            for (int j = 0; j < chromosomeNumber; j++)
            {
                if (chromosome[j] < chromosomeRange[j].getLow() || chromosome[j] > chromosomeRange[j].getHigh())
                {
                    newGroup.push_back(nextGroup.at(i));
                    chromosome_success = false;
                    break;
                }
            }
            if (chromosome_success)
            {
                Individual variating_individual(chromosome);
                newGroup.push_back(variating_individual);
            }
        }
        else
        {
            newGroup.push_back(nextGroup.at(i));
        }
    }
}

void evolution()
{
    const int interval = 20;
    InitGroup();

    cout << "init" << endl;
    cout << "chromosome_1" << setw(interval) << "chromosome_2" << setw(interval) << "chromosome_fitness" << endl;
    for (int i = 0; i < individualNumber; i++)
    {
        cout << newGroup.at(i).getChromosome()[0] << setw(interval) << newGroup.at(i).getChromosome()[1] << setw(interval) << newGroup.at(i).getFitness() << endl;
    }
    for (int i = 0; i < evolutionNumber; i++)
    {
        CaculateFitness();
        CaculateFitnessP();
        CaculateFitnessPSum();
        Select();
        Crossing();
        variating();
    }
    cout << "over" << endl;
    cout << "chromosome_1" << setw(interval) << "chromosome_2" << setw(interval) << "chromosome_fitness" << endl;
    for (int i = 0; i < individualNumber; i++)
    {
        cout << newGroup.at(i).getChromosome()[0] << setw(interval) << newGroup.at(i).getChromosome()[1] << setw(interval) << newGroup.at(i).getFitness() << endl;
    }
}

int main(int, char **)
{
    evolution();
}
