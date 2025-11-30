#include <iostream>
using namespace std;

class HashMap
{
    int keys[100];
    int values[100];
    bool occupied[100];
    int size;

public:
    HashMap()
    {
        size = 100;
        for (int i = 0; i < size; i++)
        {
            occupied[i] = false;
            values[i] = 0;
        }
    }

    int hashFunction(int key)
    {
        if (key < 0)
        {
            return (key * -1) % size;
        }
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        while (occupied[index])
        {
            if (keys[index] == key)
            {
                values[index]++;
                return;
            }
            index = (index + 1) % size;
        }

        keys[index] = key;
        values[index] = 1;
        occupied[index] = true;
    }

    int getCount(int key)
    {
        int index = hashFunction(key);
        int startIndex = index;

        while (occupied[index])
        {
            if (keys[index] == key)
            {
                return values[index];
            }
            index = (index + 1) % size;

            if (index == startIndex)
            {
                break;
            }
        }

        return 0;
    }
};

int findFirstNonRepeating(int arr[], int n)
{
    HashMap hashMap;

    for (int i = 0; i < n; i++)
    {
        hashMap.insert(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (hashMap.getCount(arr[i]) == 1)
        {
            return arr[i];
        }
    }

    return -1;
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

    int result = findFirstNonRepeating(arr, n);

    if (result != -1)
    {
        cout << "Output: " << result << endl;
    }
    else
    {
        cout << "No non-repeating element found" << endl;
    }

    return 0;
}