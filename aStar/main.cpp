#include <iostream>
#include "AStar.h"

// 参考：https://blog.csdn.net/A_L_A_N/article/details/81392212
int main(int, char **)
{

    Node start(10, 40);
    Node end(40, 10);

    AStar a(&start, &end);
    a.show();
}
