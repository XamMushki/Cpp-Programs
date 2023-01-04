#include <iostream>
using namespace std;

class student
{
private:
    int x;

public:
    student(){};
    void putData(int x)
    {
        this->x = x;
    }
    void getData()
    {
        cout << "x: " << x << endl;
    }
    // copy constructor - created by compiler if not present
    student(student &s)
    {
        x=s.x;
    }
};

int main()
{
    student s1;
    s1.putData(13);
    s1.getData();
    // student s2(s1);
    //OR
    student s2;
    s2 = s1;
    s2.getData();
    return (0);
}