#include "iostream"
#include <map>
#include <vector>

using namespace std;
class A{
    public :
    string attr1 = "attr1";
};

int main(int argc, char const *argv[])
{
    class A a;
    string attr = "attr1";
    cout << a.attr1 << endl;
    return 0;
}
