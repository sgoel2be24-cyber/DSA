#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cout << "enter the string :";
    getline(cin, s);

    reverse(s.begin(), s.end());

    cout << "the reversed string is : " << s;
    return 0;
}