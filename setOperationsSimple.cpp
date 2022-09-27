#include <iostream>
using namespace std;

//size = n = 10

void printSetOnScreen(int set[], int n, string set_name)
{
    cout << set_name << " = {";
    for (int i = 0; i < n; i++)
    {
        cout << set[i];

        if (i < n - 1)
        {
            // optional, used only to avoid the ',' at the end of the list
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main()
{
    int size = 10;

    int set_u[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int set_a[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0}; // set_a={1,2,3,4,5,6,7}
    int set_b[] = {0, 0, 0, 1, 1, 0, 1, 1, 1, 0}; // set_b={4,5,7,8,9}

    // UNION
    int set_a_union_b[size];
    for (int i = 0; i < size; i++)
    {
        if (set_a[i] == 1 || set_b[i] == 1)
        {
            set_a_union_b[i] = 1;
        }
    }

    // INTERSECTION
    int set_a_intersection_b[size];
    for (int i = 0; i < size; i++)
    {
        if (set_a[i] == 1 && set_b[i] == 1)
        {
            set_a_intersection_b[i] = 1;
        }
    }

    // A's Complement
    int set_a_complement[size];
    for (int i = 0; i < size; i++)
    {
        if (set_a[i] == 1)
        {
            set_a_complement[i] = 0;
        }
        else
        {
            set_a_complement[i] = 1;
        }
    } // similarly for set B complement

    // DIFFERENCE
    int set_a_difference_b[size];
    // i.e, A-B
    for (int i = 0; i < size; i++)
    {
        if (set_a[i] == 1 && set_b[i] == 0)
        {
            set_a_difference_b[i] = 1;
        }
        else
        {
            set_a_difference_b[i] = 0;
        }
    } // for B-A ---> if(set_a[i]==0 && set_b[i]==1)

    // printing on screen using the above defined function printSetOnScreen()
    // else we have to print the sets one by one, using the same method but multiple times.
    printSetOnScreen(set_u, size, "U    ");
    printSetOnScreen(set_a, size, "A    ");
    printSetOnScreen(set_b, size, "B    ");
    printSetOnScreen(set_a_union_b, size, "A U B");
    printSetOnScreen(set_a_intersection_b, size, "A I B");
    printSetOnScreen(set_a_complement, size, "A'   ");
    printSetOnScreen(set_a_difference_b, size, "A-B  ");

    return 0;
}