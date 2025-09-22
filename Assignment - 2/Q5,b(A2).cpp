#include <iostream>
using namespace std;

class TriDiagonal
{
    int *a, n;

public:
    TriDiagonal(int size)
    {
        n = size;
        a = new int[3 * n - 2];
        for (int i = 0; i < 3 * n - 2; i++)
            a[i] = 0;
    }

    void set(int i, int j, int val)
    {
        if (i - j == 1)
            a[i - 2] = val;
        else if (i - j == 0)
            a[n - 1 + i - 1] = val;
        else if (i - j == -1)
            a[2 * n - 1 + i - 1] = val;
    }

    int get(int i, int j)
    {
        if (i - j == 1)
            return a[i - 2];
        else if (i - j == 0)
            return a[n - 1 + i - 1];
        else if (i - j == -1)
            return a[2 * n - 1 + i - 1];
        else
            return 0;
    }

    void show()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "enter size: ";
    cin >> n;

    TriDiagonal t(n);
    cout << "enter matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            t.set(i, j, x);
        }
    }

    cout << "matrix is:" << endl;
    t.show();
}
