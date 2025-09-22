#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "enter a character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
    }

    cout << "lowercase: " << ch << endl;

    return 0;
}
