#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void improvedSelectionSort(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int minIndex = left;
        int maxIndex = left;

        for (int i = left; i <= right; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }

        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        if (maxIndex == left)
        {
            maxIndex = minIndex;
        }

        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal array: ";
    printArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}