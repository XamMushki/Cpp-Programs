/*
no. of lines = 3
and then repeat etc.
     1
   1 2 1
 1 2 3 2 1
   1 2 1
     1
*/

#include <iostream>
using namespace std;

int main()
{
    int lines;
    cout << "Enter Number of lines upto longest line: ";
    cin >> lines;
    int total_lines = lines + (lines - 1);

    for (int i = 1; i <= lines; i++)
    {
        // printing blank spaces
        for (int s = lines - i; s > 0; s--)
        {
            cout << " ";
        }
        int k = 1;
        for (k; k <= i; k++)
        {
            cout << k;
        }
        for (k = k - 2; k >= 1; k--)
        {
            cout << k;
        }

        cout << endl;
    }
    // printing lower part
    lines = lines - 1;
    for (int i = lines; i > 0; i--)
    {
        for (int s = lines - (i - 1); s > 0; s--)
        {
            cout << " ";
        }
        int k = 1;
        for (k; k <= i; k++)
        {
            cout << k;
        }
        for (k; k > 0; k--)
        {
            cout << k;
        }

        cout << endl;
        // cout << "k= " << k;
    }

    return 0;
}