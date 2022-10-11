// UNION INTERSECTION DIFFERENCE XOR

#include <iostream>
using namespace std;
void printRelation(int r[][2], int count, string msg)
{
    cout << msg << " = {";
    for (int i = 0; i < count; i++)
    {
        cout << "(" << r[i][0] << "," << r[i][1] << ")";
        if (i < count - 1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}

int main()
{
    int r1_size, r2_size;

    // R1 declaration and intialization
    cout << "Enter number of ordered pairs in relation R1: ";
    cin >> r1_size;
    int r1[r1_size][2]; // used to store elements like: for (a,b) r1[r1_size][0] = a and r1[r1_size][1] = b

    // initializing array r1[][] using user inputs
    cout << "Enter " << r1_size << " ordered pairs of R1: " << endl;
    for (int i = 0; i < r1_size; i++)
    {
        cout << "\nOrdered Pair " << i + 1 << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Element " << j + 1 << " : ";
            cin >> r1[i][j];
        }
    }
    // R2 declaration and intialization
    cout << "Enter number of ordered pairs in relation R2: ";
    cin >> r2_size;
    int r2[r2_size][2]; // used to store elements like: for (a,b) r2[r2_size][0] = a and r2[r2_size][1] = b

    // initializing array r2[][] using user inputs
    cout << "Enter " << r2_size << " ordered pairs of R2: " << endl;
    for (int i = 0; i < r2_size; i++)
    {
        cout << "\nOrdered Pair " << i + 1 << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Element " << j + 1 << " : ";
            cin >> r2[i][j];
        }
    }

    // INTERSECTION
    /* if the size of one set is x and the size of the other set is y, and x<y, the maximum number of
    elements in intersection of the two sets will be x. or let z be the size of intersection set, then z <= x*/
    int r_intersection_size;
    if (r1_size < r2_size)
    {
        r_intersection_size = r1_size;
    }
    else
    {
        r_intersection_size = r2_size;
    }
    int r1_intersection_r2[r_intersection_size][2];

    int counter_intersection = 0; // for intializing intersection array and printing its values

    for (int i = 0; i < r1_size; i++)
    {
        for (int j = 0; j < r2_size; j++)
        {
            if (r1[i][0] == r2[j][0])
            {
                if (r1[i][1] == r2[j][1])
                {
                    r1_intersection_r2[counter_intersection][0] = r1[i][0];
                    r1_intersection_r2[counter_intersection][1] = r1[i][1];
                    counter_intersection++;
                }
            }
        }
    }

    // DIFFERENCE R1 - R2

    int r1_difference_r2[r1_size][2];
    int counter_r1_diff_r2 = 0;
    bool flag_r1_diff_r2;

    for (int i = 0; i < r1_size; i++)
    {
        flag_r1_diff_r2 = false;
        for (int j = 0; j < r2_size; j++)
        {
            if (r1[i][0] == r2[j][0] && r1[i][1] == r2[j][1])
            {
                // if r1 and r2 have the element in common(means we don't need that elemet/pair)
                flag_r1_diff_r2 = true;
                break;
            }
        }
        if (!flag_r1_diff_r2) // only if the flag remains false, means the pair is in r1 but not in r2
        {
            r1_difference_r2[counter_r1_diff_r2][0] = r1[i][0];
            r1_difference_r2[counter_r1_diff_r2][1] = r1[i][1];
            counter_r1_diff_r2++;
        }
    }
    // DIFFERENCE R2 - R1

    int r2_difference_r1[r2_size][2];
    int counter_r2_diff_r1 = 0;
    bool flag_r2_diff_r1;

    for (int i = 0; i < r2_size; i++)
    {
        flag_r2_diff_r1 = false;
        for (int j = 0; j < r1_size; j++)
        {
            if (r2[i][0] == r1[j][0] && r2[i][1] == r1[j][1])
            {
                // if r2 and r1 have the element in common(means we don't need that elemet/pair)
                flag_r2_diff_r1 = true;
                break;
            }
        }
        if (!flag_r2_diff_r1) // only if the flag remains false, i.e, this pair in r2 is not in r1
        {
            r2_difference_r1[counter_r2_diff_r1][0] = r2[i][0];
            r2_difference_r1[counter_r2_diff_r1][1] = r2[i][1];
            counter_r2_diff_r1++;
        }
    }

    // UNION
    int r1_union_r2_size = r1_size + r2_size - counter_intersection; // counter_intersection gives us the size of intersection of r1 and r1
    int r1_union_r2[r1_union_r2_size][2];
    // IMPORTANT
    // r1 U r2 = elements of r1 and elements of r2-r1.

    // first assigning the elements of r1 to r1_union_r2.
    for (int i = 0; i < r1_size; i++)
    {
        r1_union_r2[i][0] = r1[i][0];
        r1_union_r2[i][1] = r1[i][1];
    }

    // now assigning the elements of r2_difference_r1 (r2-r1) to r1_union_r2
    /*index will continue from 'r1_size' to r1_size + counter_r2_diff_r1 (i.e, size of r2-r1),
    which is also equal to r1_union_r2_size declared and calculated above.*/
    int cn = 0; // used because i doesn't start from 0, which we need to access r2_difference_r1[][]
    for (int i = r1_size; i < r1_union_r2_size; i++)
    {
        r1_union_r2[i][0] = r2_difference_r1[cn][0];
        r1_union_r2[i][1] = r2_difference_r1[cn][1];
        cn++;
    }

    // printing on screen using the printRelation() declared above.
    cout<<endl;
    printRelation(r1, r1_size, "R1");
    printRelation(r2, r2_size, "R2");
    cout<<endl;
    printRelation(r1_intersection_r2, counter_intersection, "R1 ∩ R2");
    printRelation(r1_difference_r2, counter_r1_diff_r2, "R1 - R2");
    printRelation(r2_difference_r1, counter_r2_diff_r1, "R2 - R1");
    printRelation(r1_union_r2, r1_union_r2_size, "R1 U R2");
}