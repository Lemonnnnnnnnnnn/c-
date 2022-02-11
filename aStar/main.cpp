#include <iostream>
#include "AStar.h"

// 参考：https://blog.csdn.net/A_L_A_N/article/details/81392212
int main(int, char **)
{

    Node start(10, 4);
    Node end(10, 6);

    AStar a(&start, &end);
    // a.show();
    // cout << a.search() << endl;
    a.search();
}
