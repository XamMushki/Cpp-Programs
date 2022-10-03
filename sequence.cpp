#include <iostream>
#include <cmath>
using namespace std;

void printSequence(int arr[], int n)
{
    cout << "\nSequence: {";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}
void arithmeticProgression(int a, int n, int d)
{
    int seq_array[n];
    for (int i = 1; i < n + 1; i++)
    {
        int temp = a + (i - 1) * d;
        seq_array[i - 1] = temp;
    }
    printSequence(seq_array, n);
}
void geometricProgression(int a, int r, int n)
{
    int seq_array[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        temp = a * pow(r, i);
        seq_array[i] = temp;
    }
    printSequence(seq_array, n);
}

int main()
{
    while (true)
    {

        int option;
        cout << "\nChoose an option: " << endl;
        cout << "1. Arithmetic Progression\n2. Geometric Progression\n3. To check AP\n4. To check GP\n5. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        if (option == 5)
        {
            break;
        }
        else if (option == 1)
        { // Arithmetic Progression
            int a, n, d;
            cout << "Enter First element of the sequence: ";
            cin >> a;
            cout << "Enter the size of sequence: ";
            cin >> n;
            cout << "Enter Common Difference (d): ";
            cin >> d;
            arithmeticProgression(a, n, d);
        }
        else if (option == 2)
        {
            // Geometric Progression
            int a, r, n;
            cout << "Enter First element of the sequence: ";
            cin >> a;
            cout << "Enter the size of sequence: ";
            cin >> n;
            cout << "Enter Common Ratio (r): ";
            cin >> r;
            geometricProgression(a, n, r);
        }
        //CHECK AP & GP
        else if (option == 3 || option == 4)
        {
            int n;
            cout << "Enter size of sequence: ";
            cin >> n;
            int seq_array[n];
            cout << "Enter " << n << " elements of the sequence: \n";
            for (int i = 0; i < n; i++)
            {
                cin >> seq_array[i];
            }

            // CHECK
            int com_arr_size = n - 1;
            float common_array[com_arr_size];

            // Check AP
            if (option == 3)
            {
                for (int i = 0; i < com_arr_size; i++)
                {
                    int temp = seq_array[i + 1] - seq_array[i];
                    common_array[i] = temp;
                }
                // comparing common difference of elements
                bool flag = true;
                for (int i = 0; i < com_arr_size - 1; i++)
                {
                    if (common_array[i] != common_array[i + 1])
                    {
                        flag = false;
                        break;
                    }
                }
                printSequence(seq_array, n);
                if (flag)
                {
                    // i.e, flag remained unchanged, which means no two elements in common_array[] are unequal
                    //  difference between every two consecutive elements of the seq. is same (common difference)
                    cout << "The Sequence is Arithmetic Progression." << endl;
                }
                else
                {
                    cout << "The Sequence is NOT Arithmetic Progression." << endl;
                }
            }
            // Check GP
            else if (option == 4)
            {
                for (int i = 0; i < com_arr_size; i++)
                {
                    float temp = seq_array[i + 1] / seq_array[i];
                    temp = ceil(temp * 100) / 100;
                    common_array[i] = temp;
                }
                bool flag = true;
                for (int i = 0; i < com_arr_size - 1; i++)
                {
                    if (common_array[i] != common_array[i + 1])
                    {
                        flag = false;
                        break;
                    }
                }
                printSequence(seq_array, n);
                if (flag)
                {
                    // i.e, flag remained unchanged, which means no two elements in common_array[] are unequal
                    cout << "The sequence is Geometric Progression." << endl;
                }
                else
                {
                    cout << "The sequence is NOT Geometric Progression." << endl;
                }
            }

            else
            {
                cout << "Invalid Option Selected..." << endl;
            }
        }
    }
}