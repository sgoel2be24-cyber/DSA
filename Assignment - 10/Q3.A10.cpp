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

    void display()
    {
        cout << "Output:" << endl;
        for (int i = 0; i < size; i++)
        {
            if (occupied[i])
            {
                cout << keys[i] << " -> " << values[i];
                if (values[i] == 1)
                {
                    cout << " time" << endl;
                }
                else
                {
                    cout << " times" << endl;
                }
            }
        }
    }
};

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int nums[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    HashMap hashMap;

    for (int i = 0; i < n; i++)
    {
        hashMap.insert(nums[i]);
    }

    hashMap.display();

    return 0;
}