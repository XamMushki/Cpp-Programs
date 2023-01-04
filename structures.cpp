#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
};
void print(struct Student arr[])
{
    cout << "Name: " << arr[0].name << endl;
    cout << "Age: " << arr[0].age << endl;
    cout << "Name: " << arr[1].name << endl;
    cout << "Age: " << arr[1].age << endl;
    // s->age=23;
}
int main()
{
    struct Student arr[2];
    arr[0].name = "Zahid";
    arr[0].age = 20;
    arr[1].name = "Amin";
    arr[1].age = 40;
    print(arr);
    // cout<<"New Age: "<<s1.age<<endl;
    return (0);
}