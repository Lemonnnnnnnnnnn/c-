#include <iostream>
using namespace std;

#ifndef a
#define a
class dataItem
{
private:
    int Day;
    string OutLook;
    string Temperature;
    string Humidity;
    string Wind;
    string PlayTennis;
    /* data */
public:
    dataItem(int _Day,string _OutLook,string _Temperature,string _Humidity,string _Wind , string _PlayTennis){
        Day = _Day;
        OutLook = _OutLook;
        Temperature = _Temperature;
        Humidity = _Humidity;
        Wind = _Wind;
        PlayTennis = _PlayTennis;
    };
    string getOutLook(){return OutLook;};
    string getTemperature(){return Temperature;};
    string getHumidity(){return Humidity;};
    string getWind(){return Wind;};
    string getPlayTennis(){return PlayTennis;};
};

#endif

