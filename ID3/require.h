#pragma once

#include <vector>
#include <map>
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

using classDataRow = pair<string, string>; // 保存属性名和决策
using classData = vector<classDataRow>;    // 一种属性所有行数据  
using allClass = vector<classData>;        // 所有属性的所有行数据
using mapClass = map<string , classData>;  
using pair_di = pair<int , int>;
// using pair_sc = pair<string , classData>;
