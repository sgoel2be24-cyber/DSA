#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int num)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] < num)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << " enter the size :";
    cin >> n;

    int arr[50];
    cout << "enter the values";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int num;
    cout << "enter the value to find";
    cin >> num;

    int result = binarySearch(arr, 0, n - 1, num);
    if (result != -1)
    {
        cout << "index of element found is : " << result << "and the element found is : " << arr[result];
    }

    else
        cout << "result not found";
    return 0;
}