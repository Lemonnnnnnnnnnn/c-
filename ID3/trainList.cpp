#include "trainList.h"
#include <iostream>
#include <cmath>
#include <fstream>

trainList::trainList(string fileName)
{
    ifstream myfile(fileName, ios::in);
    if (myfile.fail())
    {
        cout << "文件不存在" << endl;
    }
    else
    {
        int day;
        string outLook;
        string Temperature;
        string Humidity;
        string Wind;
        string playTennis;

        while (!myfile.eof())
        {
            myfile >> day >> outLook >> Temperature >> Humidity >> Wind >> playTennis;
            dataItem *newItem = new dataItem(day, outLook, Temperature, Humidity, Wind, playTennis);
            list.push_back(newItem);
        }
    }
}

void trainList::updateList(vector<dataItem *> newList)
{
    list = newList;
}

void trainList::setE()
{
    double sum = 0.00;
    int play = 0;
    int notplay = 0;
    int total = list.size();
    for (int i = 0; i < list.size(); i++)
    {
        if (list.at(i)->getPlayTennis() == "yes")
        {
            play += 1;
        }
        else
        {
            notplay += 1;
        }
    }
    E = computeE(play, notplay, total);
}

double trainList::computeE(int play, int notplay, int total)
{
    double sum = 0.00;
    sum += play / total * log2(play / total);
    sum += notplay / total * log2(notplay / total);
    return -(sum);
}
