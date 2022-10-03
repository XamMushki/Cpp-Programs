#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    cout << "\nArray: [";
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
    int size;
    cout << "Enter array size: ";
    cin >> size;

    // decalaring and initializing array
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // finding highest and lowest numbers in the array
    int lowest = arr[0];
    int highest = arr[0];

    for (int i = 0; i < size; i++)
    {
        // finding lowest
        if (lowest > arr[i])
        {
            lowest = arr[i];
        }
        // finding highest
        if (highest < arr[i])
        {
            highest = arr[i];
        }
    }
    printArray(arr,size);
    cout<<"Highest in the array = "<<highest<<endl;
    cout<<"Lowest in the array = "<<lowest<<endl;

}