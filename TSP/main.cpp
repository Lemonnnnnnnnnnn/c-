#include "SAA.h"
#include "time.h"

// 随机法参考：https://www.cnblogs.com/linkstar/p/5406577.html
// 退火参考： https://blog.csdn.net/jing_zhong/article/details/109739312
// https://blog.csdn.net/jarvislau/article/details/79939146
// https://blog.csdn.net/qq547276542/article/details/77800776

int main(int, char **)
{
    srand((unsigned)time(NULL));

    time_t start, finish; //计时变量
    start = clock();      //程序运行开始计时

    SAA sa("D:\\c-\\TSP\\in.txt");
    cout << sa.findX() << endl;
    sa.outPath();
    sa.show();

    finish = clock(); //程序结束停止计时
                      //计算运行时间
    double run_time = ((double)(finish - start)) / CLOCKS_PER_SEC;

    cout << "spend time " << run_time << " second" << endl;

    // M_Random mr("D:\\c-\\TSP\\in.txt");
    // cout << mr.findX() << endl;
    // mr.outPath();

    return 0;
}
