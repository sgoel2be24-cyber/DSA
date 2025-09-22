#include <iostream>
using namespace std;

int sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] != 1)
        {
            return arr[i] + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    int arr[50];

    cout << "enter the number of elements" << endl;
    cin >> n;

    cout << "enter the value of the elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int missing = sort(arr, n);
    if (missing == -1)
    {
        cout << "no missing element";
    }

    else
    {
        cout << "missing element is : " << missing << endl;
        cout << "the corrected array is : ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
        }

        return 0;
    }
}
