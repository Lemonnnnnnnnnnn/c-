#include "Graph.h"

Graph::Graph(string fileName)
{
    CityCount = citycount;
    city = new City[citycount];
    ifstream myfile(fileName, ios::in);

    if (myfile.fail())
    {
        cout << "文件不存在" << endl;
    }
    else
    {
        int i = 0;
        while (!myfile.eof())
        {
            myfile >> city[i].name >> city[i].x >> city[i].y;

            i++;
        }
    }
    myfile.close();
    for (int i = 0; i < citycount; i++)
    {
        for (int j = 0; j < citycount; j++)
        {
            distance[i][j] = sqrt(pow((city[i].x - city[j].x), 2) + pow((city[i].y - city[j].y), 2)); //计算城市ij之间的距离
        }
    }
}

void Graph::show()
{
    cout << "show :" << endl;
    for (int i = 0; i < citycount; i++)
    {
        cout << city[i].name << setw(10) << city[i].x << setw(10) << city[i].y << endl;
    }
    cout << endl;
    for (int i = 0; i < citycount; i++)
    {
        for (int j = 0; j < citycount; j++)
        {
            cout << distance[i][j] << endl;
        }
    }
}