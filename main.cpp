#include <iostream>
#include "individual.h"
#include "groupRange.h"
#include <vector>
#include <random>
#include <ctime>
using namespace std;



void InitGroup();

void InitGroup(){
    default_random_engine e(time(0)); // 时间种子，可以看作随机强度
    uniform_real_distribution<double> u(chromosomeRange[0].getLow() , chromosomeRange[0].getHigh()) ; // 定义随机范围
    cout << u(e) << endl;
}

int main(int, char **)
{
    InitGroup();
    
}
