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
        string day;
        string outLook;
        string Temperature;
        string Humidity;
        string Wind;
        string playTennis;

        bool firstLine = true;
        vector<vector<string>> typeDataArray;
        
        while (!myfile.eof())
        {
            myfile >> day >> outLook >> Temperature >> Humidity >> Wind >> playTennis;
            if (firstLine)
            {
                attributes.push_back(day);
                attributes.push_back(outLook);
                attributes.push_back(Temperature);
                attributes.push_back(Humidity);
                attributes.push_back(Wind);
                attributes.push_back(playTennis);
            }
            else
            {
                typeDataArray[0].push_back(day);
                typeDataArray[1].push_back(outLook);
                typeDataArray[2].push_back(Temperature);
                typeDataArray[3].push_back(Humidity);
                typeDataArray[4].push_back(Wind);
                typeDataArray[5].push_back(playTennis);
                dataItem newItem = new dataItem(day, outLook, Temperature, Humidity, Wind, playTennis);
                data.push_back(newItem);
            }
        }
        for(int i = 0 ; i < attributes.size() ; i ++){
            map_attribute[attributes[i]] = typeDataArray[i];
        }
    }
}

// void trainList::updateList(vector<dataItem *> newList)
// {
//     list = newList;
// }

// void trainList::setE()
// {
//     double sum = 0.00;
//     int play = 0;
//     int notplay = 0;
//     int total = list.size();
//     for (int i = 0; i < list.size(); i++)
//     {
//         if (list.at(i)->getPlayTennis() == "yes")
//         {
//             play += 1;
//         }
//         else
//         {
//             notplay += 1;
//         }
//     }
//     E = computeE(play, notplay, total);
// }

// double trainList::computeE(int play, int notplay, int total)
// {
//     double sum = 0.00;
//     sum += play / total * log2(play / total);
//     sum += notplay / total * log2(notplay / total);
//     return -(sum);
// }
