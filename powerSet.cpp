#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // initializing set A (array).
    int set_a_size;
    cout << "Enter set A size: ";
    cin >> set_a_size;
    string set_a[set_a_size];
    cout << "Enter " << set_a_size << " elements of set A." << endl;
    for (int i = 0; i < set_a_size; i++)
    {
        cin >> set_a[i];
    }

    // declaring power set.
    int power_set_size = pow(2, set_a_size);
    string power_set[power_set_size];
    
    /* Generating power set using bitwise AND operator.
     we need all possible combinations of 1 and 0, i.e, nCr, where n =2 (i.e, 1,0) and
     r = size of set A (user input).(000,001,010,100,011,110,101,111) if r=3.
     In order to achieve all the combinations, we use bitwise AND (&) operator, which returns 1 when
     one of the corresponding bits of the two operands are 1. e.g, 5&3 gives 1. (i.e, 101 & 011 = 001,
     which returns 1.) */
    for (int i = 0; i < power_set_size; i++)
    {
        string temp = "";

        for (int j = 0; j < set_a_size; j++)
        {
            // & is bitwise AND
            int x = pow(2, j);
            if ((i & x))
            {
                if (temp != "")
                {
                    temp += ",";
                }
                temp += set_a[j];
            }
        }
        power_set[i] = temp;
    }
    //printing set A on screen
    cout<<"A = {";
    for (int i = 0; i < set_a_size; i++)
    {
        cout<<set_a[i];
        if (i<set_a_size-1)
        {
            cout<<", ";
        }
    }cout<<"}"<<endl;
    

    //printing Power Set on screen
    cout << "P({A}) = { ";
    for (int i = 0; i < power_set_size; i++)
    {
        cout << "{" << power_set[i];
        if (i < power_set_size)
        {
            cout << "}";
        }
        if (i < power_set_size - 1)
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;
    cout<<"Total Number of Power Set elements: "<<power_set_size<<endl;
    return 0;
}
