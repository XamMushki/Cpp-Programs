#include <iostream>
using namespace std;

int main()
{
    int domain_set_size, codomain_set_size;
    cout << "Enter Domain size: ";
    cin >> domain_set_size;
    string domain_set[domain_set_size];

    cout << "Enter " << domain_set_size << " elements of Domain: " << endl;
    for (int i = 0; i < domain_set_size; i++)
    {
        cin >> domain_set[i];
    }

    cout << "Enter Codomain size: ";
    cin >> codomain_set_size;
    string codomain_set[codomain_set_size];
    cout << "Enter " << codomain_set_size << " elements of Codomain: " << endl;
    for (int i = 0; i < codomain_set_size; i++)
    {
        cin >> codomain_set[i];
    }

    // f(x)
    // range
    string range_set[domain_set_size];
    for (int i = 0; i < domain_set_size; i++)
    {
        range_set[i] = "";
    }
    cout << "Enter Values: " << endl;
    for (int i = 0; i < domain_set_size; i++)
    {
        cout << "f(" << domain_set[i] << ") = ";
        cin >> range_set[i];
    }

    // one-to-one
    int flag;
    for (int i = 0; i < domain_set_size; i++)
    {
        flag = 0;
        for (int j = 0; j < domain_set_size; j++)
        {
            if (range_set[i] == range_set[j])
            {
                // how many times an element is in the range
                flag++;
            }
        }
        if (flag > 1)
        {
            // if more than one then Not one-to-one,
            // i.e, one element in range occurs multiple times
            break;
        }
    }
    bool one_to_one = true;
    if (flag > 1)
    {
        one_to_one = false;
    }

    // Onto
    bool onto_flag;
    for (int i = 0; i < codomain_set_size; i++)
    {
        onto_flag = false;
        for (int j = 0; j < domain_set_size; j++)
        {
            if (codomain_set[i] == range_set[j])
            {
                onto_flag = true;
            }
        }
        if (onto_flag == false)
        {
            // i.e, some element of codomain does not belong to range
            // which means f is not onto(codomain != range).
            break;
        }
    }
    // Final output
    cout << endl;
    if (one_to_one && onto_flag)
    {
        cout << "Funtion is One-to-One Correspondence (Bijection).\n";
    }
    else if (one_to_one && !onto_flag)
    {
        cout << "Function is One-to-One (Injection) but not Onto.\n";
    }
    else if (!one_to_one && onto_flag)
    {
        cout << "Function is Onto (Surjection) but not One-to-One.\n";
    }
    else
    {
        cout << "Function is neither One-to-One nor Onto.\n";
    }
    cout << endl;

    return 0;
}