#include "iostream"
#include <vector>
#include <map>

using namespace std;

template <class T>
using Map_s_T = map<string, T>;

int main(int argc, char const *argv[])
{
    Map_s_T<int> m_map; // int传递给T , map类型为< string , int>
    m_map.insert({"second", 1});

    // cout << map[second] << endl;

    return 0;
}
