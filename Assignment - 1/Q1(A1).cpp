#include <iostream>
using namespace std;

int main()
{
    int arr[50], n = 0;

    while (true)
    {
        int choice;

        cout << "1. create" << endl;
        cout << "2. display" << endl;
        cout << "3. insert" << endl;
        cout << "4. delete" << endl;
        cout << "5. search" << endl;
        cout << "6. exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "enter number of elements: ";
            cin >> n;
            cout << "enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
        }
        else if (choice == 2)
        {
            if (n == 0)
                cout << "array is empty" << endl;
            else
            {
                cout << "array elements: ";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
        }
        else if (choice == 3)
        {
            if (n >= 50)
            {
                cout << "array full" << endl;
                continue;
            }
            int pos, val;
            cout << "enter position (1 to " << n + 1 << "): ";
            cin >> pos;
            if (pos < 1 || pos > n + 1)
            {
                cout << "invalid position" << endl;
                continue;
            }
            cout << "enter value: ";
            cin >> val;
            for (int i = n; i >= pos; i--)
                arr[i] = arr[i - 1];
            arr[pos - 1] = val;
            n++;
            cout << "element inserted" << endl;
        }
        else if (choice == 4)
        {
            if (n == 0)
            {
                cout << "array empty, cannot delete" << endl;
                continue;
            }
            int pos;
            cout << "enter position (1 to " << n << "): ";
            cin >> pos;
            if (pos < 1 || pos > n)
            {
                cout << "invalid position" << endl;
                continue;
            }
            for (int i = pos - 1; i < n - 1; i++)
                arr[i] = arr[i + 1];
            n--;
            cout << "element deleted" << endl;
        }
        else if (choice == 5)
        {
            if (n == 0)
            {
                cout << "array is empty" << endl;
                continue;
            }
            int key;
            cout << "enter element to search: ";
            cin >> key;
            int found = -1;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == key)
                {
                    found = i + 1;
                    break;
                }
            }
            if (found == -1)
                cout << "element not found" << endl;
            else
                cout << "element found at position " << found << endl;
        }
        else if (choice == 6)
        {
            cout << "rxit" << endl;
            break;
        }
        else
        {
            cout << "invalid choice" << endl;
        }
    }

    return 0;
}
