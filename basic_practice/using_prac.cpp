#include "iostream"

using namespace std;

class ClassOne
{
private:
    int w;
    /* data */
public:
    int a;
};


int main(){
    // cout << "hello world" << endl;
    int a = 0;
    using C  = ClassOne;
    C c;
    c.a = 123;
    cout << c.a << endl;
    return 0;
}