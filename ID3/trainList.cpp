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
        string outLook;
        string Temperature;
        string Humidity;
        string Wind;
        string playTennis;

        bool firstLine = true;
        
        while (!myfile.eof())
        {
            myfile  >> outLook >> Temperature >> Humidity >> Wind >> playTennis;
            if (firstLine)
            {
                attributes.push_back(outLook);
                attributes.push_back(Temperature);
                attributes.push_back(Humidity);
                attributes.push_back(Wind);
                attributes.push_back(playTennis);
                firstLine = false;
            }
            else
            {
                dataItem *newItem = new dataItem( outLook, Temperature, Humidity, Wind, playTennis);
                list.push_back(*newItem);
            }
        }
    }
}

trainList::trainList(DATA_LIST dataList, vector<string> attribute){
    list = dataList;
    attributes = attribute;
}