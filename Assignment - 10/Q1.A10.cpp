#include <iostream>
using namespace std;

class HashSet
{
    int table[100];
    bool occupied[100];
    int size;

public:
    HashSet()
    {
        size = 100;
        for (int i = 0; i < size; i++)
        {
            occupied[i] = false;
        }
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        while (occupied[index])
        {
            index = (index + 1) % size;
        }

        table[index] = key;
        occupied[index] = true;
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        int startIndex = index;

        while (occupied[index])
        {
            if (table[index] == key)
            {
                return true;
            }
            index = (index + 1) % size;

            if (index == startIndex)
            {
                break;
            }
        }

        return false;
    }
};

bool containsDuplicate(int arr[], int n)
{
    HashSet hashSet;

    for (int i = 0; i < n; i++)
    {
        if (hashSet.search(arr[i]))
        {
            return true;
        }
        hashSet.insert(arr[i]);
    }

    return false;
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

    if (containsDuplicate(arr, n))
    {
        cout << "Output: true" << endl;
        cout << "Array contains duplicates" << endl;
    }
    else
    {
        cout << "Output: false" << endl;
        cout << "Array does not contain duplicates" << endl;
    }

    return 0;
}