#include <iostream>
using namespace std;

int main()
{
    int a, n, d;
    cout << "Enter First element of the sequence: ";
    cin >> a;
    cout << "Enter the size of sequence: ";
    cin >> n;
    cout << "Enter Common Difference (d): ";
    cin >> d;

    int seq_array[n];
    for (int i = 1; i < n + 1; i++)
    {
        int temp = a + (i - 1) * d;
        seq_array[i - 1] = temp;
    }

    // print
    cout << "\nSequence: {";
    for (int i = 0; i < n; i++)
    {
        cout << seq_array[i];

        if (i < n - 1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}