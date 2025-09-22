#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

bool isOperator(const string &c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

int evaluatePostfix(const string &expr)
{
    stack<int> st;
    stringstream ss(expr);
    string c;

    while (ss >> c)
    {
        if (isOperator(c))
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            int result = 0;
            if (c == "+")
                result = b + a;
            else if (c == "-")
                result = b - a;
            else if (c == "*")
                result = b * a;
            else if (c == "/")
                result = b / a;

            st.push(result);
        }
        else
        {
            st.push(stoi(c));
        }
    }

    return st.top();
}

int main()
{
    string expr;
    cout << "enter postfix expression: ";
    getline(cin, expr);

    int result = evaluatePostfix(expr);
    cout << "result: " << result << endl;

    return 0;
}
