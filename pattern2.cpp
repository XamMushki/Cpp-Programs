/*
     1
   1 2 1
 1 2 3 2 1      --> longest line, int lines;
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

    for (int i = 1; i <= 2 * lines - 1; i++)
    {
        // printing blank spaces
        // abs() returns +ve of the number
        for (int s = abs(lines - i); s > 0; s--)
        {
            cout << " ";
        }
        if (i <= lines)
        {
            int j = 1;
            for (j; j <= i; j++)
            {
                cout << j;
            }
            for (j = j - 2; j > 0; j--)
            {
                cout << j;
            }
        }
        else
        {
            /*let lines be 4, then else part will start when i >4.
                and i<=7, i.e, 'i' will be 5,6,7 in order to execute the else part.
                when i = 5, x will be (5-(2*4)), i.e, 3 (using abs()). and k will be 1,2,3.
                m will be 2, values of m will be 2,1.
                when i = 6, x will be 2, and values of k will be 1,2.
                m will be 1, values of m will be 1.
                when i = 7, x will be 1. and value of k will be 1.
                m will be 0, values of m will be 0. */

            int x = abs(i - (2 * lines));
            // left side of lower pyramid
            for (int k = 1; k <= x; k++)
            {
                cout << k;
            }
            // right side of lower pyramid
            for (int m = x - 1; m > 0; m--)
            {
                cout << m;
            }
        }

        cout << endl;
    }

    return 0;
}