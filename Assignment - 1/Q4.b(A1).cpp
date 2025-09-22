#include <iostream>
using namespace std;

int main()
{
    int a[10][10], b[10][10], c[10][10], r1, c1, r2, c2;

    cout << "enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2)
    {
        cout << "matrix multiplication not possible" << endl;
        return 0;
    }

    cout << "enter elements of first matrix:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "enter elements of second matrix:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    cout << "resultant matrix:" << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}
