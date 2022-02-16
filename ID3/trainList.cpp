#include "trainList.h"


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
        allClass ac; 
        
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
                ac[0].push_back({day , playTennis});
                ac[1].push_back({outLook , playTennis});
                ac[2].push_back({Temperature , playTennis});
                ac[3].push_back({Humidity , playTennis});
                ac[4].push_back({Wind , playTennis});
                dataItem *newItem = new dataItem(day, outLook, Temperature, Humidity, Wind, playTennis);
                data.push_back(*newItem);
            }
        }
        for(int i = 0 ; i < attributes.size() - 1 ; i ++){
            map_attribute[attributes[i]] = ac[i];
        }
    }
}

