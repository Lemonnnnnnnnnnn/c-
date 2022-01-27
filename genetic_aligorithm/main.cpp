#include <iostream>
#include "individual.h"
#include "groupRange.h"
#include <vector>
#include <random>
#include <ctime>
#include <math.h>
using namespace std;

//常数
const int groupNumber = 50;   // 种群数
const double variationP = 0.01 ; // 变异概率
const double crossP = 0.8; // 杂交概率
const int evolutionNumber = 500 ; // 进化代数
vector<Individual> initGroup; // 当前种群组
vector<Individual> midGroup;  // 轮盘选择出的种群组
vector<Individual> nextGroup; // 下一种群组

// 函数
void InitGroup();       // 初始化所有种群
void CaculateFitness(); // 计算适应值
double FitnessFunc();   // 适应值函数
void CaculateFitnessP(); // 适应值概率  适应值越高 -> 适应值概率越大 -> 被选择的概率越大

void InitGroup()
{
    double initArray[groupNumber][chromosomeNumber];
    for (int i = 0; i < chromosomeNumber; i++)
    {
        default_random_engine e(time(0));                                                               // 时间种子，可以看作随机强度
        uniform_real_distribution<double> u(chromosomeRange[i].getLow(), chromosomeRange[i].getHigh()); // 定义随机范围
        for (int j = 0; j < groupNumber; j++)
        {
            initArray[j][i] = u(e); 
        }
    }

    for (int i = 0; i < groupNumber; i++)
    {
        Individual currentGroup(initArray[i]);
        initGroup.push_back(currentGroup);
    }
}

double FitnessFunc(double x1, double x2)
{
    // f(x1,x2) = 21.5+x1*sin(4pi*x1)+x2*sin(20pi*x2)）为适应度计算函数
    return 21.5 + x1 * sin(4 * M_PI * x1) + x2 * sin(20 * M_PI * x2);
}

void CaculateFitness()
{
    // 对染色体执行固定函数，结果为适应值
    double currentChromosome[chromosomeNumber];
    for (int i = 0; i < groupNumber; i++)
    {
        Individual currentGroup = initGroup.at(i);

        for (int j = 0; j < chromosomeNumber; j++)
        {
            currentChromosome[j] = currentGroup.getChromosome()[j];
            double fitness = FitnessFunc(currentChromosome[0], currentChromosome[1]);
            currentGroup.setFitness(fitness);
        }
    }
}

void CaculateFitnessP(){
    // 个体适应值 / 总体适应值之和 等于个体适应值概率
    double sum;
    for (int i = 0; i < groupNumber; i++)
    {
        Individual currentGroup = initGroup.at(i);
        sum += currentGroup.getFitness();
    }
    for (int i = 0; i < groupNumber; i++)
    {
        Individual currentGroup = initGroup.at(i);
        double currentFitness = currentGroup.getFitness();
        double currentFitnessP = currentFitness / sum;
        currentGroup.setFitnessProbability(currentFitnessP);
    }
}

int main(int, char **)
{
    InitGroup();
    cout << "process success" << endl;
}
