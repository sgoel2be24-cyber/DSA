#include <iostream>
using namespace std;

class UpperTriangular
{
    int *a, n;

public:
    UpperTriangular(int size)
    {
        n = size;
        a = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++)
            a[i] = 0;
    }

    void set(int i, int j, int val)
    {
        if (i <= j)
        {
            int index = (j * (j - 1)) / 2 + (i - 1);
            a[index] = val;
        }
    }

    int get(int i, int j)
    {
        if (i <= j)
        {
            int index = (j * (j - 1)) / 2 + (i - 1);
            return a[index];
        }
        else
        {
            return 0;
        }
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

    UpperTriangular ut(n);
    cout << "enter matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            ut.set(i, j, x);
        }
    }

    cout << "matrix is:" << endl;
    ut.show();
}
