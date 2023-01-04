#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
struct student
{
    string name;
    int age;
};
void printStructure(struct student *p){
    cout<<"Name: () "<<p->name<<endl;
}
int main()
{
    int x = 5, y = 13;
    cout << "X: " << x << "\tY: " << y << endl;
    swap(&x, &y);
    cout << "X: " << x << "\tY: " << y << endl;

    {
        cout << "Pointer to structure" << endl;
        struct student s;
        s.name="Zahid";
        s.age=13;
        
        cout<<"Name: "<<s.name<<endl;
        cout<<"Age: "<<s.age<<endl;
        struct student *ps;
        ps=&s;
        ps->name="Amin";
        cout<<"New Name: "<<ps->name<<endl;
        // printStructure(ps);  or
        printStructure(&s);

    }
}