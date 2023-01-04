#include <iostream>
using namespace std;

class Student
{
private:
    int x;

public:
    Student() { cout << "default constructor called" << endl; };

    friend int getPrivateValue(Student); // friend function declaration

    void putData(int x)
    {
        this->x = x;
    }
    // Operator overloading
    Student operator+(Student s)
    {
        Student sr;
        sr.x = x + s.x;
        return (sr);
    }
    Student add(Student s)
    {
        Student sr;
        sr.x = s.x + x;
        return (sr);
    }
    int getData()
    {
        return (x);
    }
};
int getPrivateValue(Student s)
{
    int y = s.x;
    return(y);
}
int main()
{
    Student s1, s2, s3;
    s1.putData(3);
    s2.putData(5);

    // s3 = s1.add(s2); // can be replaced using Operator overloading.

    s3 = s1 + s2; // Operator Overloading

    cout << "Sum: " << s3.getData() << endl;

    {
        cout << "Friend Function" << endl;
        Student s;
        s.putData(13);
        // cout<<s.x<<endl;    //ERROR, x is inaccessible
        cout<<getPrivateValue(s)<<endl;
        
    }
    return (0);
}