// Using Warshall's algorithm
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    cout << "Enter Size of Set A: ";
    cin >> n;

    // matrix size will always be nxn
    cout << "Enter Matrix Elements (1's and 0's), one row at a time, " << n << "elements seperated by commas ','" << endl;
    int matrixR[n][n];
    for (int i = 0; i < n; i++) {
        string line;
        cout << "Row " << i + 1 << " : ";
        cin >> line;

        stringstream line_stream(line);
        string temp;
        int j = 0;
        while (getline(line_stream, temp, ',')) {
            // matrixR[i][j] = stoi(temp);
            matrixR[i][j] = atoi(temp.c_str());
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        int col_with_ones[n];
        int row_with_ones[n];
        int c_counter = 0;
        int r_counter = 0;
        for (int j = 0; j < n; j++) {
            if (matrixR[i][j] == 1) {
                row_with_ones[r_counter] = j;
                r_counter++;
            }
            if (matrixR[j][i] == 1) {
                col_with_ones[c_counter] = j;
                c_counter++;
            }
        }
        // assigning 1 at newly formed ordered pairs
        for (int x = 0; x < c_counter; x++) {
            for (int m = 0; m < r_counter; m++) {
                matrixR[col_with_ones[x]][row_with_ones[m]] = 1;
            }
        }
    }

    cout << "Transitive Closure: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrixR[i][j] << ' ';
        }
        cout << endl;
    }
}