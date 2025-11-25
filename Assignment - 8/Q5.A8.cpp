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

void heapifyMaxHeap(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapifyMaxHeap(arr, n, largest);
    }
}

void heapifyMinHeap(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        heapifyMinHeap(arr, n, smallest);
    }
}

void heapSortIncreasing(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMaxHeap(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyMaxHeap(arr, i, 0);
    }
}

void heapSortDecreasing(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMinHeap(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyMinHeap(arr, i, 0);
    }
}

int main()
{
    int n, choice;

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

    while (true)
    {
        cout << "\n1. Heap Sort (Increasing Order)" << endl;
        cout << "2. Heap Sort (Decreasing Order)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        int tempArr[n];
        for (int i = 0; i < n; i++)
        {
            tempArr[i] = arr[i];
        }

        switch (choice)
        {
        case 1:
            heapSortIncreasing(tempArr, n);
            cout << "Sorted array (Increasing): ";
            printArray(tempArr, n);
            break;

        case 2:
            heapSortDecreasing(tempArr, n);
            cout << "Sorted array (Decreasing): ";
            printArray(tempArr, n);
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}