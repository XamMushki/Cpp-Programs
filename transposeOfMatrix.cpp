#include <iostream>
using namespace std;

int main()
{
    int col_size, row_size;
    cout << "Enter number of rows: ";
    cin >> row_size;
    cout << "Enter number of columns: ";
    cin >> col_size;

    int matrix[row_size][col_size];

    cout << "Enter elements of Matrix: \n";
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout<<"A"<<i<<j<<" = ";
            cin >> matrix[i][j];
        }
    }
    // printing matrix on screen
    cout<<"Matrix A is \n";
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;

    }
    // Transpose
    // no. of columns in matrix are no of rows in its transpose
    int transpose_of_matrix[col_size][row_size];
    for (int i = 0; i < col_size; i++)
    {
        for (int j = 0; j < row_size; j++)
        {
            transpose_of_matrix[i][j] = matrix[j][i];
            
        }
        
    }
    // printing transpose of matrix on screen
    cout<<"Transpose of A is \n";
    for (int i = 0; i < col_size; i++)
    {
        for (int j = 0; j < row_size; j++)
        {
            cout<<transpose_of_matrix[i][j]<<" ";
        }
        cout<<endl;

    }



    return 0;
}