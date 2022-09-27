#include <iostream>
using namespace std;

int main()
{
    int set_a_size;
    int set_b_size;

    // Set A declaration and initialization
    cout << "Enter set A size: ";
    cin >> set_a_size;
    string set_a[set_a_size];
    cout << "Enter " << set_a_size << " elements of set A: " << endl;
    for (int i = 0; i < set_a_size; i++)
    {
        cin >> set_a[i];
    }

    // Set B declaration and initialization
    cout << "Enter set B size: ";
    cin >> set_b_size;
    string set_b[set_b_size];
    cout << "Enter " << set_b_size << " elements of set A: " << endl;
    for (int i = 0; i < set_b_size; i++)
    {
        cin >> set_b[i];
    }

    // Cartesian Product A x B
    int cp_size = set_a_size * set_b_size;
    string cp[cp_size];
    int counter = 0;
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_b_size; j++)
        {
            string temp = "";
            temp = set_a[i] + "," + set_b[j];

            cp[counter] = temp;
            counter++;
        }
    }

    // Generating output on the screen
    cout<<"Cartesian Product"<<endl;
    cout << "AxB = { ";
    for (int i = 0; i < cp_size; i++)
    {
        cout << "(" << cp[i] << ")";
        if (i < cp_size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}