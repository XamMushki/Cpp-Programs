#include <iostream>

using namespace std;

// Base class
class A
{
public:
    A()
    {
        cout << "A() called" << endl;
    }
};
class B : virtual public A
{
public:
    B()
    {
        cout << "B() called" << endl;
    }
};
class C : virtual public A
{
public:
    C()
    {
        cout << "C() called" << endl;
    }
};
class D : public B, public C
{
public:
    D()
    {
        cout << "D() called" << endl;
    }
};

int main()
{
      D d;
    return (0);
}