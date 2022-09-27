#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter Universal Set size: ";
    cin >> n;
    int *universal_set = new int(n);

    cout << "Enter " << n << " elements of Universal Set: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> universal_set[i];
    }

    // printing Universal Set on screen
    cout << "make sure elements belong to this domain." << endl;
    cout << "US = {";
    for (int i = 0; i < n; i++)
    {
        cout << universal_set[i] << ", ";
    }
    cout << "}" << endl;

    // Set A
    int temp_n;
    cout << "Enter set A size: ";
    cin >> temp_n;
    int *set_a = new int(n);
    for (int i = 0; i < n; i++)
    {
        set_a[i] = 0;
    }

    cout << "Enter set A elements: ";
    for (int i = 0; i < temp_n; i++)
    {
        // retrieving Set A elements and assigning value 1 if it belongs to universal set else 0 in set_a.

        int temp;
        cin >> temp;
        for (int i = 0; i < n; i++)
        {
            if (universal_set[i] == temp)
            {
                set_a[i] = 1;
            }
        }
    }
    // Set B
    cout << "Enter set B size: ";
    cin >> temp_n;
    int *set_b = new int(n);
    for (int i = 0; i < n; i++)
    {
        set_b[i] = 0;
    }

    cout << "Enter set B elements: ";
    for (int i = 0; i < temp_n; i++)
    {
        // retrieving Set A elements and assigning value 1 if it belongs to universal set else 0 in set_b.

        int temp;
        cin >> temp;
        for (int i = 0; i < n; i++)
        {
            if (universal_set[i] == temp)
            {
                set_b[i] = 1;
            }
        }
    }
    // printing Universal Set on screen
    cout << "US = {";
    for (int i = 0; i < n; i++)
    {
        cout << universal_set[i] << ", ";
    }
    cout << "}" << endl;
    // printing set A on screen
    cout << "A = {";
    for (int i = 0; i < n; i++)
    {
        if (set_a[i] == 1)
        {
            cout << universal_set[i] << ", ";
        }
    }
    cout << "}" << endl;
    // printing set B on screen
    cout << "B = {";
    for (int i = 0; i < n; i++)
    {
        if (set_b[i] == 1)
        {
            cout << universal_set[i] << ", ";
        }
    }
    cout << "}" << endl;

    // Set Operations
    // subset
    // proper subset

    // Set A
    int flag_a = 1;
    for (int i = 0; i < n; i++)
    {
        if (set_a[i] == 0)
        {
            flag_a = 0; // i.e, There is some element in US which is not in set A.
            break;
        }
    }
    if (flag_a == 0)
    {
        cout << "Set A is Proper Subset of Universal Set" << endl;
    }
    else
    {
        cout << "Set A is Subset of Universal Set" << endl;
    }

    // Set B
    int flag_b = 1;
    for (int i = 0; i < n; i++)
    {
        if (set_b[i] == 0)
        {
            flag_b = 0; // i.e, There is some element in US which is not in set B.
            break;
        }
    }
    if (flag_b == 0)
    {
        cout << "Set B is Proper Subset of Universal Set" << endl;
    }
    else
    {
        cout << "Set A is Subset of Universal Set" << endl;
    }
    cout << endl;
    // Set operations
    // Intersection
    int count_i = 0;
    int *intersection_set = new int(n);
    for (int i = 0; i < n; i++)
    {
        if (set_a[i] == 1 && set_b[i] == 1)
        {
            intersection_set[count_i] = universal_set[i];
            count_i++;
        }
    }
    // printing Intersection set on screen
    cout << "A Intersection B = {";
    for (int i = 0; i < count_i; i++)
    {
        cout << intersection_set[i] << ", ";
    }
    cout << "}" << endl;

    // Union
    int *union_set = new int(n);
    int count_u = 0;
    for (int i = 0; i < n; i++)
    {
        if (set_a[i] == 1 || set_b[i] == 1)
        {
            union_set[count_u] = universal_set[i];
            count_u++;
        }
    }

    // printing Union set on screen
    cout << "A Union B= {";
    for (int i = 0; i < count_u; i++)
    {
        cout << union_set[i] << ", ";
    }
    cout << "}" << endl;

    return 0;
}