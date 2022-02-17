#include "dataItem.h"
#include "require.h"
#pragma once

class trainList
{
public:
    DATA_LIST list;
    vector<string> attributes;
    trainList(string);
    trainList(DATA_LIST , vector<string>);
};
