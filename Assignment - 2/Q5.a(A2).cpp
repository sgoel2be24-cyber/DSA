#include <iostream>
using namespace std;

class Diagonal
{
    int *arr;
    int n;

public:
    Diagonal(int size)
    {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = 0;
    }

    ~Diagonal()
    {
        delete[] arr;
    }

    void set(int i, int j, int val)
    {
        if (i == j)
        {
            arr[i - 1] = val;
        }
    }

    int get(int i, int j)
    {
        if (i == j)
            return arr[i - 1];
        else
            return 0;
    }

    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    cout << arr[i - 1] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "enter size of square matrix: ";
    cin >> n;

    Diagonal d(n);

    cout << "enter " << n << " diagonal elements:" << endl;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        d.set(i, i, x);
    }

    cout << "the diagonal matrix is:" << endl;
    d.display();

    return 0;
}
