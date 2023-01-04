#include <iostream>
using namespace std;

namespace n1
{
    int x = 20;
    void func()
    {
        cout << "n1 func() called" << endl;
    }
}
namespace n2
{
    int x = 40;
    void func()
    {
        cout << "n2 func() called" << endl;
    }
    namespace nested_n2
    {
        void func()
        {
            cout << "nested namespace" << endl;
        }
    }
}
namespace n3
{
    int x;
    void show();
}
void n3::show()
{
    cout << n3::x << endl;
}
int val=100;
int main()
{
    int x = 3;
    cout << x << endl;
    // n1::func();
    // n2::func();
    cout << n2::x << endl;
    cout << n1::x << endl;

    using namespace n1;
    func();
    func();
    n3::x = 13;
    n3::show();

    n2::nested_n2::func();
    int val=200;
    cout<<val<<endl;    //local
    cout<<::val<<endl;  //global
    cerr<<"error";
    cout<<"hello";
}
