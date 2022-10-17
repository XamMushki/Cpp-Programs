#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int set_a_size;
    string values;
    cout << "Enter Elements in set A: ";
    cin >> set_a_size;
    cout << "Enter " << set_a_size << " elements separated by \',\': ";
    cin >> values;
    stringstream values_stream(values);
    int set_a[set_a_size];
    for (int j = 0; j < set_a_size; j++)
    {
        set_a[j] = 0;
    }

    string temp;
    int x = 0;
    while (getline(values_stream, temp, ','))
    {
        set_a[x] = stoi(temp);
        x++;
    }
    // print set A
    cout << "A = {";
    for (int i = 0; i < set_a_size; i++)
    {
        cout << set_a[i];
        if (i < set_a_size - 1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;

    // finding matrices of relations
    int matrix_r1[set_a_size][set_a_size];
    int matrix_r2[set_a_size][set_a_size];

    // initializing with 0's
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            matrix_r1[i][j] = 0;
            matrix_r2[i][j] = 0;
        }
    }
    // int r1_counter = 0;
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            // R1 = {(a,b)| a/b}, b divides a
            if (set_a[i] % set_a[j] == 0)
            {
                matrix_r1[i][j] = 1;
            }
            // R2 = {(a,b)| b/a}, a divides b
            if (set_a[j] % set_a[i] == 0)
            {
                matrix_r2[i][j] = 1;
            }
        }
    }

    // print matrix MR1
    cout << "MR1 = {(a,b)|a/b}: " << endl;
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            cout << matrix_r1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // print matrix MR2
    cout << "MR2 = {(a,b)|b/a}: " << endl;
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            cout << matrix_r2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Union and Intersection of matrices.
    int mr1_union_mr2[set_a_size][set_a_size];
    int mr1_intersection_mr2[set_a_size][set_a_size];
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            mr1_union_mr2[i][j] = 0;
            mr1_intersection_mr2[i][j] = 0;
        }
    }

    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            // UNION
            if (matrix_r1[i][j] == 1 || matrix_r2[i][j] == 1)
            {
                mr1_union_mr2[i][j] = 1;
            }
            // INTERSECTION
            if (matrix_r1[i][j] == 1 && matrix_r2[i][j] == 1)
            {
                mr1_intersection_mr2[i][j] = 1;
            }
        }
    }
    // print matrix MR1 UNION MR2
    cout << "MR1 U MR2: " << endl;
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            cout << mr1_union_mr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // print matrix MR1 INTERSECTION MR2
    cout << "MR1 ∩ MR2: " << endl;
    for (int i = 0; i < set_a_size; i++)
    {
        for (int j = 0; j < set_a_size; j++)
        {
            cout << mr1_intersection_mr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}