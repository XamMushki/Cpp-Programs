#include <iostream>
using namespace std;

int main()
{
    int set_a_size;
    cout << "Enter the size of set A: ";
    cin >> set_a_size;
    int set_a[set_a_size];

    // array intialization
    cout << "Enter " << set_a_size << " elements of set A: \n";
    for (int i = 0; i < set_a_size; i++)
    {
        cin >> set_a[i];
    }

    int r_size;
    cout << "Enter size of relation R: ";
    cin >> r_size;
    int relation_r[r_size][2];

    // initialzing relation_r array (2D)
    cout << "Enter " << r_size << " Ordered pairs: " << endl;
    for (int i = 0; i < r_size; i++)
    {
        cout << "\nOrdered Pair " << i + 1 << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Element " << j + 1 << ": ";
            cin >> relation_r[i][j];
        }
    }
    // checking whether the set of ordered pairs is relation on set A or not
    // i.e, if every element of relation_r array belongs to set A --> is a relation, else not a relation.
    bool flag;
    int missing_element;
    for (int i = 0; i < r_size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            flag = false;
            for (int k = 0; k < set_a_size; k++)
            {
                missing_element = relation_r[i][j]; // used only if the below condition is false
                if (relation_r[i][j] == set_a[k])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (!flag)
        {
            cout << "R is not a relation on set A, because " << missing_element << " doesn't belong to A" << endl;
            break;
        }
    }
    if (flag) // if R is a relation on set A
    {
        int set_a_visited_flag[set_a_size]; // index [i] --> set_a[i]

        // initializing with 0's
        for (int i = 0; i < set_a_size; i++)
        {
            set_a_visited_flag[i] = 0;
        }
        // initializing the elements of set_a_visited_flag;
        for (int i = 0; i < r_size; i++)
        {
            if (relation_r[i][0] == relation_r[i][1])
            {
                for (int j = 0; j < set_a_size; j++)
                {
                    if (relation_r[i][0] == set_a[j])
                    {
                        set_a_visited_flag[j] = 1;
                    }
                }
            }
        }
        // checking whether all the elements of set_a_visited_flag[] are 1 (reflexive) or 0 (not reflexive)
        bool is_reflexive = true;
        for (int i = 0; i < set_a_size; i++)
        {
            if (set_a_visited_flag[i] == 0)
            {
                is_reflexive = false;
                break;
            }
        }
        // Irreflexive
        // there exists not such ordered pair as (a,a) in R
        // which means all elements of set_a_visited_flag[] must 0
        bool is_irreflexive = true;
        for (int i = 0; i < set_a_size; i++)
        {
            if (set_a_visited_flag[i] == 1)
            {
                is_irreflexive = false;
                break;
            }
        }
        // printing set A on screen
        cout << "A = {";
        for (int i = 0; i < set_a_size; i++)
        {
            // here
            //  cout << set_a[i];
            cout << set_a_visited_flag[i];
            if (i < set_a_size - 1)
            {
                cout << ",";
            }
        }
        cout << "}" << endl;
        // printing relation R on screen
        cout << "R = {";
        for (int i = 0; i < r_size; i++)
        {
            cout << "(" << relation_r[i][0] << "," << relation_r[i][1] << ")";
            if (i < r_size - 1)
            {
                cout << ",";
            }
        }
        cout << "}" << endl;

        // Generating Output
        cout << endl;
        if (is_reflexive) // all the elements of set_a_visited_flag[] are 1
        {
            cout << "Relation R is Reflexive." << endl;
        }
        else if (is_irreflexive) // all the elements of set_a_visited_flag[] are 0
        {
            cout << "Relation R is Irreflexive, because there exists no such ordered pair as (a,a) in R." << endl;
        }
        else if (!is_reflexive) // executes if only some of the elements of set_a_visited_flag[] are 0/1
        {
            cout << "Relation R is Neither Reflexive because ordered pair/s ";
            // finding the missing ordered pairs
            // for not Reflexive
            for (int i = 0; i < set_a_size; i++)
            {
                if (set_a_visited_flag[i] == 0)
                {
                    cout << "(" << set_a[i] << "," << set_a[i] << ")  ";
                }
            }
            cout << "are missing." << endl;

            // for nor Irreflexive
            cout << "Nor Irreflexive because R contains ordered pair/s ";
            for (int i = 0; i < set_a_size; i++)
            {
                if (set_a_visited_flag[i] == 1)
                {
                    cout << "(" << set_a[i] << "," << set_a[i] << ")  ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}