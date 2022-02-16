#include "iostream"
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    using pair_sv = pair<string, vector<string>>;
    using map_sv = map<string, vector<string>>;
    map_sv a;
    string b("b");
    for (int i = 0; i < 2; i++)
    {
        map_sv::iterator lt = a.find(b);

        if (lt != a.end())
        {
            vector<string> &d = a[b];
            d.push_back("222");
        }
        else
        {
            vector<string> c;
            c.push_back("123");
            a.insert(pair_sv(b, c));
        }
    }

    cout << a[b][0] << endl;
    cout << a[b][1] << endl;

    return 0;
}
