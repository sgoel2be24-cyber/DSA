#include <iostream>
#include <stack>
#include <string>
using namespace std;

int balanced(string expr)
{
    stack<char> s;

    for (int i = 0; i < expr.length(); i++)
    {
        char character = expr[i];

        if (character == '(' || character == '{' || character == '[')
        {
            s.push(character);
        }
        else if (character == ')' || character == '}' || character == ']')
        {
            if (s.empty())
            {
                return false;
            }
            char top = s.top();
            s.pop();

            if ((character == '(' && top != ')') || (character == '{' && top != '}') || (character == '[' && top != ']'))
            {

                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    string expression;
    cout << "enter the expression : ";
    getline(cin, expression);
    if (balanced(expression))
    {
        cout << "it is balanced" << endl;
    }
    else
    {
        cout << "it isn't balanced" << endl;
    }
}