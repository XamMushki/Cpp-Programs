#include <iostream>
using namespace std;
/*STATIC BINDING*/
// class base
// {
// protected:
//     int x;

// public:
//     void show()
//     {
//         cout << "Base Class" << endl;
//     }
// };
// class derv1 : public base
// {
// public:
//     void show()
//     {
//         cout << "derv1 class" << endl;
//     }
// };
// class derv2 : public derv1
// {
// public:
//     void show()
//     {
//         cout << "derv2 class" << endl;
//     }
// };

// int main()
// {
//     derv2 d2;
//     derv1 d1;
//     base b;
//     base *bp;
//     bp = &b;
//     bp->show(); // base class show() called

//     bp = &d1;
//     bp->show(); // still base class show() called

//     derv1 * dp1; // static binding
//     dp1=&d2;
//     dp1->show(); // derv1 show() called

//     return (0);
// }

/*DYNAMIC BINDING*/

class base
{
protected:
    int x;

public:
    base(){};
    virtual void show()
    {
        cout << "Base Class" << endl;
    }
    virtual ~base()
    {
        cout << "base destructor called" << endl;
    }
};
class derv1 : virtual public base
{
public:
    derv1(){};
    ~derv1()
    {
        cout << "derv1 destructor called" << endl;
    }
    void show()
    {
        cout << "derv1 class" << endl;
    }
};
class derv2 : public derv1
{
public:
    void show()
    {
        cout << "derv2 class" << endl;
    }
};

int main()
{
    derv2 d2;
    derv1 d1;
    base b;
    base *bp;
    bp = &b;
    bp->show(); // base class show() called

    // bp = &d1;
    // bp->show();  // derv1 class show() called

    // bp = &d2;
    // bp->show();  // derv2 class show() called

    // derv1 *dd1 = new derv1();
    // base *bptr = dd1;
    // bptr->show();

    // delete bptr;

    return (0);
}