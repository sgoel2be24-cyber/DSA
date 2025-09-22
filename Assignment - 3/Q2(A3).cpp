#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString(string str)
{
    stack<char> s;

    for (char c : str)
    {
        s.push(c);
    }
    string reversed;
    while (!s.empty())
    {
        reversed = reversed + s.top();
        s.pop();
    }
    return reversed;
}

int main()
{
    string str;
    cout << "enter the string : ";
    getline(cin, str);
    string reversed = reverseString(str);
    cout << "reversed string is : " << reversed;
    return 0;
}