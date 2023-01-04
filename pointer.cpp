#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string x = "xam20.3";

    void *ptr;
    ptr = &x;
    cout << *((string *)ptr) << endl;

    int *p1 = NULL;
    cout << p1 << endl;
    ;

    // Pointer to Array
    int arr[5] = {2, 32, 13, 24, 7};
    int *p2;
    p2 = arr; // assigns address of first element of arr to *p2
    cout << p2 << endl;
    cout << &arr[0] << endl;
    cout << *p2 << endl;
    cout << &(*(p2 + 1)) << endl;
    *(p2 + 1) = 2413;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << *(p2 + i) << ", ";
    }
    cout << endl;
    cout << *(arr + 1) << endl;

    {
        // Pointer to Pointer
        cout << "Pointer to Pointer" << endl;

        int n = 20;
        int *ptr;
        ptr = &n;
        cout << *ptr << endl;
        int **p2;
        p2=&ptr;
        cout<<*p2<<endl;
        cout<<ptr<<endl;
        cout<<p2<<endl;
        cout<<&n<<endl;
        cout<<**p2<<endl;
        cout<<&ptr<<endl;
    }
    {
        cout<<"Pointer to Strings"<<endl;
        char name[16]={'Z','a','h','i','d','\0'};
        cout<<name<<endl;
        char* p;
        p= name;
        cout<<*(p+3)<<endl;

        string n="Zahid";
        string *p1;
        p1=&n;
        cout<<*p1<<endl;
        cout<<size(n)<<endl;

    }
    {
        cout<<"Problems with pointers"<<endl;
        int x =13;
        int* p2;
        p1=&x;
        p2=p1;
        cout<<*p2<<endl;
        cout<<*p1<<endl;
    }
    return (0);
}