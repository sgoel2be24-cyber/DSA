#include <iostream>
using namespace std;

class Symmetric
{
    int *a, n;

public:
    Symmetric(int size)
    {
        n = size;
        a = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++)
            a[i] = 0;
    }

    void set(int i, int j, int val)
    {
        if (i >= j)
        {
            int index = (i * (i - 1)) / 2 + (j - 1);
            a[index] = val;
        }
        else
        {
            int index = (j * (j - 1)) / 2 + (i - 1);
            a[index] = val;
        }
    }

    int get(int i, int j)
    {
        if (i >= j)
        {
            int index = (i * (i - 1)) / 2 + (j - 1);
            return a[index];
        }
        else
        {
            int index = (j * (j - 1)) / 2 + (i - 1);
            return a[index];
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

    Symmetric s(n);
    cout << "enter matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            s.set(i, j, x);
        }
    }

    cout << "matrix is:" << endl;
    s.show();
}
