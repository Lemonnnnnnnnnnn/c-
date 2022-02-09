#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
// const int citycount = 29;

#ifndef B
#define B
class City
{
public:
    string name;
    double x, y;
    void shuchu()
    {
        cout << name + ":"
             << "(" << x << "," << y << ")" << endl;
    }
};
#endif