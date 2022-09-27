// C++ program to keep calculating the sum of digits of a number until the number is a single number.
#include <iostream>
using namespace std;

int sod(long num)
{
    int sum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        sum += digit;
        num = num / 10;
    }
    return sum;
}

int main()
{
    long x;
    cout << "Enter Number: ";
    cin >> x;
    // cout << endl;
    if (x < 10 && x >= 0)
    {
        cout << "Final Signal Digit: " << x << endl;
    }
    else if (x < 0)
    {
        cout << "Invalid Input!!"<<endl;
    }

    else
    {
        int i = 1;
        while (true)
        {
            int sum = sod(x);
            x = sum;
            cout << "Itr " << i << ":" << endl;
            i++;
            if (sum > 9)
            {
                cout << "Sum: " << sum << endl;
            }
            else
            {
                cout << "Final Signal Digit (Sum): " << sum << endl;
                break;
            }
        }
    }

    return 0;
}