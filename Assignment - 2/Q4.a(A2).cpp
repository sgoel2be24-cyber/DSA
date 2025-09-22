#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cout << "enter the first string: ";
    getline(cin, s1);
    cout << "enter the second string: ";
    getline(cin, s2);

    string result = s1 + s2;

    cout << "concatenated string: " << result << endl;
    return 0;
}
