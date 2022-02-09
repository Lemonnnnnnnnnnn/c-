#include "m_random.h"

int main(int, char **)
{
    //  随机法参考：https://www.cnblogs.com/linkstar/p/5406577.html
    // 退火参考： https://blog.csdn.net/jing_zhong/article/details/109739312
    // https://blog.csdn.net/jarvislau/article/details/79939146
    // https://blog.csdn.net/qq547276542/article/details/77800776
    M_Random mr("D:\\c-\\TSP\\in.txt");
    mr.show();
    // Graph Map_City("D:\\c-\\TSP\\in.txt");
    return 0;
}
