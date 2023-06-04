#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    cout << "Enter Array Size: ";
    cin >> n;
    int arr[n];
    string input;
    cout << "Enter Array separated by commas ',': ";
    cin >> input;
    stringstream ss(input);
    string temp;
    int i = 0;
    while (getline(ss, temp, ',')) {
        arr[i] = atoi(temp.c_str());
        i++;
    }

    cout << "Original Array: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    cout << "Reversed Array: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}