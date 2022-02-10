#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "City.h"
using namespace std;

#ifndef A
#define A
const int citycount = 29;

class Graph
{
public:
    Graph(string);
    void show();

protected:
    int CityCount;
    City *city;                            // 城市数组
    double distance[citycount][citycount]; // 城市间距离
};

#endif