#include<iostream>
using namespace std;
class Base1{
    protected:
    int x;
    public:
    Base1(){
        cout<<"Base1() Called"<<endl;
        x=13;
    }
    void show(){
        cout<<"X: "<<x<<endl;

    }
};
class Base2{
    protected:
    int z;
    public:
    Base2(){
        cout<<"Base2() Called"<<endl;
        z=24;
    }
    void show(){
        cout<<"Z: "<<z<<endl;
    }
};
class Derived: public Base1, public Base2{
    protected:
    int y;
    public:
    Derived(){
        cout<<"Derived() Called"<<endl;
        y=2413;
    }
    // void show(){
    //     cout<<"Y: "<<y<<endl;
    // }
};



int main(){
    Derived d;
    d.Base1::show();
    d.Base2::show();
    
    return(0);
}