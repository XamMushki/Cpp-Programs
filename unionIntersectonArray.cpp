#include <iostream>
using namespace std;

void printArray(int arr[], int n, string txt)
{
    cout << "\n"
         << txt << " [";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main()
{
    int size_a, size_b;

    cout << "Enter size of Array A: ";
    cin >> size_a;
    int array_a[size_a];
    if (size_a > 0)
    {
        cout << "Enter " << size_a << " elements of A: " << endl;
        for (int i = 0; i < size_a; i++)
        {
            cin >> array_a[i];
        }
    }
    cout << "Enter size of Array B: ";
    cin >> size_b;
    int array_b[size_b];
    int common_counter = 0; // used to determine the size of array to be created for union and intersection
    if (size_b > 0)
    {

        cout << "Enter " << size_b << " elements of A: " << endl;
        for (int i = 0; i < size_b; i++)
        {
            int temp;
            cin >> temp;
            array_b[i] = temp;
            for (int i = 0; i < size_a; i++)
            {
                if (temp == array_a[i])
                {
                    common_counter++;
                }
            }
        }
    }

    // Union and intersection array size calculation
    int union_array_size = size_a + size_b - common_counter;
    int union_array[union_array_size];
    int intersection_array[common_counter];

    // UNION
    // assigning values of array_a to union_array
    for (int i = 0; i < size_a; i++)
    {
        union_array[i] = array_a[i];
    }

    int x = size_a; // used to assign values to union_array after index size_a, acts as a counter

    for (int i = 0; i < size_b; i++)
    {
        bool is_already_present = false;
        for (int j = 0; j < union_array_size; j++)
        {

            if (array_b[i] == union_array[j])
            {
                is_already_present = true;
            }
        }
        if (!is_already_present)
        {
            // var is_already_present should remain unchanged (i.e, false)
            // which means item in array_b is not present in array_a/union_array
            union_array[x] = array_b[i];
            x++;
            // break;
        }
    }
    // }

    // INTERSECTION

    int c = 0; // used as a counter/index for assigning values to intersecton_array
    for (int i = 0; i < size_a; i++)
    {
        for (int j = 0; j < size_b; j++)
        {
            if (array_a[i] == array_b[j])
            {
                intersection_array[c] = array_a[i];
                c++;
                break;
            }
        }
    }

    printArray(union_array, union_array_size, "Union: ");
    printArray(intersection_array, common_counter, "Intersection: ");

    return 0;
