#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "enter number of strings: ";
    cin >> n;
    cin.ignore();

    string arr[30];
    cout << "enter the strings:";
    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i]);
    }

    sort(arr, arr + n);

    cout << "strings in alphabetical order: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
