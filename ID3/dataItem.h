// #include "require.h"

#ifndef UNQIUE
#define UNQIUE
#include <iostream>

using namespace std;

class dataItem
{
public:
    string OutLook;
    string Temperature;
    string Humidity;
    string Wind;
    string PlayTennis;
    dataItem(string _OutLook,string _Temperature,string _Humidity,string _Wind , string _PlayTennis){
        OutLook = _OutLook;
        Temperature = _Temperature;
        Humidity = _Humidity;
        Wind = _Wind;
        PlayTennis = _PlayTennis;
    };
    string getAttribute(string attribute){
        if(attribute == "outLook"){
            return OutLook;
        }
        if(attribute == "temperature"){
            return Temperature;
        }
        if(attribute == "humidity"){
            return Humidity;
        }
        if(attribute == "wind"){
            return Wind;
        }
        if(attribute == "play"){
            return PlayTennis;
        }
    };
    
};

#endif


