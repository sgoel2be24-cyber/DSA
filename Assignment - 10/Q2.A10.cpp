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
            if (table[index] == key)
            {
                return;
            }
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

void findCommonElements(int A[], int n1, int B[], int n2)
{
    HashSet hashSet;

    for (int i = 0; i < n1; i++)
    {
        hashSet.insert(A[i]);
    }

    cout << "Common elements: ";
    bool found = false;

    for (int i = 0; i < n2; i++)
    {
        if (hashSet.search(B[i]))
        {
            cout << B[i] << " ";
            found = true;
        }
    }

    if (!found)
    {
        cout << "None";
    }
    cout << endl;
}

int main()
{
    int n1, n2;

    cout << "Enter size of array A: ";
    cin >> n1;

    int A[n1];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i];
    }

    cout << "Enter size of array B: ";
    cin >> n2;

    int B[n2];
    cout << "Enter elements of array B: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> B[i];
    }

    findCommonElements(A, n1, B, n2);

    return 0;
}