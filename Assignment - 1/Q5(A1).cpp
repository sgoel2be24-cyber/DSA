#include <iostream>
using namespace std;

int main()
{
    int arr[10][10], rows, cols;

    cout << "enter number of rows: ";
    cin >> rows;
    cout << "enter number of columns: ";
    cin >> cols;

    cout << "enter elements of the array:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < rows; i++)
    {
        int sumRow = 0;
        for (int j = 0; j < cols; j++)
            sumRow += arr[i][j];
        cout << "sum of row " << i + 1 << " = " << sumRow << endl;
    }

    for (int j = 0; j < cols; j++)
    {
        int sumCol = 0;
        for (int i = 0; i < rows; i++)
            sumCol += arr[i][j];
        cout << "sum of column " << j + 1 << " = " << sumCol << endl;
    }

    return 0;
}
