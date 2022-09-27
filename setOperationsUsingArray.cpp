#include <iostream>
using namespace std;

void printSet(int set_to_print[], int set_u[], int size, string text)
{
    int flag = 0;
    cout << text << "{";
    for (int i = 0; i < size; i++)
    {
        if (set_to_print[i] == 1)
        {
            if (flag > 0)
            {
                cout << ", ";
            }

            cout << set_u[i];
            flag++;
        }
    }
    cout << "}" << endl;
}

int main()
{
    int set_u_size;
    cout << "Enter size |U| = ";
    cin >> set_u_size;

    // initializing universal set U.
    int set_u[set_u_size];
    int set_a_union_b[set_u_size], set_a_intersection_b[set_u_size],
        set_a_complement[set_u_size], set_b_complement[set_u_size],
        set_a_difference_b[set_u_size], set_b_difference_a[set_u_size];
    cout << "Enter elements of set U:" << endl;
    for (int i = 0; i < set_u_size; i++)
    {
        cin >> set_u[i];
    }
    int set_a_size, set_b_size;               // used for retrieving the set elements.
    int set_a[set_u_size], set_b[set_u_size]; // set A and set B have same size as the universal set U.
    // initializing every element as 0, because c/c++ does not auto initialize.(else we will get random values)
    // and by doing this, we only need to assign 1's.
    for (int i = 0; i < set_u_size; i++)
    {
        set_a[i] = 0;
        set_b[i] = 0;
        set_a_union_b[i] = 0;
        set_a_intersection_b[i] = 0;
        set_a_complement[i] = 0;
        set_b_complement[i] = 0;
        set_a_difference_b[i] = 0;
        set_b_difference_a[i] = 0;
    }

    cout << "Enter size |A| = ";
    cin >> set_a_size;
    // retrieving set A elements and assigning 1's and 0's in set A with respect to the universal set U.
    cout << "Enter " << set_a_size << " elements of A:" << endl;
    for (int i = 0; i < set_a_size; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < set_u_size; j++)
        {
            if (set_u[j] == temp)
            {
                set_a[j] = 1;
                break;
            }
        }
    }

    cout << "Enter size |B| = ";
    cin >> set_b_size;
    // retrieving set B elements and assigning 1's and 0's in set A with respect to the universal set U.
    cout << "Enter " << set_b_size << " elements of B: " << endl;
    for (int i = 0; i < set_b_size; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < set_u_size; j++)
        {
            if (set_u[j] == temp)
            {
                set_b[j] = 1;
                break;
            }
        }
    }
    // Set Operations

    for (int i = 0; i < set_u_size; i++)
    {
        // Union
        if (set_a[i] == 1 || set_b[i] == 1)
        {
            set_a_union_b[i] = 1;
        }
        // Intersection
        if (set_a[i] == 1 && set_b[i] == 1)
        {
            set_a_intersection_b[i] = 1;
        }
        // A Complement
        if (set_a[i] == 0)
        {
            // 0's are already assigned
            set_a_complement[i] = 1;
        }
        // B Complement
        if (set_b[i] == 0)
        {
            set_b_complement[i] = 1;
        }
        // Difference A-B
        if (set_a[i] == 1 && set_b[i] == 0)
        {
            set_a_difference_b[i] = 1;
        }
        // Difference B-A
        if (set_b[i] == 1 && set_a[i] == 0)
        {
            set_b_difference_a[i] = 1;
        }
    }

    // Printing on screen
    cout << "U = {";
    for (int i = 0; i < set_u_size; i++)
    {
        cout << set_u[i];
        if (i < set_u_size - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;

    printSet(set_a, set_u, set_u_size, "A = ");
    printSet(set_b, set_u, set_u_size, "B = ");
    printSet(set_a_union_b, set_u, set_u_size, "A U B = ");
    printSet(set_a_intersection_b, set_u, set_u_size, "A ∩ B = ");
    printSet(set_a_complement, set_u, set_u_size, "A' = ");
    printSet(set_b_complement, set_u, set_u_size, "B' = ");
    printSet(set_a_difference_b, set_u, set_u_size, "A-B = ");
    printSet(set_b_difference_a, set_u, set_u_size, "B-A = ");
    return 0;
}