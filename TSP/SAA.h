// #include "Graph.h"
#include "m_random.h"


// 在随机法（爬山法）的基础上加入退火算法
class SAA :public M_Random{
    private:
    int currentT = 5000; // 开始温度
    double endT = 1e-9; // 结束温度
    double delta = 0.999; // 温度变化率 
    double DTMC = 20; // 马尔科夫链长

    public : 
    SAA(string fileName) : M_Random(fileName){};
    double findX();
};