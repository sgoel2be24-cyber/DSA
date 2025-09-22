#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter number of elements: ";
    cin >> n;

    double A[n];
    cout << "enter elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
                count++;
        }
    }

    cout << "number of inversions: " << count << endl;
    return 0;
}
