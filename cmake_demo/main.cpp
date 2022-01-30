#include <iostream>
#include <string>
 
#include "./math/add.h"
 
int main()
{
    int ret_add;
    std::cout << "Hello, this is my first cmake sample" << std::endl;
 
    ret_add = Add(1, 2);
    std::cout << ret_add << std::endl;
    return 0;
}