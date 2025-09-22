#include <iostream>
#include <string>
using namespace std;

string removeVowels(string s)
{
    string result = "";
    for (char c : s)
    {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    string str;
    cout << "enter a string: ";
    getline(cin, str);

    string noVowels = removeVowels(str);

    cout << "string after removing vowels: " << noVowels << endl;

    return 0;
}
